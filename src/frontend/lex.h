//
// Created by Sutinder S. Saini on 5/13/2025.
//

#ifndef LEX_H
#define LEX_H
#include <string>
#include <vector>

namespace frontend
{

  enum token_t
  {
    LPAREN, RPAREN, LBRACKET, RBRACKET,

    /* p-logic toks */
    NOT, AND, OR, IMPLIES, IFF, END_OF_FILE, VAR, PROP_VAR,

    /* thorn specifics */
    LET, EQUAL, COMMENT
  };

  struct token
  {
    token_t type;
    std::wstring value;
    int pos;

    token(token_t ty, std::wstring value, int pos)
    {
      this->type = ty;
      this->value = value;
      this->pos = pos;
    }
  };

  class lex {
  public:
    lex();
    ~lex();

    static std::vector<token> tokenize(std::wstring expression);
    static bool verify_next_slot(int pos, std::wstring expression);
  };
}

#endif //LEX_H
