string AssignNode::execute(Environment &env)
{
  cout << "Assign Node;";

  auto itVar = left->children.begin();
  auto itExp = right->children.begin();

  string var;
  string exp;

  while (itVar != left->children.end() && itExp != left->children.end())
  {
    TableConstructorNode *tab = dynamic_cast<TableConstructorNode *>(*itExp);
    if (tab != nullptr)
    {
      var = (*itVar)->getValue();
      vector<string> *arr = tab->construct(env);
      cout << "debug : " << var << "="
           << "tab" << endl;

      env.declareArray(var, arr);
    }
    else
    {
      if (dynamic_cast<TabNode *>(*itVar) != nullptr)
      {
        TabNode* tab = dynamic_cast<TabNode *>(*itVar);
        cout << "=== EXPR ===" << endl;
        exp = (*itExp)->execute(env);
        cout << "new value : " << exp << endl;

        Environment cpy1 = env;

        env.getArray(tab->name->getValue())->at(stoi(tab->exp->execute(cpy1))-1) = exp;
      }
      else
      {
        var = (*itVar)->getValue();
        exp = (*itExp)->execute(env);
        cout << "debug : " << var << "=" << exp << endl;

        env.declare(var, exp);
      }
    }

    itVar++;
    itExp++;
  }

  return "";
}

