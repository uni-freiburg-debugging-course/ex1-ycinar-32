#include <iostream>
#include <string>
#include <random> 
#include <fstream> 
#include <cmath>

#define FUZZER_ELEMENT_LENGTH 10

int main(){

    std::ofstream outFile("output.txt", std::ios::trunc);  

    std::random_device rd;  
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<int32_t> dist(INT32_MIN, INT32_MAX);

    for(int i = 0; i < FUZZER_ELEMENT_LENGTH; i++){
        int32_t num1 = dist(gen);
        int32_t num2 = dist(gen);

        int32_t arith = abs(dist(gen)) % 3;

        std:: cout << arith;

        std::string arithmetic = (arith == 0) ? "+" : (arith == 1) ? "-" : (arith == 2) ? "*" : "Invalid";

        std::cout << "(simplify (" << arithmetic << " " <<  num1 << " " << num2 << "))" << std::endl;

        outFile << "(simplify (" << arithmetic << " " <<  num1 << " " << num2 << "))" << std::endl;

    }

    outFile.close();

    std::cout << "Data successfully written to output.txt!" << std::endl;
    return 0;
    
}