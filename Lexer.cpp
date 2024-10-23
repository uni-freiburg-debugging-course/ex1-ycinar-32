#include "Lexer.h"
#include <cctype> 
#include <iostream>

std::vector<Token> lineLexer(const std::string& expression) {
    std::vector<Token> tokens;
    std::string numberBuffer;

    for (size_t i = 0; i < expression.length(); ++i) {
        char ch = expression[i];

        if (std::isspace(ch)) {
            continue; 
        }

        if (ch == '(') {
            tokens.push_back(Token(TokenRole::LPar, "("));
        } 
        else if (ch == ')') {
            tokens.push_back(Token(TokenRole::RPar, ")"));
        } 
        else if (std::isdigit(ch)) {
            numberBuffer += ch; 
            if(!std::isdigit(expression[i+1])){
                if (!numberBuffer.empty()) {
                    tokens.push_back(Token(TokenRole::Number, numberBuffer));
                    numberBuffer.clear();
            }
            }
        } 
        else if (ch == '+' || ch == '-' || ch == '*') {
            if(!std::isdigit(expression[i+1])){
                tokens.push_back(Token(TokenRole::Operator, std::string(1, ch)));
            }
            else{
                numberBuffer += ch;
            }
            
        }
        else if(std::isalpha(ch)){
            if(size_t lastIndex = expression.find_last_of("simplify")){
                tokens.push_back(Token(TokenRole::Keyword, "simplify"));
                i = lastIndex;
            }
        }
    }

    if (!numberBuffer.empty()) {
        tokens.push_back(Token(TokenRole::Number, numberBuffer));
    }

    return tokens;
}
