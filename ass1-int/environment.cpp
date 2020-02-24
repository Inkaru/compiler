#include "environment.h"
#include "node.h"

Environment::Environment() {}

void Environment::declare(string var, string val)
{
  if (isDeclared(var))
  {
    vars.find(var)->second = val;
  }
  else
  {
    vars.insert({var, val});
  }
}

bool Environment::isDeclared(string var)
{
  return vars.find(var) != vars.end();
}

string Environment::get(string var)
{

  if (isDeclared(var))
  {
    return vars.find(var)->second;
  }

  auto func = funcs.find(var);

  if (func != funcs.end())
  {
    // copy func vars
    Node *block = func->second;
    string returnValue = block->execute(*this);

    //re-assigment

    return returnValue;
  }

  cout << "var was undefined" << endl;
  return "0";
}

void Environment::declareFunc(string name, Node *func)
{
  funcs.insert({name, func});
}
