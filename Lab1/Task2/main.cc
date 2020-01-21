#include<iostream>
#include "binary.tab.hh"

void yy::parser::error(std::string const&err)
{
  std::cout << "It's one of the bad ones... " << err << std::endl;
}

int main(int argc, char **argv)
{
yy::parser parser;
  if(!parser.parse()){}
  return 0;
}