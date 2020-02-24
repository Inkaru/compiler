#include "environment.h"
#include "node.h"

Environment::Environment() {}

Environment::Environment(const Environment &env)
{
  vars = env.vars;
  funcs = env.funcs;
  arrays = env.arrays;
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

void Environment::declareFunc(string name, FunctionNode *func)
{
  cout << "declared func : " << name << endl;
  funcs.insert({name, func});
}

void Environment::declareArray(string name, vector<string>* vec){
  cout << "declared array : " << name << endl;
  arrays.insert({name, vec});
}

bool Environment::varIsDeclared(string var)
{
  return vars.find(var) != vars.end();
}

bool Environment::funcIsDeclared(string var)
{
  return funcs.find(var) != funcs.end();
}

bool Environment::arrayIsDeclared(string var)
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

FunctionNode *Environment::getFunc(string name)
{
  cout << "searching for : " << name;
  auto func = funcs.find(name);

  if (func != funcs.end())
  {
    cout << "found" << endl;
    return func->second;
  }

  cout << "func was undefined" << endl;
  return nullptr;
}

vector<string>* Environment::getArray(string name)
{
  cout << "searching for : " << name;
  auto arr = arrays.find(name);

  if (arr != arrays.end())
  {
    cout << "found" << endl;
    return arr->second;
  }

  cout << "array was undefined" << endl;
  return new vector<string>;
}

