//
// Created by Sutinder S. Saini on 5/13/2025.
//

#include "lex.h"

namespace frontend
{
  lex::lex()
  {
  }

  lex::~lex()
  {
  }

  bool lex::verify_next_slot(int pos, std::wstring expression)
  {
    int exp_len = expression.length();
    int updatedsz = pos + 1;

    if (exp_len < updatedsz)
    {
      return false;
    }

    return true;
  }

  std::vector<token> lex::tokenize(std::wstring expression)
  {
    std::vector<token> toks;
    int pos = 0;

    while (verify_next_slot(pos, expression))
    {
      wchar_t curr_tok = expression[pos];

      // Firstly check if we have a comment
      bool comment = false;
      if (verify_next_slot(pos, expression) && curr_tok == L'/')
      {
        pos++;

        if (expression[pos] == L'/')
        {
          comment = true;
        }
      }

      if (comment)
      {
        toks.push_back({COMMENT ,L"", pos});
        break;
      }

      std::wstring word = L"";
      std::wstring ident = L"";

      while (isalpha(expression[pos]) && verify_next_slot(pos,expression) && !isspace(expression[pos]))
      {
        word += expression[pos];
        pos++;
      }

      if (verify_next_slot(pos, expression) && word == L"LET")
      {
        pos++;

        while (isspace(expression[pos]) && verify_next_slot(pos, expression))
        {
          pos++;
        }

        while (verify_next_slot(pos, expression) && isalpha(expression[pos]))
        {
          ident += expression[pos];
          pos++;
        }

        toks.push_back({LET, ident, pos});
      }

      int wordlen = word.size();
      if (wordlen == 1)
      {
        // prop-var
        toks.push_back({PROP_VAR, word, pos});
      }

      switch (curr_tok)
      {
        case L'¬':
          toks.push_back({NOT, L"", pos});
          break;

        case L'∧':
          toks.push_back({AND,L"", pos});
          break;

        case L'∨':
          toks.push_back({OR, L"", pos});
          break;

        case L'→':
          toks.push_back({IMPLIES, L"", pos});
          break;

        case L'↔':
          toks.push_back({IFF,L"",pos});
          break;

        case L'=':
          toks.push_back({EQUAL, L"", pos});
          break;

        default: // un-lexable (for right now this might be a identifier or pred)
          break;
      }
      pos++;
    }
    return toks;
  }
}
