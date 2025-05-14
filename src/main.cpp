#include <iostream>

#include "frontend/lex.h"

using namespace frontend;

int main()
{
  std::wstring expression = L"LET k = ¬A ∧ B → C";
  auto lexd = lex::tokenize(expression);


  return 0;
}
