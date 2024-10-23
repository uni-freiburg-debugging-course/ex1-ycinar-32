#include <iostream>
#include <fstream>
#include <string>

#include "Lexer.h"
#include "Parser.h"


int main(){

    std::ifstream inputFile("output.txt");
    if (!inputFile.is_open()) { 
        std::cerr << "Error: Could not open the file." << std::endl;
        return 1;
    }

    std::string line;
    std::vector<Token> tokens;
    std::vector<Operation> operations;

    while (std::getline(inputFile, line)) {
        //std::cout << line << std::endl;
        tokens = lineLexer(line);
        /*for (const auto& token : tokens) {
            std::cout << "Token: " << token.value << " Role: " << static_cast<int>(token.role) << std::endl;
        }*/
        operations.push_back(parse_tokens(tokens));
    }

    for(auto &op: operations){
        op.operate();
    }

    inputFile.close();  
    return 0;
}