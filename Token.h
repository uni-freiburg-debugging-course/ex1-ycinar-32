#ifndef TOKEN_H
#define TOKEN_H

#include <string>

enum TokenRole {
    LPar,
    RPar,
    Operator,
    Number,
    Keyword
};

class Token {
public:
    TokenRole role;
    std::string value;

    Token(TokenRole r, const std::string& val) : role(r), value(val) {}
};

#endif  // TOKEN_H
