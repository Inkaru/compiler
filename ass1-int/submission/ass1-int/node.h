#pragma once

#include <list>
#include <cstring>
#include <fstream>
#include <iostream>
#include <cmath>
#include <map>
#include <vector>

class Environment;

using namespace std;

class Node
{
public:
	std::string tag;
	int node_id;
	std::list<Node *> children;
	Node(std::string t, int i) : tag(t), node_id(i) {}
	Node();
	~Node();

	void dump(int depth = 0);
	void dumpRoot();
	void dumpDot(ofstream &file);

	virtual string getValue() = 0;
	virtual string execute(Environment &env) = 0;
	void interpreter();

	Node *get(int i);
};

class StdNode : public Node
{
public:
	string value;
	StdNode(string t, string v, int i) : Node(t, i), value(v) {}

	string getValue();

	string execute(Environment &env);
};

class LastStatNode : public Node
{
public:
	string value;
	Node *explist;
	LastStatNode(string t, string v, Node *explist, int i) : Node(t, i), value(v), explist(explist) {}

	string getValue();

	string execute(Environment &env);
};

class VarNode : public Node
{
public:
	string value;
	VarNode(string t, string v, int i) : Node(t, i), value(v) {}

	string getValue();

	string execute(Environment &env);
};

class TabNode : public Node
{
public:
	Node* name;
	Node* exp;
	TabNode(string t, Node* name, Node* exp, int i) : Node(t, i), name(name), exp(exp) {}

	string getValue();

	string execute(Environment &env);
};

class ExpNode : public Node
{
public:
	Node *left;
	Node *right;

	ExpNode(string t, Node *left, Node *right, int i) : Node(t, i), left(left), right(right) {}

	string childEval(Environment &env, Node *node);
};

class ExpNodeImpl : public ExpNode
{
public:
	ExpNodeImpl(string t, string v, int i) : ExpNode(t, nullptr, nullptr, i) {}

	string getValue();

	string execute(Environment &env);
};

class PlusNode : public ExpNode
{
public:
	PlusNode(string t, Node *left, Node *right, int i) : ExpNode(t, left, right, i) {}

	string getValue();

	string execute(Environment &env);
};

class MinusNode : public ExpNode
{
public:
	MinusNode(string t, Node *left, Node *right, int i) : ExpNode(t, left, right, i) {}

	string getValue();

	string execute(Environment &env);
};

class MultNode : public ExpNode
{
public:
	MultNode(string t, Node *left, Node *right, int i) : ExpNode(t, left, right, i) {}

	string getValue();

	string execute(Environment &env);
};

class DivNode : public ExpNode
{
public:
	DivNode(string t, Node *left, Node *right, int i) : ExpNode(t, left, right, i) {}

	string getValue();

	string execute(Environment &env);
};

class ModNode : public ExpNode
{
public:
	ModNode(string t, Node *left, Node *right, int i) : ExpNode(t, left, right, i) {}

	string getValue();

	string execute(Environment &env);
};

class ExpoNode : public ExpNode
{
public:
	ExpoNode(string t, Node *left, Node *right, int i) : ExpNode(t, left, right, i) {}

	string getValue();

	string execute(Environment &env);
};

class DbEquNode : public ExpNode
{
public:
	DbEquNode(string t, Node *left, Node *right, int i) : ExpNode(t, left, right, i) {}

	string getValue();

	string execute(Environment &env);
};

class InfNode : public ExpNode
{
public:
	InfNode(string t, Node *left, Node *right, int i) : ExpNode(t, left, right, i) {}

	string getValue();

	string execute(Environment &env);
};

class SupNode : public ExpNode
{
public:
	SupNode(string t, Node *left, Node *right, int i) : ExpNode(t, left, right, i) {}

	string getValue();

	string execute(Environment &env);
};

class NequNode : public ExpNode
{
public:
	NequNode(string t, Node *left, Node *right, int i) : ExpNode(t, left, right, i) {}

	string getValue();

	string execute(Environment &env);
};

class InfEquNode : public ExpNode
{
public:
	InfEquNode(string t, Node *left, Node *right, int i) : ExpNode(t, left, right, i) {}

	string getValue();

	string execute(Environment &env);
};

class SupEquNode : public ExpNode
{
public:
	SupEquNode(string t, Node *left, Node *right, int i) : ExpNode(t, left, right, i) {}

	string getValue();

	string execute(Environment &env);
};

class NegNode : public ExpNode
{
public:
	NegNode(string t, Node *right, int i) : ExpNode(t, nullptr, right, i) {}

	string getValue();

	string execute(Environment &env);
};

class HashNode : public ExpNode
{
public:
	HashNode(string t, Node *right, int i) : ExpNode(t, nullptr, right, i) {}

	string getValue();

	string execute(Environment &env);
};

class IntNode : public ExpNode
{
public:
	int value;
	IntNode(string t, string v, int i) : ExpNode(t, nullptr, nullptr, i), value(stoi(v)) {}

	string getValue();

	string execute(Environment &env);
};

class TrueNode : public ExpNode
{
public:
	int value = 1;
	TrueNode(int i) : ExpNode("TRUE", nullptr, nullptr, i) {}

	string getValue();

	string execute(Environment &env);
};

class FalseNode : public ExpNode
{
public:
	int value = 0;
	FalseNode(int i) : ExpNode("FALSE", nullptr, nullptr, i) {}

	string getValue();

	string execute(Environment &env);
};

class StringNode : public ExpNode
{
public:
	string value;
	StringNode(string t, string v, int i) : ExpNode(t, nullptr, nullptr, i), value(v) {}

	string getValue();

	string execute(Environment &env);
};

class ArgsNode : public Node
{
public:
	ArgsNode(string t, int i) : Node(t, i) {}

	string getValue();

	string execute(Environment &env);
};

class ExpListNode : public Node
{
public:
	ExpListNode(string t, int i) : Node(t, i) {}

	string getValue();

	string execute(Environment &env);
};

class VarListNode : public Node
{
public:
	VarListNode(string t, int i) : Node(t, i) {}

	string getValue();

	string execute(Environment &env);
};

class FuncCallNode : public Node
{
public:
	Node *left;
	Node *right;
	FuncCallNode(string t, Node *left, Node *right, int i) : Node(t, i), left(left), right(right) {}

	string getValue();

	string execute(Environment &env);
};

class AssignNode : public Node
{
public:
	Node *left;
	Node *right;

	AssignNode(string t, VarListNode *left, ExpListNode *right, int i) : Node(t, i), left(left), right(right) {}

	string getValue();

	string execute(Environment &env);
};

class ForNode : public Node
{
public:
	Node *var;
	Node *exp1;
	Node *exp2;
	Node *block;

	ForNode(string t, Node *v, Node *e1, Node *e2, Node *blo, int i) : Node(t, i), var(v), exp1(e1), exp2(e2), block(blo) {}

	string getValue();

	string execute(Environment &env);
};

class RepeatNode : public Node
{
public:
	
	Node *block;
	Node* exp;

	RepeatNode(string t, Node *blo, Node *e, int i) : Node(t, i), block(blo), exp(e) {}

	string getValue();

	string execute(Environment &env);
};

class IfNode : public Node
{
public:
	Node *condition;
	Node *block;

	IfNode(string t, Node *c, Node *blo, int i) : Node(t, i), condition(c), block(blo) {}

	string getValue();

	string execute(Environment &env);
};

class IfElseNode : public Node
{
public:
	Node *condition;
	Node *block;
	Node *block2;

	IfElseNode(string t, Node *c, Node *blo, Node *blo2, int i) : Node(t, i), condition(c), block(blo), block2(blo2) {}

	string getValue();

	string execute(Environment &env);
};

class FunctionNode : public Node
{
public:
	string name;
	Node *block;

	FunctionNode(string t, string name, Node *block, int i) : Node(t, i), name(name), block(block) {}

	string getValue();

	string execute(Environment &env);

	string executeFunc(Environment &env);
};

class TableConstructorNode : public Node
{
public:
	Node *fieldlist;
	string value;

	TableConstructorNode(string t, string v ,Node* list, int i) : Node(t, i), value(v), fieldlist(list) {}

	string getValue();

	string execute(Environment &env);

	vector<string>* construct(Environment &env);
};