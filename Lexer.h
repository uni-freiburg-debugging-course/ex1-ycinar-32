#ifndef LEXER_H
#define LEXER_H

#include <vector>
#include <string>
#include "Token.h"  

std::vector<Token> lineLexer(const std::string& expression);

#endif 
