#include "node.h"
#include "environment.h"

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

void Node::interpreter()
{
  Environment env;
  (*this).execute(env);
}


string StdNode::getValue() { return value; }

string StdNode::execute(Environment &env)
{
  // cout << "stdnode;";

  string returnValue = "";
  for(auto child: children){
    if(dynamic_cast<LastStatNode*>(child) != nullptr){
      return child->execute(env);
    }
    returnValue += child->execute(env);
  }
  cout << "StdNode : " << returnValue << endl;
  return returnValue;
}


	string LastStatNode::getValue(){ return value;}

	string LastStatNode::execute(Environment &env){
  cout << "LastStat " << endl;
  if(value == "RETURN"){
    string returnValue = explist->execute(env);
    cout << "   return : " << returnValue << endl;
    return returnValue;
  }
  cout << "   break" << endl;
  return "";
}


string VarNode::getValue() { return value; }

string VarNode::execute(Environment &env)
{
  cout << "varnode;";
  return env.get(value);
}


string ExpNode::childEval(Environment &env, Node *node)
{
  if (dynamic_cast<VarNode *>(node) != nullptr)
  {
    return env.get(node->getValue());
  }

  if (dynamic_cast<ExpNode *>(node) != nullptr)
  {
    return node->execute(env);
  }

  if (dynamic_cast<FuncCallNode *>(node) != nullptr)
  {
    return node->execute(env);
  }
}


string ExpNodeImpl::getValue() { return "EXP"; }

string ExpNodeImpl::execute(Environment &env)
{
  cout << "expImplNode;";
  return "";
}


string PlusNode::getValue() { return "PLUS"; }

string PlusNode::execute(Environment &env)
{
  cout << "PLUS NODE " << endl;
  return to_string(stof(childEval(env, left)) + stof(childEval(env, right)));
}


string MinusNode::getValue() { return "MINUS"; }

string MinusNode::execute(Environment &env)
{
  return to_string(stof(childEval(env, left)) - stof(childEval(env, right)));
}


string MultNode::getValue() { return "MULT"; }

string MultNode::execute(Environment &env)
{
  return to_string(stof(childEval(env, left)) * stof(childEval(env, right)));
}


string DivNode::getValue() { return "DIV"; }

string DivNode::execute(Environment &env)
{
  return to_string(stof(childEval(env, left)) / stof(childEval(env, right)));
}


string ModNode::getValue() { return "MOD"; }

string ModNode::execute(Environment &env)
{
  float a = stof(childEval(env, left));
  float b = stof(childEval(env, right));
  return to_string(a - floor(a / b) * b);
}


string ExpoNode::getValue() { return "EXPO"; }

string ExpoNode::execute(Environment &env)
{
  return to_string(pow(stof(childEval(env, left)), stof(childEval(env, right))));
}


string DbEquNode::getValue() { return "EQU"; }

string DbEquNode::execute(Environment &env)
{
  if (stof(childEval(env, left)) == stof(childEval(env, right)))
    return "1";
  else
    return "0";
}


string InfNode::getValue(){return "INF";}

string InfNode::execute(Environment &env){
  if (stof(childEval(env, left)) < stof(childEval(env, right)))
    return "1";
  else
    return "0";
}


string NegNode::getValue() { return "NEG"; }

string NegNode::execute(Environment &env)
{
  return to_string(-stof(childEval(env, right)));
}


string IntNode::getValue() { return to_string(value); }

string IntNode::execute(Environment &env)
{
  return to_string(value);
}


string TrueNode::getValue() { return to_string(value); }

string TrueNode::execute(Environment &env)
{
  return to_string(value);
}


string FalseNode::getValue() { return to_string(value); }

string FalseNode::execute(Environment &env)
{
  return to_string(value);
}


string StringNode::getValue() { return value; }

string StringNode::execute(Environment &env) { return value; }


string ArgsNode::getValue() { return ""; }

string ArgsNode::execute(Environment &env) { return (*children.begin())->execute(env); }

Node *ArgsNode::get(int i)
{
  list<Node *>::iterator it = next(children.begin(), i);
  return (*it);
}


string ExpListNode::getValue() { return ""; }

string ExpListNode::execute(Environment &env) {
  string returnValue = "";
  for(auto child: children){
    cout << "debug Explist child : " << child->tag << " " << child->getValue() << endl;
    returnValue += child->execute(env);
  }
  cout << "ExplistNode : " << returnValue << endl;
  return returnValue;
}

Node *ExpListNode::get(int i)
{
  list<Node *>::iterator it = next(children.begin(), i);
  return (*it);
}


string VarListNode::getValue() { return ""; }

string VarListNode::execute(Environment &env) { return ""; }

Node *VarListNode::get(int i)
{
  list<Node *>::iterator it = next(children.begin(), i);
  return (*it);
}


string FuncCallNode::getValue() { return ""; }

string FuncCallNode::execute(Environment &env)
{

  if (env.funcIsDeclared(left->getValue())){
    FunctionNode* func = env.getFunc(left->getValue());
    Environment cpy = env;

    return func->executeFunc(env);
  }

  if (left->getValue() == "print" || left->getValue() == "io.write")
  {

    bool doesReturn = left->getValue() == "print";

    if (dynamic_cast<ArgsNode *>(right) != nullptr)
    {
      ArgsNode *args = dynamic_cast<ArgsNode *>(right);
      Node *res = args->get(0);

      if (dynamic_cast<ExpNode *>(res) != nullptr)
      {
        cout << "debug : exp" << endl;
        cout << res->execute(env);
      }

      if (dynamic_cast<StringNode *>(res) != nullptr)
      {
        cout << "debug : string" << endl;
        cout << res->getValue();
      }

      if (dynamic_cast<ExpListNode *>(res) != nullptr)
      {
        cout << "debug : explist" << endl;

        for (auto n : res->children)
        {
          cout << n->execute(env) << " ";
        }
      }

      if (doesReturn)
      {
        cout << endl;
      }
    }

    if (dynamic_cast<StringNode *>(right) != nullptr)
    {
      StringNode *str = dynamic_cast<StringNode *>(right);
      cout << "debug : string" << endl;
      cout << str->getValue() << endl;
    }
  }
  else if (left->getValue() == "io.read")
  {

    // ArgsNode* args = dynamic_cast<ArgsNode*>(right);
    // ExpListNode* explist = dynamic_cast<ExpListNode*>(args->get(0));
    // StringNode* str = dynamic_cast<StringNode*>(explist->get(0));

    string val;

    // cin.ignore();
    // cin.sync(); cin.get(); cin.clear();
    // getline(cin, val);

    // if (cin.fail ()){
    // 	cout << "error" << endl;
    // }

    // int iValid = 1;
    // while (iValid == 1)
    // {
    // 	if (cin.fail())
    // 	{
    // 					cin.ignore();
    // 					cout<<"Wrong! Enter a #!"<<endl;
    // 					cin>>val;
    // 	} //closes if
    // 	else
    // 					iValid = 0;
    // }

    return "1";
  }
  else
  {
    cout << "func not implemented yet" << endl;
  }

  return "";
}


string AssignNode::getValue() { return "Assign"; }

string AssignNode::execute(Environment &env)
{
  cout << "Assign Node;";

  auto itVar = left->children.begin();
  auto itExp = right->children.begin();

  string var;
  string exp;

  while (itVar != left->children.end() && itExp != left->children.end())
  {

    var = (*itVar)->getValue();
    exp = (*itExp)->execute(env);
    cout << "debug : " << var << "=" << exp << endl;

    env.declare(var, exp);

    itVar++;
    itExp++;
  }

  return "";
}


string ForNode::getValue() { return "FOR"; }

string ForNode::execute(Environment &env)
{
  cout << "For Node;";

  env.declare(var->getValue(), exp1->execute(env));

  string lim = exp2->execute(env);

  while (env.get(var->getValue()) != lim)
  {
    block->execute(env);
    env.declare(var->getValue(), to_string(1 + stoi(env.get(var->getValue()))));
  }
  block->execute(env);

  return "";
}


string IfNode::getValue() { return "IF"; }

string IfNode::execute(Environment &env)
{
  cout << "If Node;";

  if (condition->execute(env) != "0")
  {
    block->execute(env);
  }

  return "";
}


string IfElseNode::getValue() { return "IF ELSE"; }

string IfElseNode::execute(Environment &env)
{
  cout << "If Else Node " ;

  if (condition->execute(env) != "0")
  {
    cout << "true condition" << endl;
    return block->execute(env);
  }
  else
  {
    cout << "false condition" << endl;
    return block2->execute(env);
  }

  return "";
}


string FunctionNode::getValue() { return "Function"; }

string FunctionNode::execute(Environment &env)
{
  cout << "funtcion Node;";

  env.declareFunc(name, this);

  return "";
}

string FunctionNode::executeFunc(Environment& env){
  cout << "Function called : " << name << endl;

  return "";
}