/* 
   DV1465 / DV1505 / DV1511 Lab-task example code.
   (C) Dr Andrew Moss, Erik Bergenholtz  2016, 2017, 2018
   This code is released into the public domain.

   You are free to use this code as a base for your second assignment after
   the lab sessions (it is not required that you do so). 

   2018: Took out the double-pointers.
*/

#include <list>
#include <set>
#include <initializer_list>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

set<string> names;

/************* Three Address Instructions *************/
class ThreeAd
{
public:
	string name, lhs, rhs;
	char op;

	ThreeAd(string name, char op, string lhs, string rhs) : name(name), op(op), lhs(lhs), rhs(rhs)
	{
	}

	void dump(ofstream &file)
	{
		cout << name << " := ";
		cout << lhs << " " << op << " " << rhs << endl;
		file << name << ":=" << lhs << " " << op << " " << rhs << '\n';
	}
};

class BBlock
{
private:
	static int nCounter;

public:
	list<ThreeAd> instructions;
	list<string> code;
	BBlock *tExit, *fExit;
	string name;
	bool isFinal;

	BBlock() : tExit(NULL), fExit(NULL), name("blk" + to_string(nCounter++)), isFinal(true)
	{
	}

	void dump(ofstream &file)
	{

		file << name << ":" << endl;

		for (string i : code)
		{
			file << i << endl << endl;
		}

		file << endl;

		if(isFinal){
			file << "exit(0);\n\n";
		}
	}
};
int BBlock::nCounter = 0;

/******************** Expressions ********************/
class Expression
{
protected:
	static int nCounter;

public:
	string name;

	Expression() : name("")
	{
	}
	virtual string makeNames()
	{
		// Lecture 8 / slide 3-onwards.
		// Psuedo-code is illustrated on slide 5.
		// Virtual (but not pure) to allow overriding in the leaves.
		string n = "t_" + to_string(nCounter++);
		names.insert(n);
		return n;
	}

	virtual string asm_input(){
		return "["+ name +"] \"g\"(" + name + ")";
	}

	virtual string value(){
		return "true";
	}

	virtual string convert(BBlock *) = 0; // Lecture 8 / slide 12.
	virtual void dump(int depth) = 0;
};
int Expression::nCounter = 0;

class Add : public Expression
{
public:
	Expression *lhs, *rhs;

	Add(Expression *lhs, Expression *rhs) : lhs(lhs), rhs(rhs)
	{
	}

	string convert(BBlock *out)
	{
		// Write three address instructions into the block
		name = makeNames();
		string left = lhs->convert(out);
		string right = rhs->convert(out);

		out->instructions.push_back(ThreeAd(name, '+', left, right));

		string assembly = "  asm(\n\
      \"  movq %[" + left + "], %%rax\\n\\t\"\n\
      \"  movq %[" + right + "], %%rbx\\n\\t\"\n\
      \"  addq %%rbx, %%rax\\n\\t\"\n\
      \"  movq %%rax, %[" + name + "]\\n\\t\"\n\
      : [" + name + "] \"=g\"(" + name + ")\n\
      : " + lhs->asm_input() + ",\n\
			" + rhs->asm_input() + "\n\
      : \"rax\", \"rbx\", \"cc\");"
		;

		out->code.push_back(assembly);

		return name;
	}

	void dump(int depth)
	{
		for (int i = 0; i < depth; i++)
			cout << "  ";
		cout << "+" << endl;
		lhs->dump(depth + 1);
		rhs->dump(depth + 1);
	}
};

class Mult : public Expression
{
public:
	Expression *lhs, *rhs;

	Mult(Expression *lhs, Expression *rhs) : lhs(lhs), rhs(rhs)
	{
	}

	string convert(BBlock *out)
	{
		// Write three address instructions into the block
		name = makeNames();
		string left = lhs->convert(out);
		string right = rhs->convert(out);
		out->instructions.push_back(ThreeAd(name, '*', left, right));

		string assembly = "  asm(\n\
      \"  movq %[" + left + "], %%rax\\n\\t\"\n\
      \"  movq %[" + right + "], %%rbx\\n\\t\"\n\
      \"  mulq %%rbx\\n\\t\"\n\
      \"  movq %%rax, %[" + name + "]\\n\\t\"\n\
      : [" + name + "] \"=g\"(" + name + ")\n\
      : " + lhs->asm_input() + ",\n\
			" + rhs->asm_input() + "\n\
      : \"rax\", \"rbx\", \"rdx\", \"cc\");"
		;

		out->code.push_back(assembly);

		return name;
	}

	void dump(int depth)
	{
		for (int i = 0; i < depth; i++)
			cout << "  ";
		cout << "*" << endl;
		lhs->dump(depth + 1);
		rhs->dump(depth + 1);
	}
};

class Equality : public Expression
{
public:
	Expression *lhs, *rhs;

	Equality(Expression *lhs, Expression *rhs) : lhs(lhs), rhs(rhs)
	{
	}

	string convert(BBlock *out)
	{
		// Write three address instructions into the block
		name = makeNames();
		string left = lhs->convert(out);
		string right = rhs->convert(out);
		out->instructions.push_back(ThreeAd(name, '=', left, right));

		string assembly = "if ("+ left + " == " + rhs->value() +")\n";
		out->code.push_back(assembly);

		return name;
	}

	void dump(int depth)
	{
		for (int i = 0; i < depth; i++)
			cout << "  ";
		cout << "==" << endl;
		lhs->dump(depth + 1);
		rhs->dump(depth + 1);
	}
};

class Constant : public Expression
{
public:
	int val;

	Constant(int val) : val(val)
	{
	}

	string convert(BBlock *out)
	{
		// Write three address instructions into the block
		name = makeNames();
		return name;
	}

	void dump(int depth)
	{
		for (int i = 0; i < depth; i++)
			cout << "  ";
		cout << val << endl;
	}

	string makeNames()
	{
		// Lecture 8 / slide 3-onwards.
		// Psuedo-code is illustrated on slide 5.
		// Virtual (but not pure) to allow overriding in the leaves.
		return "const" + to_string(val);
	}

	string asm_input(){
		return "["+ name +"] \"g\"(" + to_string(val) + ")";
	}

	string value(){
		return to_string(val);
	}
};

class Variable : public Expression
{
public:

	Variable(string var_name)
	{
		name = var_name;
	}

	string convert(BBlock *out)
	{
		// Write three address instructions into the block
		names.insert(name);
		return name;
	}

	void dump(int depth)
	{
		for (int i = 0; i < depth; i++)
			cout << "  ";
		cout << name << endl;
	}

};

/******************** Statements ********************/
class Statement
{
public:
	string name;

	Statement()
	{
	}
	virtual BBlock *convert(BBlock *) = 0;
	virtual void dump(int depth) = 0;
};

class Assignment : public Statement
{
public:
	Variable *lhs;
	Expression *rhs;

	Assignment(string lhs, Expression *rhs) : lhs(new Variable(lhs)), rhs(rhs)
	{
	}

	BBlock *convert(BBlock *out)
	{
		// Write three address instructions into the block
		string left = lhs->convert(out);
		string right = rhs->convert(out);
		out->instructions.push_back(ThreeAd(left, 'c', right, right));

		string assembly = "  asm(\n\
      \"  movq %[" + right + "], %%rax\\n\\t\"\n\
      \"  movq %[" + right + "], %%rbx\\n\\t\"\n\
      \"  movq %%rax, %[" + left + "]\\n\\t\"\n\
      : [" + left + "] \"=g\"(" + left + ")\n\
      : " + rhs->asm_input() + "\n\
      : \"rax\", \"rbx\", \"cc\");"
		;

		out->code.push_back(assembly);

		return out;
	}

	void dump(int depth)
	{
		for (int i = 0; i < depth; i++)
			cout << "  ";
		cout << "Statement(A)" << endl;
		lhs->dump(depth + 1);
		rhs->dump(depth + 1);
	}
};

class Seq : public Statement
{
public:
	list<Statement *> stats;

	Seq(initializer_list<Statement *> arg)
	{
		for (auto i : arg)
		{
			stats.push_back(i);
		}
	}

	BBlock *convert(BBlock *out)
	{
		// Write three address instructions into the block
		BBlock *current = out;

		for (auto child : stats)
		{
			current = child->convert(current);
		}

		return out;
	}

	void dump(int depth)
	{
		cout << "";
		for (int i = 0; i < depth; i++)
			cout << "  ";

		cout << "Statement(S)" << endl;
		for (auto child : stats)
		{
			child->dump(depth + 1);
		}
	}
};

class If : public Statement
{
public:
	Expression *cond;
	Statement *true_block;
	Statement *false_block;

	If(Expression *exp, Statement *true_block, Statement *false_block) : cond(exp), true_block(true_block), false_block(false_block)
	{
	}

	BBlock *convert(BBlock *out)
	{
		// Write three address instructions into the block
		cond->convert(out);

		BBlock *exit = new BBlock();

		out->tExit = new BBlock();
		BBlock* tExitBlock = true_block->convert(out->tExit);
		tExitBlock->tExit = exit;

		out->fExit = new BBlock();
		BBlock* fExitBlock = false_block->convert(out->fExit);
		fExitBlock->tExit = exit;

		string assembly = "goto " + out->tExit->name + ";\n else \n goto " + out->fExit->name + ";\n";
		out->code.push_back(assembly);

		tExitBlock->code.push_back("goto " + exit->name + ";\n");
		fExitBlock->code.push_back("goto " + exit->name + ";\n");

		out->isFinal = false;
		tExitBlock->isFinal = false;
		fExitBlock->isFinal = false;

		return exit;
	}

	void dump(int depth)
	{
		for (int i = 0; i < depth; i++)
			cout << "  ";
		cout << "Statement(I)" << endl;
		cond->dump(depth + 1);
		true_block->dump(depth + 1);
		false_block->dump(depth + 1);
	}
};

/* Test cases */

// Statement *test = new Seq({new Assignment(
// 															 "x",
// 															 new Add(
// 																	 new Variable("x"),
// 																	 new Constant(1))),
// 													 new If(
// 															 new Equality(
// 																	 new Variable("x"),
// 																	 new Constant(10)),
// 															 new Assignment(
// 																	 "y",
// 																	 new Add(
// 																			 new Variable("x"),
// 																			 new Constant(1))),
// 															 new Assignment(
// 																	 "y",
// 																	 new Mult(
// 																			 new Variable("x"),
// 																			 new Constant(2)))),
// 													 new Assignment(
// 															 "x",
// 															 new Add(
// 																	 new Variable("x"),
// 																	 new Constant(1)))});

Statement *test = new Seq({new Assignment(
															 "x",
															 new Add(
																	 new Variable("x"),
																	 new Constant(1))),
													 new Assignment(
															 "y",
															 new Add(
																	 new Variable("y"),
																	 new Constant(1))),
													 new If(
															 new Equality(
																	 new Variable("x"),
																	 new Constant(0)),
															 new If(
																	 new Equality(
																			 new Variable("y"),
																			 new Constant(0)),
																	 new Assignment(
																			 "x",
																			 new Constant(1)),
																	 new Assignment(
																			 "y",
																			 new Constant(2))),
															 new Assignment(
																	 "y",
																	 new Constant(3)))});

/*
 * Iterate over each basic block that can be reached from the entry point
 * exactly once, so that we can dump out the entire graph.
 * This is a concrete example of the graph-walk described in lecture 7.
 */
void dumpCFG(BBlock *start)
{
	ofstream Source("source.cc");
	Source << "#include <iostream>" << endl << endl;
	Source << "int main() {" << endl << endl;

	for(auto n: names){
		Source << "long " << n << " = 0;\n";
	}

	Source << endl;

	list<BBlock *> done, todo;
	todo.push_back(start);
	while (todo.size() > 0)
	{
		// Pop an arbitrary element from todo set
		auto first = todo.begin();
		BBlock *next = *first;
		todo.erase(first);
		next->dump(Source);
		done.push_back(next);
		if (next->tExit != NULL && find(done.begin(), done.end(), next->tExit) == done.end() && find(todo.begin(), todo.end(), next->tExit) == todo.end())
			todo.push_back(next->tExit);
		if (next->fExit != NULL && find(done.begin(), done.end(), next->fExit) == done.end() && find(todo.begin(), todo.end(), next->fExit) == todo.end())
			todo.push_back(next->fExit);
	}

	Source << "}" << endl;
	Source.close();
}

int main()
{
	test->dump(0);
	BBlock *start = new BBlock();
	start = test->convert(start);
	dumpCFG(start);
	return 0;
}
