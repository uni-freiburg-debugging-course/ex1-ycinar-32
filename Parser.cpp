#include "Parser.h"
#include <cctype> 
#include <iostream>
#include <cmath>

Operation parse_tokens(const std::vector<Token> tokens){

    std::vector<long long> numbers;
    std::string arithmeticType;

    for(auto token : tokens){
        if(token.role == TokenRole::Operator){
            arithmeticType = token.value;
        }
        else if(token.role == TokenRole::Number){
            numbers.push_back(stoi(token.value));
        }
    }
    Operation *operation = new Operation(numbers, arithmeticType);
    
    return *operation;
}

void Operation::operate()
{
    if(m_arithmeticOperation == "*"){
        m_result = m_numbers[0] * m_numbers[1];
    }
    else if(m_arithmeticOperation == "+"){
        m_result = m_numbers[0] + m_numbers[1];
    }
    else if(m_arithmeticOperation == "-"){
        m_result = m_numbers[0] - m_numbers[1];
    }

    print_result();
}

void Operation::print_result(){
    if(m_result < 0){
        std::cout << "(" << "- " << abs(m_result) << ")" <<std::endl;
    }
    else{
        std::cout << m_result << std::endl;
    }
}