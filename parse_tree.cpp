#include <iostream>
#include <vector>
#include<map>
#include<sstream>

#include "parse_tree.h"
using namespace std;

#define mp make_pair
vector< map<string,int> > semanticIDTable;
map<string,int> table2;
map<pair<string,int >, string> idToType;
map<pair<string,int >, string> fnRetType;
map<pair<string,int >, vector<string> > fnParamsTypes;
pair<string,int> lastFnDef;
map<pair<string,int >, bool> idToIsUsed;

map<string, string> descToRet;
map<string, int> descToRetNum;
map<string, string> descToParam;
pair <string,int> lastFnCall;

int findID(string id, int depth){
    for(int i=depth;i>=0;i--){
        if (semanticIDTable.size()>i&&semanticIDTable[i].find(id)!=semanticIDTable[i].end()){
			idToIsUsed[mp(id,semanticIDTable[i].find(id)->second)]=true;
            return semanticIDTable[i].find(id)->second;
        }
    }
    return -1;
}

int setID(string id, int depth, string type){
    int num=1;
    if(table2.find(id)==table2.end()){
        table2[id]=1;
    }
    else {
        table2.find(id)->second++;
        num=table2.find(id)->second;
    }
    while(semanticIDTable.size()<=depth){
        map<string,int> m;
        semanticIDTable.push_back(m);
    }
    if(semanticIDTable[depth].find(id)!=semanticIDTable[depth].end()){
        cerr<<"error: Multiple declarations with same identifier \""<<id<<"\""<<endl;
		return -1;
    }
    semanticIDTable[depth].insert(mp(id,num));
	idToType.insert(mp(mp(id,num), type));
	if(type=="fn"){
		lastFnDef=mp(id,num);
		vector<string> vec;
		fnParamsTypes[lastFnDef]=vec;
	}
	idToIsUsed.insert(mp(mp(id,num), false));
	return num;
}

bool castsInto(string a,string b){
	if(a==b)
		return true;
	if(a=="int"&&b=="double")
		return true;
	if(a=="double"&&b=="int")
		return true;
	
	return false;
}

string getValFromNode(BaseNode * typeNode){
	ValNode<string> *vn = dynamic_cast<ValNode<string>* > ( typeNode);
	string str;// = dynamic_cast<string*> (&val);
        /*stringstream ss;
        ss << vn.getVal();
        ss>> str;*/
	return vn->getVal();
}

void BaseNode::addNode(BaseNode * newNode) {
    children.push_back(newNode);
}

int BaseNode::getNodesCount() {
    return children.size();
}

int BaseNode::getLine() {
    return line;
}

string BaseNode::getDescription() {
    return description;
}

BaseNode::BaseNode(int line, string description) {
    this -> description = description;
    this -> line = line;
    this -> hasError = false;
}

vector<BaseNode*>::iterator BaseNode::getFirstChild() {
    return children.begin();
}

BaseNode* BaseNode::getChild(int idx){
	return children[idx];
}

vector<BaseNode*>::iterator BaseNode::getEnd() {
    return children.end();
}

void BaseNode::printNode(int indent) {
    string sp(indent, ' ');
    cout<< sp << this -> getDescription() << '\n';
    for (vector<BaseNode*>::iterator it = this -> getFirstChild(); it != getEnd(); it++)
        if(*it != NULL)
            (*it) -> printNode(indent + 1);
}

void BaseNode::setErrorTrue(){
	hasError=true;
}

string BaseNode::printSemantic(int indent, int depth, string declType, BaseNode* root) {
    string sp(indent, ' ');
    cout<< sp << this -> getDescription()<<" line: "/*<<line*/<<endl;//" depth:"<<depth<< '\n';

    string desc=this -> getDescription();
	string retStr="none";
    int i=0;
    if(depth+1<semanticIDTable.size()){
        semanticIDTable[depth+1].clear();
    }
	if(!("fun_decl"==desc||"decl"==desc||"param"==desc||"call"==desc||"argument_list"==desc||"return_value"==desc
	||"assignment_expr"==desc||"rel_expr"==desc))
    for (vector<BaseNode*>::iterator it = this -> getFirstChild(); it != getEnd(); it++)
        if(*it != NULL&&(i!=0||!("term"==desc||"sum_expr"==desc))){
            //cout<<"depth? "<<i<<" "<<desc<<" "<<(i>1&&"fun_decl"==desc)<<endl;
			int addDepth=((i>=1&&"fun_decl"==desc)||"compound_stmt"==desc||"if"==desc||"if_else"==desc||"for"==desc||"while"==desc||"do_while"==desc);
			//(*it) -> printSemantic(indent + 1,depth+addDepth,(i==0&&("fun_decl"==desc||"var_decl"==desc||"param"==desc)));
			string rstr= (*it) -> printSemantic(indent + 1,depth+addDepth,"none", root);
			if(descToParam.find(desc)!=descToParam.end()){
				if(!castsInto(rstr, descToParam[desc])){
					cerr<<"error on line "<<line<<": can't cast \""<<rstr<<"\" into \""<<descToParam[desc]<<"\""<<endl;
					root->setErrorTrue();
				}
			}
			if(descToRetNum.find(desc)!=descToRetNum.end()&&(i==descToRetNum[desc]||(i==children.size()-1&&descToRetNum[desc]==-1))){
				retStr=rstr;
			}
            i++;
        }
	if("fun_decl"==desc){
		//TODO
		children[0] -> printSemantic(indent + 1,depth,"fn", root);
		children[1] -> printSemantic(indent + 1,depth+1,"none", root);
		if(this->children.size()==3){ //if fn is void
			fnRetType[lastFnDef]="void";
			children[2] -> printSemantic(indent + 1,depth+1,"none", root);
		}
		else {
			fnRetType[lastFnDef]=getValFromNode(children[2]);
			children[3] -> printSemantic(indent + 1,depth+1,"none", root);
			children[4] -> printSemantic(indent + 1,depth+1,"none", root);
		}
	}
	if("return_value"==desc){
		string rstr = children[0] -> printSemantic(indent + 1,depth,"none", root);
		if(!castsInto(rstr, fnRetType[lastFnDef])){
			cerr<<"error on line "<<line<<": In function \""<<lastFnDef.first<<"\" returned type does not match (expected \""
					<<fnRetType[lastFnDef]<<"\", but got \""<<rstr<<"\")"<<endl;
			root->setErrorTrue();
		}
	}
	if("decl"==desc){
		children[0] -> printSemantic(indent + 1,depth,getValFromNode(children[1]), root);
		if(children.size()==3) {
			string rstr = children[2] -> printSemantic(indent + 1,depth,"none", root);
			if(!castsInto(rstr, getValFromNode(children[1]))){
				cerr<<"error on line "<<line<<": can't cast \""<<rstr<<"\" into \""<<getValFromNode(children[1])<<"\""<<endl;
				root->setErrorTrue();
			}
		}
	}
	if("assignment_expr"==desc){
		if(children.size()==3) { //assignment=
			string dstr = children[0] -> printSemantic(indent + 1,depth,"none", root);
			if(getValFromNode(children[1]) != "=" && !castsInto(dstr, "double")){
				cerr<<"error on line "<<line<<": can't use operator \""<<getValFromNode(children[1])<<"\" for \""<<dstr<<"\""<<endl;
				root->setErrorTrue();
			}
			string rstr = children[2] -> printSemantic(indent + 1,depth,"none", root);
			if(!castsInto(rstr, dstr)){
				cerr<<"error on line "<<line<<": can't cast \""<<rstr<<"\" into \""<<dstr<<"\""<<endl;
				root->setErrorTrue(); 
			}
		}
		else { //postfix++
			string dstr = children[0] -> printSemantic(indent + 1,depth,"none", root);
			if(!castsInto(dstr, "double")){
				cerr<<"error on line "<<line<<": can't use operator \""<<getValFromNode(children[1])<<"\" for \""<<dstr<<"\""<<endl; 
				root->setErrorTrue();
			}
		}
	}
	if("term"==desc||"sum_expr"==desc){
		retStr = children[0] -> printSemantic(indent + 1,depth,"none", root);
		if(children.size()>1&&!castsInto(retStr,"double")){
			cerr<<"error on line "<<line<<": can't cast \""<<retStr<<"\" into "<<"\"double\""<<endl; 
			root->setErrorTrue();
		}
		
	}
	if("rel_expr"==desc){
		string strA = children[0] -> printSemantic(indent + 1,depth,"none", root);
		string strB = children[2] -> printSemantic(indent + 1,depth,"none", root);
		string op = getValFromNode(children[1]);
		if(!castsInto(strA,strB)){
			cerr<<"error on line "<<line<<": can't compare \""<<strA<<"\" and \""<<strB<<"\""<<endl; 
			root->setErrorTrue();
		}
		if(strA=="bool"&&!(op=="eq"||op=="ne")){
			cerr<<"error on line "<<line<<": invalid operator for type \"boolean\""<<endl; 
			root->setErrorTrue();
		}
		
	}
	if("param"==desc){
		fnParamsTypes[lastFnDef].push_back(getValFromNode(children[1]));
		retStr = children[0] -> printSemantic(indent + 1,depth,getValFromNode(children[1]), root);
	}
	if("call"==desc){
		retStr = children[0] -> printSemantic(indent + 1,depth,"none", root);
		if(retStr=="notDeclared") return retStr;
		lastFnCall = mp(getValFromNode(children[0]), findID(getValFromNode(children[0]),depth));
		children[1] -> printSemantic(indent + 1,depth,"none", root);
	}
	if("argument_list"==desc){
		if(children.size()!=fnParamsTypes[lastFnCall].size()) {
			cerr<<"error on line "<<line<<": function \""<<lastFnCall.first<<"\" with "<<fnParamsTypes[lastFnCall].size()
				<<" parameters is called with "<<children.size()<<" arguments"<<endl;
			root->setErrorTrue();
			return "none";
		}
		for(int i=0;i<children.size();i++){
			string rstr = children[i] -> printSemantic(indent + 1,depth,"none", root);
			if(!castsInto(rstr,fnParamsTypes[lastFnCall][i])){
				cerr<<"error on line "<<line<<": In call to function \""<<lastFnCall.first<<"\" argument #"<<i+1<<" has wrong type (got \""
					<<rstr<<"\" instead of \""<<fnParamsTypes[lastFnCall][i]<<"\")"<<endl;
				root->setErrorTrue();
			}
		}
	}
	
	if("decl_list"==desc){
		int mid=findID("main", 0);
		for(map<pair<string,int >, bool>::iterator it = idToIsUsed.begin(); it != idToIsUsed.end(); it++) {
			string id=it->first.first;
			if(it->second==false&&id!="turtle_forward"&&id!="turtle_left"&&id!="turtle_right"&&id!="turtle_move_to"&&
						id!="print_number"&&id!="print_bool"&&id!="print_string"&&id!="set_pen_color"&&
						id!="set_pen_line_width"&&id!="turn_pen_on"&&id!="turn_pen_off"){
				cerr<<"warning: Identifier \""<<it->first.first<<"\" was declared, but never used"<<endl;
				//root->setErrorTrue();
			}
		}
		if(mid==-1||idToType[mp("main",mid)]!="fn"){
			cerr<<"error on line "<<line<<": main function is not defined"<<endl;
			root->setErrorTrue();
			return "error";
		}
		if(fnRetType[mp("main",mid)]!="void"){
			cerr<<"error on line "<<line<<": main function needs to be void"<<endl;
			root->setErrorTrue();
			return "error";
		}
		if(fnParamsTypes[mp("main",mid)].size()!=0){
			cerr<<"error on line "<<line<<": main function should have no parameters"<<endl;
			root->setErrorTrue();
		}		
		if(hasError){
			retStr="error";
		}
	}
	if(descToRet.find(desc)!=descToRet.end()){
		return descToRet[desc];
	}
	//cout<<desc<<" returns "<<retStr<<endl;
	return retStr;
}

template<class T>
string ValNode<T>::printSemantic(int indent, int depth, string declType, BaseNode* root) {
    string sp(indent,' ');
    cout << sp << this->getDescription() << " : "  << val;
    string desc=this -> getDescription();
    if("IDENTIFIER"==desc){
        string str;// = dynamic_cast<string*> (&val);
        stringstream ss;
        ss << val;
        ss>> str;
		int idNum;
        if(declType!="none"){
            idNum=setID(str,depth, declType);
			if(idNum==-1){
				root->setErrorTrue();
				return "doubleDeclared";
			}
        }
		else {
			idNum=findID(str,depth);
			if(idNum==-1){
				cerr<<"error on line " << getLine() << ": Identifier \""+str+"\" was used before it was declared"<<endl;
				root->setErrorTrue();
				return "notDeclared";
			}
		}
        cout<<" #"<<idNum;
		cout<<" type: "<<idToType[mp(str,idNum)];
		if(idToType[mp(str,idNum)]=="fn") {
			cout<<" "<<fnRetType[mp(str,idNum)]<<endl;
			return fnRetType[mp(str,idNum)];
		}
		cout<<endl;
		return idToType[mp(str,idNum)];
    }
    cout<<endl;
	
	if (desc=="int"||desc=="double"||desc=="string"||desc=="bool"){
		return desc;
	}
	if (desc=="type_spec"){
		stringstream ss;
		string str;
        ss << val;
        ss>> str;
		return str;
	}
	if(descToRet.find(desc)!=descToRet.end()){
		return descToRet[desc];
	}
	return "none";
}

void BaseNode::initSemantic() {
    setID("turtle_forward",0,"fn");
	fnParamsTypes[lastFnDef].push_back("double");
    setID("turtle_left",0,"fn");
	fnParamsTypes[lastFnDef].push_back("double");
    setID("turtle_right",0,"fn");
	fnParamsTypes[lastFnDef].push_back("double");
	setID("turtle_move_to",0,"fn");
	fnParamsTypes[lastFnDef].push_back("double");
	fnParamsTypes[lastFnDef].push_back("double");
	setID("print_number",0,"fn");
	fnParamsTypes[lastFnDef].push_back("double");
	fnParamsTypes[lastFnDef].push_back("int");
	setID("print_bool",0,"fn");
	fnParamsTypes[lastFnDef].push_back("bool");
	setID("print_string",0,"fn");
	fnParamsTypes[lastFnDef].push_back("string");
	setID("set_pen_color",0,"fn");
	fnParamsTypes[lastFnDef].push_back("double");
	fnParamsTypes[lastFnDef].push_back("double");
	fnParamsTypes[lastFnDef].push_back("double");
	setID("set_pen_line_width",0,"fn");
	fnParamsTypes[lastFnDef].push_back("double");
    setID("turn_pen_on",0,"fn");
    setID("turn_pen_off",0,"fn");
	
	descToRet["or_expr"]="bool";
	descToParam["or_expr"]="bool";
	descToRet["and_expr"]="bool";
	descToParam["and_expr"]="bool";
	descToRet["not_expr"]="bool";
	descToParam["not_expr"]="bool";
	descToRet["rel_expr"]="bool";
	
	//descToRet["sum_expr"]="double";
	descToParam["sum_expr"]="double"; //except first
	descToRet["sum_with"]="double";
	descToParam["sum_with"]="double";
	descToRet["sum_op"]="double";
	//descToRet["term"]="double";
	descToParam["term"]="double"; //except first
	descToRet["mul_with"]="double";
	descToParam["mul_with"]="double";
	descToRet["mul_op"]="double";
	
	descToRetNum["cast_expr"]=0;
	descToRetNum["unary_expr"]=-1;
	descToRetNum["array_access"]=0;
	descToRetNum["call"]=0;
	
	
}

template<class T>
T ValNode<T>::getVal() {
    return val;
}

template<class T>
ValNode<T>::ValNode(string description, T val) : BaseNode(-1,description) {
    this -> val = val;
}
template<class T>
ValNode<T>::ValNode(std::string description, T val, int line_no) : BaseNode(line_no, description) {
    this -> val = val;
}



template<class T>
void ValNode<T>::printNode(int indent) {
    string sp(indent,' ');
    cout << sp << this->getDescription() << " : "  << val << '\n';
}

/*template<class T>
UnaryValNode<T>::UnaryValNode(string description,T val, BaseNode* operant) : ValNode<T>(description, val) {
    this->addNode(operant);
}

template<class T>
BinaryValNode<T>::BinaryValNode(string description, T val, BaseNode* firstOperant, BaseNode* secondOperant) : ValNode<T>(description, val) {
    this -> addNode(firstOperant);
    this -> addNode(secondOperant);
}*/

UnaryNode::UnaryNode(int line, string description, BaseNode* operant) : BaseNode(line, description) {
    this->addNode(operant);
}

BinaryNode::BinaryNode(int line, string description, BaseNode* firstOperant, BaseNode* secondOperant) : BaseNode(line, description) {
    this -> addNode(firstOperant);
    this -> addNode(secondOperant);
}

TernaryNode::TernaryNode(int line, string description, BaseNode* firstOperant, BaseNode* secondOperant,
                         BaseNode* thirdOperant) : BaseNode(line, description) {
    this -> addNode(firstOperant);
    this -> addNode(secondOperant);
    this -> addNode(thirdOperant);
}

QuaternaryNode::QuaternaryNode(int line, string description, BaseNode* firstOperant, BaseNode* secondOperant,
                               BaseNode* thirdOperant, BaseNode* forthOperant) : BaseNode(line, description) {
    this -> addNode(firstOperant);
    this -> addNode(secondOperant);
    this -> addNode(thirdOperant);
    this -> addNode(forthOperant);
}

ListNode::ListNode(int line, string description) : BaseNode(line, description) {
}

void ListNode::addNodeToList(BaseNode* newNode) {
    this->addNode(newNode);
}

void BaseNode::generateCode(/*int indent*/) {
    /*string sp(indent, ' ');*/
    //cerr<< this -> getDescription() << " " << this->children.size() << '\n';
	string desc = this -> getDescription();
		
	
	if (desc == "argument_list"){ //DONE	
		if (this -> children.size() > 0 && (this -> getChild(0)) != NULL){
			(this -> getChild(0)) -> generateCode ();
			for (int i=1; i < this -> children.size(); i++){
				cout << " ";
				this -> children[i] -> generateCode();
			}
		}
		cout << "\n";
		return;
	} 
	
	if (desc == "call"){ //DONE	
		(this -> getChild(1)) -> generateCode();
		(this -> getChild(0)) -> generateCode ();
		
		return;
	} 
		
	if (desc == "statement_call"){ //DONE
		(this -> getChild(0)) -> generateCode ();
		cout << "\npop\n";
		return;
	}

	if (desc == "unary_expr"){ //DONE
		for (int i=0; i < this -> children.size(); i++){
			cout << " ";
			this -> children[i] -> generateCode();
		}
		return;
	} 
	
	
	if (desc == "sum_expr"){ //DONE
		(this -> getChild(0)) -> generateCode ();
		for (int i=1; i < this -> children.size(); i++){			
			cout << " ";
			this -> children[i] -> getChild(1) -> generateCode();
			cout << " ";
			this -> children[i] -> getChild(0) -> generateCode();
			cout << " ";
		}
		return;
	} 
	
	if (desc == "term"){ //DONE
		(this -> getChild(0)) -> generateCode ();
		for (int i=1; i < this -> children.size(); i++){			
			cout << " ";
			this -> children[i] -> getChild(1) -> generateCode();
			cout << " ";
			this -> children[i] -> getChild(0) -> generateCode();
			cout << " ";
		}
		return;
	} 
	
	if (desc == "not"){  //DONE
		
		(this -> getChild(0)) -> generateCode ();
		cout <<" not";
		return;
	} 
	
	if (desc == "rel_expr"){ //DONE
		(this -> getChild(0)) -> generateCode ();
		cout << " ";
		(this -> getChild(2)) -> generateCode ();
		cout << " ";
		(this -> getChild(1)) -> generateCode ();
		cout << " ";
		return;
	} 

	if (desc == "or_expr"){	//DONE
		(this -> getChild(0)) -> generateCode ();
		for (int i=1; i < this -> children.size(); i++){			
			this -> children[i] -> generateCode();
			cout << " or ";
		}
		return;
	} 
	
	if (desc == "and_expr"){ //DONE
		(this -> getChild(0)) -> generateCode ();
		for (int i=1; i < this -> children.size(); i++){
			this -> children[i] -> generateCode();
			cout << " and ";
			
		}
		return;
	} 
	
	if (desc == "assignment_expr"){  //DONE
		if (this -> children.size() == 2){
			if (getValFromNode(children[1]) == "++"){
				cout << "/";
				(this -> getChild(0)) -> generateCode ();
				cout << " ";
				(this -> getChild(0)) -> generateCode ();
				cout << " 1 add def\n";
			}
			if (getValFromNode(children[1]) == "--"){
				cout << "/";
				(this -> getChild(0)) -> generateCode ();
				cout << " ";
				(this -> getChild(0)) -> generateCode ();
				cout << " 1 sub def\n";
			}
		} else {
			if (getValFromNode(children[1]) == "=") {
				cout << "/";
				(this -> getChild(0)) -> generateCode ();
				cout << " ";
				(this -> getChild(2)) -> generateCode ();
				cout << " def\n";
			}
			if (getValFromNode(children[1]) == "+=") {
				cout << "/";
				(this -> getChild(0)) -> generateCode ();
				cout << " ";
				(this -> getChild(0)) -> generateCode ();
				cout << " ";
				(this -> getChild(2)) -> generateCode ();
				cout << " add def\n";
			}
			if (getValFromNode(children[1]) == "-=") {
				cout << "/";
				(this -> getChild(0)) -> generateCode ();
				cout << " ";
				(this -> getChild(0)) -> generateCode ();
				cout << " ";
				(this -> getChild(2)) -> generateCode ();
				cout << " sub def\n";
			}
			if (getValFromNode(children[1]) == "*=") {
				cout << "/";
				(this -> getChild(0)) -> generateCode ();
				cout << " ";
				(this -> getChild(0)) -> generateCode ();
				cout << " ";
				(this -> getChild(2)) -> generateCode ();
				cout << " mul def\n";
			}
			if (getValFromNode(children[1]) == "/=") {
				cout << "/";
				(this -> getChild(0)) -> generateCode ();
				cout << " ";
				(this -> getChild(0)) -> generateCode ();
				cout << " ";
				(this -> getChild(2)) -> generateCode ();
				cout << " div def\n";
			}
			if (getValFromNode(children[1]) == "%=") {
				cout << "/";
				(this -> getChild(0)) -> generateCode ();
				cout << " ";
				(this -> getChild(0)) -> generateCode ();
				cout << " ";
				(this -> getChild(2)) -> generateCode ();
				cout << " mod def\n";
			}
		}
		return;
	} 
	
	if (desc == "for"){ //DONE
		(this -> getChild(0)) -> generateCode();
		cout << "\n{\n"; 
		(this -> getChild(1)) -> generateCode();
		cout << " not {exit} if\n";
		(this -> getChild(this ->children.size()-1)) -> generateCode();
		if (this -> children.size() > 3){
			(this -> getChild(2)) -> generateCode();
		}
		cout << "\n} loop\n";
		return;
	}
	
	if (desc == "while"){ //DONE
		cout << "{\n"; 
		(this -> getChild(0)) -> generateCode();
		cout << " not {exit} if\n";
		(this -> getChild(1)) -> generateCode();
		cout << "\n} loop\n";
		return;
	} 
	
	if (desc == "if"){ //DONE
		(this -> getChild(0)) -> generateCode();
		cout << "{";
		(this -> getChild(1)) -> generateCode();
		cout << "} if ";
		return;
	} 
	
	if (desc == "if_else"){ //DONE
		(this -> getChild(0)) -> generateCode();
		cout << "{ ";
		(this -> getChild(1)) -> generateCode();
		cout << " } {";
		(this -> getChild(2)) -> generateCode();
		cout << "} ifelse";
		return;
	} 
	
	if (desc == "expression_stmt"){  //DONE
		if (this -> children.size() > 0)
			(this -> getChild(0)) -> generateCode();
		cout << "\n";
		return;
	} 
	
	if (desc == "statement_list"){  //DONE
		cout << "\n";
		
		for (int i=0; i < this -> children.size(); i++){			
			this -> children[i] -> generateCode();
			cout << "\n";
		}
		cout << "\n";
		return;
	} 
	
	if (desc == "param_list"){ //DONE
		if (this -> children.size() > 0){
			cout << this -> children.size() << " dict begin\n";
			for (int i=this -> children.size() - 1; i >=0 ; i--){
				cout << "/";
				this -> children[i] -> generateCode();
				cout << " exch def\n";
			}
		}
		return;
	} 
	
	if (desc == "param"){ //DONE
		(this -> getChild(0)) -> generateCode ();
		return;
	}
	
	if (desc == "fun_decl"){  //DONE
		cout << "/";
		(this -> getChild(0)) -> generateCode ();
		cout << " {\n";
		(this -> getChild(1)) -> generateCode();		
		if (this -> children.size() == 5){
			(this -> getChild(3)) -> generateCode ();
			cout << "\n";
			(this -> getChild(4)) -> generateCode();
			cout << "\n";
		} else {
			(this -> getChild(2)) -> generateCode ();
			cout << "\n0\n";
		}
		if ((this -> getChild(1)) -> children.size() > 0 )
			cout << "end\n";
		cout << "} def\n";	
		return;
	} 
	
	if (desc == "return_value" ) {
		(this -> getChild(0)) -> generateCode ();
		return;
	}
	
	if (desc == "decl"){ //DONE
		cout << "/";
		(this -> getChild(0)) -> generateCode ();
		cout << " ";
		if (this -> children.size() > 2){
			(this -> getChild(2)) -> generateCode ();
		} else {
			if (getValFromNode(children[1]) == "int" || getValFromNode(children[1]) == "double"){
				cout << "0";
			}
			if (getValFromNode(children[1]) == "bool") {
				cout << "false";
			}
			if (getValFromNode(children[1]) == "string"){
				cout << "()";
			}
		}
		cout << " def\n";
		return;
	} 
	
	if (desc == "decl_list"){  //DONE
		for (int i=0; i < this -> children.size(); i++){			
			this -> children[i] -> generateCode();
			cout << "\n";
		}
		return;
	}
	
	cout << desc << " is not implemented!\n";
	
    /*for (vector<BaseNode*>::iterator it = this -> getChild(0); it != getEnd(); it++)
        if(*it != NULL)
            (*it) -> generateCode(indent + 1);*/
}

template<class T>
void ValNode<T>::generateCode() {
    string desc = this->getDescription();
	//cerr << desc;
	if (desc == "string"){
		cout << "(" << this -> getVal() << ")";
		return;			
	} 
	
	if (desc == "type"){
		cout << "/";
		return;
	}
	
	if (desc == "bool"){
		string value;// = dynamic_cast<string*> (&val);
        stringstream ss;
        ss << val;
        ss>> value;
		if (value == "0")
			cout << "false";
		else
			cout << "true";
		return;
	}
	
	/* int, real, IDENTIFIER, bool, unary_op, sum_op, mul_op, rel_op, assignment_op, postfix_op */
	cout << this -> getVal();
}

// DON'T DELETE!!!!
// Function needed so templates are correctly compiled from header
int templateFix() {
    ValNode<int>  t("int", 5);
    ValNode<int>  t1("int", 5, 2);
    ValNode<double>  d("double", 5.3);
    ValNode<double>  d1("double", 5.3, 2);
    ValNode<string>  i0("IDENTIFIER", "ABV");
    ValNode<string>  i1("IDENTIFIER", "ABV");
    ValNode<string>  i2("IDENTIFIER", "ABV");
    ValNode<string>  i3("IDENTIFIER", "ABV");
    ValNode<string>  i4("IDENTIFIER", "ABV");
    ValNode<string>  i5("IDENTIFIER", "ABV");
    ValNode<string>  i6("IDENTIFIER", "ABV", 2);
    ValNode<string>  ifu("IDENTIFIER", "myFunction");
    ValNode<string>  t3("op", "?");
}

/*
int main(){

    //simple test
    ValNode<int>  t("int", 5);
    ValNode<string>  i0("IDENTIFIER", "ABV");
    ValNode<string>  i1("IDENTIFIER", "ABV");
    ValNode<string>  i2("IDENTIFIER", "ABV");
    ValNode<string>  i3("IDENTIFIER", "ABV");
    ValNode<string>  i4("IDENTIFIER", "ABV");
    ValNode<string>  i5("IDENTIFIER", "ABV");
    ValNode<string>  ifu("IDENTIFIER", "myFunction");

    ValNode<string>  t3("op", "?");
    
    ListNode t6("int");
    BinaryNode t4("var_decl", &i0, &t6);
    BinaryNode tp2("param_decl", &i2, &t6);
    UnaryNode tp("params", &tp2);
    BinaryNode ts1("statement", &i3,&i4);
    BinaryNode ts2("var_decl", &i5,&t6);
    BinaryNode ts("statements", &ts1, &ts2);
    TernaryNode tf("fun_decl", &ifu, &tp, &ts);

    ListNode t5("statements");
    t5.addNodeToList(&t4);
    t5.addNodeToList(&i1);
    t5.addNodeToList(&tf);
    t5.addNodeToList(new BinaryNode("TESTPLUS", new ValNode<int>("int", 4), new ValNode<double>("double",0.3)));
    t5.printNode(0);
    t5.printSemantic(0,0,false);
    
    return 0;
}
*/

