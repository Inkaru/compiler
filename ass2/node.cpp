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
    current = child->convertStmt(current);
  }

  return current;
}

string LastStatNode::getValue() { return value; }

BBlock *LastStatNode::convertStmt(BBlock *out)
{
  if (value == "RETURN")
  {
    string tmp = explist->get(0)->convertExpr(out);
    out->code.push_back("return " + tmp + ";");
  }
  else
  {
    out->code.push_back("return;");
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
  // string tmp = makeNames();
  // string i = exp->convertExpr(out);
  // out->code.push_back(tmp + "=" + name->getValue() + "[(int)" + i + "];");
  // return tmp;

  string i = exp->convertExpr(out);
  return name->getValue() + "[(int)" + i + "-1 ]";
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

  out->code.push_back(name + " = fmod(" + lhs + "," + rhs + ");");
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

  out->code.push_back(name + " = fmod" + lhs + " <= " + rhs + ";");
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
  int rhs = arrays.find(right->getValue())->second;

  string name = makeNames();

  out->code.push_back(name + " = " + to_string(rhs) + ";");
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
  return "true";
}

string FalseNode::getValue() { return to_string(value); }
string FalseNode::convertExpr(BBlock *out)
{
  return "false";
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

BBlock* FuncCallNode::convertStmt(BBlock *out)
{
  convertExpr(out);
  return out;
}

string FuncCallNode::convertExpr(BBlock *out)
{
  string rhs;
  string lhs = left->getValue();
  if (lhs == "io.read")
  {
    string name = makeNames();
    out->code.push_back("std::cin >> " + name + ";");
    return name;
  }
  if (lhs == "print" || lhs == "io.write")
  {
    bool returns = lhs == "print";
    Node *explist = right->get(0);

    lhs = "printf(\"";
    string lhs2 = "";

    if (dynamic_cast<StringNode *>(right) != nullptr)
    {
      out->code.push_back("printf(\"" + right->getValue() + "\");");
      return "";
    }

    for (auto i : explist->children)
    {
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
    string name = makeNames();
    rhs = right->convertExpr(out);
    out->code.push_back(name + " = " + lhs + "(" + rhs + ");");
    return name;
  }
  return "";
}

string AssignNode::getValue() { return "Assign"; }

BBlock *AssignNode::convertStmt(BBlock *out)
{

  vector<string> exprs;

  auto itVar = left->children.begin();
  auto itExp = right->children.begin();

  string var;
  string exp;

  while (itVar != left->children.end() && itExp != left->children.end())
  {
    TableConstructorNode *tab = dynamic_cast<TableConstructorNode *>(*itExp);
    if (tab != nullptr)
    {
      out->code.push_back(tab->construct((*itVar)->getValue()));
    }
    else if (dynamic_cast<TabNode *>(*itExp) != nullptr)
    {
      exp = (*itExp)->convertExpr(out);
      string tmp = makeNames();
      out->code.push_back(tmp + " = " + exp + ";");
      exprs.push_back(tmp);
    }
    else
    {
      exp = (*itExp)->convertExpr(out);
      exprs.push_back(exp);
    }

    itVar++;
    itExp++;
  }

  itVar = left->children.begin();
  itExp = right->children.begin();

  while (itVar != left->children.end() && itExp != left->children.end())
  {
    if (dynamic_cast<TableConstructorNode *>(*itExp) != nullptr)
    {
      //pass
    }
    else if (dynamic_cast<TabNode *>(*itVar) != nullptr)
    {
      string lhs = (*itVar)->convertExpr(out);
      string rhs = (*exprs.begin());
      exprs.erase(exprs.begin());
      out->code.push_back(lhs + " = " + rhs + ";");
    }
    else
    {
      string lhs = (*itVar)->convertExpr(out);
      string rhs = (*exprs.begin());
      exprs.erase(exprs.begin());

      out->code.push_back(lhs + " = " + rhs + ";");
    }

    itVar++;
    itExp++;
  }
  return out;
}

string ForNode::getValue() { return "FOR"; }

BBlock *ForNode::convertStmt(BBlock *out)
{

  string i = var->convertExpr(out);
  string val = exp1->convertExpr(out);
  string stop = exp2->convertExpr(out);

  BBlock *cond = new BBlock();
  cond->isFinal = false;
  out->tExit = cond;

  out->code.push_back(i + " = " + val + ";");
  out->code.push_back("goto " + cond->name + ";");
  out->isFinal = false;

  BBlock *exit = new BBlock();
  BBlock *loop = new BBlock();
  loop->isFinal = false;
  cond->tExit = loop;
  cond->fExit = exit;

  cond->code.push_back("if(" + i + "<=" + stop + ") \n\tgoto " + loop->name + ";\nelse \n\tgoto " + exit->name + ";");

  cout << "loop is " << loop->name << endl;
  loop = block->convertStmt(loop);
  cout << "loop is " << loop->name << endl;
  loop->code.push_back(i + "++;");
  loop->tExit = cond;
  loop->code.push_back("goto " + cond->name + ";");

  return exit;
}

string RepeatNode::getValue()
{
  return "REPEAT";
}

BBlock *RepeatNode::convertStmt(BBlock *out)
{
  BBlock *exit = new BBlock();
  BBlock *blo = new BBlock();

  out->tExit = blo;
  out->code.push_back("goto " + blo->name + ";");
  blo->isFinal = false;

  blo = block->convertStmt(blo);
  string cond = exp->convertExpr(blo);

  blo->code.push_back("if(" + cond + "!= 1)\n\tgoto " + out->tExit->name + ";\nelse\n\tgoto " + exit->name + ";");
  blo->tExit = out->tExit;
  blo->fExit = exit;

  return exit;
}

string IfNode::getValue() { return "IF"; }

BBlock *IfNode::convertStmt(BBlock *out)
{
  BBlock *exit = new BBlock();
  BBlock *blo = new BBlock();

  string i = condition->convertExpr(out);
  out->tExit = blo;
  out->fExit = exit;
  out->code.push_back("if(" + i + " != 0)\n\tgoto " + blo->name + ";\nelse\n\tgoto " + exit->name + ";");
  out->isFinal = false;
  blo->isFinal = false;

  blo = block->convertStmt(blo);
  blo->tExit = exit;
  blo->code.push_back("goto " + exit->name + ";");

  return exit;
}

string IfElseNode::getValue() { return "IF ELSE"; }

BBlock *IfElseNode::convertStmt(BBlock *out)
{
  BBlock *exit = new BBlock();
  BBlock *blo1 = new BBlock();
  BBlock *blo2 = new BBlock();

  string i = condition->convertExpr(out);
  out->tExit = blo1;
  out->fExit = blo2;
  out->code.push_back("if(" + i + " != 0)\n\tgoto " + blo1->name + ";\nelse\n\tgoto " + blo2->name + ";");
  out->isFinal = false;
  blo1->isFinal = false;
  blo2->isFinal = false;

  blo1 = block->convertStmt(blo1);
  blo1->tExit = exit;
  blo1->code.push_back("goto " + exit->name + ";");

  blo2 = block2->convertStmt(blo2);
  blo2->tExit = exit;
  blo2->code.push_back("goto " + exit->name + ";");

  return exit;
}

string FunctionNode::getValue() { return "Function"; }

BBlock *FunctionNode::convertStmt(BBlock *out)
{
  
  set<string> namesCpy = names;
  map<string, int> arraysCpy = arrays;

  names = {};
  arrays = {};

  BBlock* func = new BBlock();
  BBlock* end = block->convertStmt(func);

  string f = "double " + name + "(" ;
  if(block->getValue() == "parlist"){
    auto list = block->get(0)->children;
    for (auto ptr = list.begin(); ptr != list.end(); ptr++){
      f += "double " + (*ptr)->getValue();
      if(*ptr != list.back()){
        f += ", ";
      }
      names.erase((*ptr)->getValue());
    }
  }

  f += "){\n";
  func->name = f + func->name;
  f = "";

  for (auto n : names)
  {
    f += "double " + n + " = 0;\n";
  }

  func->code.push_front(f);
  end->code.push_back("exit(0);");
  end->code.push_back("}");
  end->isFinal = false;

  names = namesCpy;
  arrays = arraysCpy;

  funcs.insert({name, func});

  return out;
}

string TableConstructorNode::getValue()
{
  return value;
}

string TableConstructorNode::convertExpr(BBlock *out)
{
  return "";
}

string TableConstructorNode::construct(string name)
{
  vector<string> *tab = new vector<string>;

  for (auto child : get(0)->children)
  {
    tab->push_back(child->getValue());
  }

  string tabDecl;

  int size = tab->size();
  arrays.insert({name, size});

  tabDecl += "double " + name + "[" + to_string(size) + "] = {";
  for (int i = 0; i < size - 1; i++)
  {
    tabDecl += tab->at(i) + ",";
  }
  tabDecl += tab->at(size - 1);
  tabDecl += "};";

  return tabDecl;
}
