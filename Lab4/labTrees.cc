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

using namespace std;

/************* Three Address Instructions *************/
class ThreeAd
{
public:
	string name, lhs, rhs;
	char op;

	ThreeAd(string name, char op, string lhs, string rhs) : name(name), op(op), lhs(lhs), rhs(rhs)
	{
	}

	void dump(ofstream& file)
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
	BBlock *tExit, *fExit;
	string name;

	BBlock() : tExit(NULL), fExit(NULL), name("blk" + to_string(nCounter++))
	{
	}

	void dump(ofstream &file)
	{
		cout << "BBlock @ " << this << endl;
		cout << name << endl;
		file << "BB" << this << " [label=\"" << name + '\n' ;
		for (auto i : instructions)
		{
			i.dump(file);
		}
		file << "\"];" << '\n';
		cout << "True:  " << tExit << endl;
		cout << "False: " << fExit << endl;

		if (tExit != NULL)
		{
			file << "BB"<< this << " -> " << "BB"<< tExit << '\n';
		}
		if (fExit != NULL)
		{
			file << "BB"<< this << " -> " << "BB"<< fExit << '\n';
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
		return "t_" + to_string(nCounter++);
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
		out->instructions.push_back(ThreeAd(name, '+', lhs->convert(out), rhs->convert(out)));
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
		out->instructions.push_back(ThreeAd(name, '*', lhs->convert(out), rhs->convert(out)));
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
		out->instructions.push_back(ThreeAd(name, '=', lhs->convert(out), rhs->convert(out)));
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
	int value;

	Constant(int val) : value(val)
	{
	}

	string convert(BBlock *out)
	{
		// Write three address instructions into the block
		return to_string(value);
	}

	void dump(int depth)
	{
		for (int i = 0; i < depth; i++)
			cout << "  ";
		cout << value << endl;
	}
};

class Variable : public Expression
{
public:
	string var_name;

	Variable(string name) : var_name(name)
	{
	}

	string convert(BBlock *out)
	{
		// Write three address instructions into the block
		return var_name;
	}

	void dump(int depth)
	{
		for (int i = 0; i < depth; i++)
			cout << "  ";
		cout << var_name << endl;
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
		true_block->convert(out->tExit)->tExit = exit;;
		// out->tExit->tExit = exit;

		out->fExit = new BBlock();
		false_block->convert(out->fExit)->tExit = exit;
		// out->fExit->tExit = exit;

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
	ofstream MyFile("source.md");
	MyFile << "```graphviz" << std::endl;
	MyFile << "digraph {" << std::endl;
	MyFile << "node [shape=box];" << endl;

	set<BBlock *> done, todo;
	todo.insert(start);
	while (todo.size() > 0)
	{
		// Pop an arbitrary element from todo set
		auto first = todo.begin();
		BBlock *next = *first;
		todo.erase(first);
		next->dump(MyFile);
		done.insert(next);
		if (next->tExit != NULL && done.find(next->tExit) == done.end())
			todo.insert(next->tExit);
		if (next->fExit != NULL && done.find(next->fExit) == done.end())
			todo.insert(next->fExit);
	}

	MyFile << "}" << endl;
	MyFile << "```";
	MyFile.close();
}

int main()
{
	test->dump(0);
	BBlock *start = new BBlock();
	start = test->convert(start);
	dumpCFG(start);
	return 0;
}
