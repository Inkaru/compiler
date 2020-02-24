#include "environment.h"
#include "node.h"

Environment::Environment() {}

Environment::Environment(const Environment &env){
  vars = env.vars;
  funcs = env.funcs;
}

void Environment::declare(string var, string val)
{
  if (varIsDeclared(var))
  {
    cout << "update " << var << " to : " << val << endl;
    vars.find(var)->second = val;
  }
  else
  {
    cout << "created " << var << " to : " << val << endl;
    vars.insert({var, val});
  }
}

bool Environment::varIsDeclared(string var)
{
  return vars.find(var) != vars.end();
}

bool Environment::funcIsDeclared(string var)
{
  return funcs.find(var) != funcs.end();
}

string Environment::get(string var)
{

  if (varIsDeclared(var))
  {
    return vars.find(var)->second;
  }

  cout << "var was undefined" << endl;
  return "0";
}

FunctionNode* Environment::getFunc(string name){
  cout << "searching for : " << name ;
  auto func = funcs.find(name);

  if (func != funcs.end())
  {
    cout << "found" << endl;
    return func->second;
  }

  cout << "func was undefined" << endl;
  return nullptr;
}

void Environment::declareFunc(string name, FunctionNode *func)
{
  cout << "declared func : " << name << endl;
  funcs.insert({name, func});
}
