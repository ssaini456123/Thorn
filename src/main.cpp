#include <iostream>

#include "file.h"
#include "frontend/lex.h"

using namespace frontend;

int main()
{
  std::wstring expression = L"let k = ¬A ∧ //B → C";
  auto lexd = lex::tokenize(expression);

  return 0;
}
