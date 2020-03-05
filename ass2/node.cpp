#include "node.h"
#include "translate.h"

Node::Node()
{
  tag = "uninitialised";
} // Bison needs this.

Node::~Node()
{
  for (auto n : children)
    delete n;
}

void Node::dump(int depth)
{
  for (int i = 0; i < depth; i++)
    std::cout << "  ";
  std::cout << tag << std::endl;
  for (auto i : children)
    i->dump();
}

void Node::dumpRoot()
{
  ofstream MyFile("source.md");
  MyFile << "```graphviz" << std::endl;
  MyFile << "digraph {" << std::endl;
  dumpDot(MyFile);
  MyFile << "}" << endl;
  MyFile << "```";
  MyFile.close();
}

void Node::dumpDot(ofstream &file)
{
  file << node_id << " [label=\"" << tag << ": " << getValue() << "\"];" << '\n';
  for (auto i : children)
    file << node_id << " -> " << (*i).node_id << '\n';
  for (auto i : children)
    i->dumpDot(file);
}

Node *Node::get(int i)
{
  auto it = next(children.begin(), i);
  return (*it);
}

int Node::nCounter = 0;

string Node::makeNames()
{
  string n = "t_" + to_string(nCounter++);
  names.insert(n);
  return n;
}

BBlock *Node::convertStmt(BBlock *out)
{
  return out;
}

string Node::convertExpr(BBlock *out)
{
  return "";
}

string StdNode::getValue() { return value; }

BBlock *StdNode::convertStmt(BBlock *out)
{

  BBlock *current = out;

  for (auto child : children)
  {
    child->convertStmt(current);
  }

  return out;
}

string LastStatNode::getValue() { return value; }

BBlock *LastStatNode::convertStmt(BBlock *out)
{
  if (value == "RETURN")
  {
    out->code.push_back("return " + explist->get(0)->getValue());
  }
  else
  {
    out->code.push_back("return");
  }
  return out;
}

string VarNode::getValue() { return value; }

string VarNode::convertExpr(BBlock *out)
{
  names.insert(value);
  return value;
}

string TabNode::getValue()
{
  return (name->getValue() + "[ ]");
}

string TabNode::convertExpr(BBlock *out)
{
  out->code.push_back(name->getValue() + "[" + exp->getValue() + "]");
  return "tmp";
}

string ExpNodeImpl::getValue() { return "EXP"; }

string ExpNodeImpl::convertExpr(BBlock *out)
{
  out->code.push_back("exp : " + getValue());
  return "out";
}

string PlusNode::getValue() { return "PLUS"; }
string PlusNode::convertExpr(BBlock *out)
{
  string lhs = left->convertExpr(out);
  string rhs = right->convertExpr(out);

  string name = makeNames();

  out->code.push_back(name + " = " + lhs + " + " + rhs + ";");
  return name;
}

string MinusNode::getValue() { return "MINUS"; }
string MinusNode::convertExpr(BBlock *out)
{
  string lhs = left->convertExpr(out);
  string rhs = right->convertExpr(out);

  string name = makeNames();

  out->code.push_back(name + " = " + lhs + " - " + rhs + ";");
  return name;
}

string MultNode::getValue() { return "MULT"; }
string MultNode::convertExpr(BBlock *out)
{
  string lhs = left->convertExpr(out);
  string rhs = right->convertExpr(out);

  string name = makeNames();

  out->code.push_back(name + " = " + lhs + " * " + rhs + ";");
  return name;
}

string DivNode::getValue() { return "DIV"; }
string DivNode::convertExpr(BBlock *out)
{
  string lhs = left->convertExpr(out);
  string rhs = right->convertExpr(out);

  string name = makeNames();

  out->code.push_back(name + " = " + lhs + " / " + rhs + ";");
  return name;
}

string ModNode::getValue() { return "MOD"; }
string ModNode::convertExpr(BBlock *out)
{
  string lhs = left->convertExpr(out);
  string rhs = right->convertExpr(out);

  string name = makeNames();

  out->code.push_back(name + " = " + lhs + " % " + rhs + ";");
  return name;
}

string ExpoNode::getValue() { return "EXPO"; }
string ExpoNode::convertExpr(BBlock *out)
{
  string lhs = left->convertExpr(out);
  string rhs = right->convertExpr(out);

  string name = makeNames();

  out->code.push_back(name + " = pow(" + lhs + "," + rhs + ");");
  return name;
}

string DbEquNode::getValue() { return "EQU"; }
string DbEquNode::convertExpr(BBlock *out)
{
  string lhs = left->convertExpr(out);
  string rhs = right->convertExpr(out);

  string name = makeNames();

  out->code.push_back(name + " = " + lhs + " == " + rhs + ";");
  return name;
}

string InfNode::getValue() { return "INF"; }
string InfNode::convertExpr(BBlock *out)
{
  string lhs = left->convertExpr(out);
  string rhs = right->convertExpr(out);

  string name = makeNames();

  out->code.push_back(name + " = " + lhs + " < " + rhs + ";");
  return name;
}

string SupNode::getValue()
{
  return "SUP";
}
string SupNode::convertExpr(BBlock *out)
{
  string lhs = left->convertExpr(out);
  string rhs = right->convertExpr(out);

  string name = makeNames();

  out->code.push_back(name + " = " + lhs + " > " + rhs + ";");
  return name;
}

string NequNode::getValue()
{
  return "NEQU";
}
string NequNode::convertExpr(BBlock *out)
{
  string lhs = left->convertExpr(out);
  string rhs = right->convertExpr(out);

  string name = makeNames();

  out->code.push_back(name + " = " + lhs + " != " + rhs + ";");
  return name;
}

string InfEquNode::getValue()
{
  return "INFEQU";
}
string InfEquNode::convertExpr(BBlock *out)
{
  string lhs = left->convertExpr(out);
  string rhs = right->convertExpr(out);

  string name = makeNames();

  out->code.push_back(name + " = " + lhs + " <= " + rhs + ";");
  return name;
}

string SupEquNode::getValue()
{
  return "SUPEQU";
}
string SupEquNode::convertExpr(BBlock *out)
{
  string lhs = left->convertExpr(out);
  string rhs = right->convertExpr(out);

  string name = makeNames();

  out->code.push_back(name + " = " + lhs + " >= " + rhs + ";");
  return name;
}

string NegNode::getValue()
{
  return "NEG";
}
string NegNode::convertExpr(BBlock *out)
{
  string rhs = right->convertExpr(out);

  string name = makeNames();

  out->code.push_back(name + " = -" + rhs + ";");
  return name;
}

string HashNode::getValue()
{
  return "HASH";
}
string HashNode::convertExpr(BBlock *out)
{
  string rhs = right->convertExpr(out);

  string name = makeNames();

  out->code.push_back(name + " = #" + rhs);
  return name;
}

string IntNode::getValue() { return to_string(value); }
string IntNode::convertExpr(BBlock *out)
{
  string name = makeNames();

  // out->code.push_back("+ name + " = " + to_string(value) + ";");

  return to_string(value) + ".0";
}

string IntNode::makeNames()
{
  return "const" + to_string(value);
}

string TrueNode::getValue() { return to_string(value); }
string TrueNode::convertExpr(BBlock *out)
{
  out->code.push_back("exp : " + getValue());
  return "out";
}

string FalseNode::getValue() { return to_string(value); }
string FalseNode::convertExpr(BBlock *out)
{
  out->code.push_back("exp : " + getValue());
  return "out";
}

string StringNode::getValue() { return value; }
string StringNode::convertExpr(BBlock *out)
{
  return value;
}

string ArgsNode::getValue() { return ""; }

string ArgsNode::convertExpr(BBlock *out)
{
  return get(0)->convertExpr(out);
}

string ExpListNode::getValue() { return ""; }

string ExpListNode::convertExpr(BBlock *out)
{
  string res;
  for (auto i : children)
  {
    res += i->convertExpr(out);
    res += " ";
  }
  return res;
}

string VarListNode::getValue() { return ""; }

string VarListNode::convertExpr(BBlock *out)
{
  string res;
  for (auto i : children)
  {
    res += i->convertExpr(out);
    res += " ";
  }
  return res;
}

string FuncCallNode::getValue() { return ""; }

BBlock *FuncCallNode::convertStmt(BBlock *out)
{
  string rhs;
  string lhs = left->getValue();
  if (lhs == "print" || lhs == "io.write")
  {
    bool returns = lhs == "print";
    Node *explist = right->get(0);

    lhs = "printf(\"";
    string lhs2 = "";

    if (dynamic_cast<StringNode *>(right) != nullptr)
    {
      out->code.push_back("printf(\"" + right->getValue() + "\");");
      return out;
    }

    for (auto i : explist->children)
    {
      cout << i->getValue() << endl;
      if (dynamic_cast<StringNode *>(i) != nullptr)
      {
        lhs += i->getValue() + " ";
      }
      else
      {
        lhs += "%f ";
        lhs2 += ", " + i->convertExpr(out);
      }
    }

    if (returns)
    {
      lhs += "\\n";
    }

    lhs += "\"";

    lhs2 += ");";

    lhs += lhs2;

    out->code.push_back(lhs);
  }
  else
  {
    rhs = right->convertExpr(out);
    out->code.push_back(lhs + "(" + rhs + ");");
  }
  return out;
}

string AssignNode::getValue() { return "Assign"; }

BBlock *AssignNode::convertStmt(BBlock *out)
{
  string lhs = left->convertExpr(out);
  string rhs = right->convertExpr(out);

  out->code.push_back(lhs + " = " + rhs + ";");

  return out;
}

string ForNode::getValue() { return "FOR"; }

BBlock *ForNode::convertStmt(BBlock *out)
{
  return out;
}

string RepeatNode::getValue()
{
  return "REPEAT";
}

BBlock *RepeatNode::convertStmt(BBlock *out)
{
  return out;
}

string IfNode::getValue() { return "IF"; }

BBlock *IfNode::convertStmt(BBlock *out)
{
  return out;
}

string IfElseNode::getValue() { return "IF ELSE"; }

BBlock *IfElseNode::convertStmt(BBlock *out)
{
  return out;
}

string FunctionNode::getValue() { return "Function"; }

BBlock *FunctionNode::convertStmt(BBlock *out)
{
  return out;
}

string TableConstructorNode::getValue()
{
  return value;
}

string TableConstructorNode::convertExpr(BBlock *out)
{
  return "out";
}
