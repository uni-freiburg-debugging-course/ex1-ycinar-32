#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <string>
#include "Token.h"

class Operation{
public:
    Operation();
    Operation(std::vector<long long> numbers, std::string arithmeticOperation) : m_numbers(numbers), m_arithmeticOperation(arithmeticOperation) {}

    void operate();

private:
    std::vector<long long> m_numbers;
    long long m_result = 0;
    std::string m_arithmeticOperation;

    void print_result();
};

Operation parse_tokens(const std::vector<Token> tokens);


#endif 