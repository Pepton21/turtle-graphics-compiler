#ifndef PARSE_TREE
#define PARSE_TREE

#include <iostream>
#include <vector>
#include<string>

class BaseNode{
     std::string description;
     std::vector<BaseNode*> children;
	 int line;
	 bool hasError;
public:
     void addNode(BaseNode * newNode);
     int getNodesCount();
     int getLine();
     std::string getDescription();
     BaseNode(int line, std::string description);
     std::vector<BaseNode*>::iterator getFirstChild();
     BaseNode* getChild(int idx);
     std::vector<BaseNode*>::iterator getEnd();
     virtual void printNode(int indent);
     virtual std::string printSemantic(int indent, int depth, std::string declType, BaseNode* root);
     void initSemantic();
	 void setErrorTrue();
	 virtual void generateCode();
};

template <class T>
class ValNode: public BaseNode{
     T val;
public:
     T getVal();
     ValNode(std::string description, T val);
     ValNode(std::string description, T val, int line_no);
     void printNode(int indent);
     std::string printSemantic(int indent, int depth, std::string declType, BaseNode* root);
	 void generateCode();
};

/*template <class T>
class UnaryValNode: public ValNode<T>{
public:
    UnaryValNode(std::string description,T val, BaseNode* operant);
};

template <class T>
class BinaryValNode: public ValNode<T>{
public:
    BinaryValNode(std::string description,T val, BaseNode* firstOperant, BaseNode* secondOperant);
};*/

class UnaryNode: public BaseNode{
public:
    UnaryNode(int line, std::string description, BaseNode* operant);
};

class BinaryNode: public BaseNode{
public:
    BinaryNode(int line, std::string description, BaseNode* firstOperant, BaseNode* secondOperant);
};

class TernaryNode: public BaseNode{
public:
    TernaryNode(int line, std::string description, BaseNode* firstOperant, BaseNode* secondOperant,
                BaseNode* thirdOperant);
};

class QuaternaryNode: public BaseNode{
public:
        QuaternaryNode(int line, std::string description, BaseNode* firstOperant, BaseNode* secondOperant,
                   BaseNode* thirdOperant, BaseNode* forthOperant);
};

class ListNode: public BaseNode{
public:
    ListNode(int line, std::string description);
    void addNodeToList(BaseNode* newNode);
};

#endif // PARSE_TREE
