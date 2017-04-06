// #include "calcCommandParser.h"
#include "calcCommand.h"
#include <iostream>
#include <string>

int main() {
    
    std::cout << "Testing Empty CalcCommand" << std::endl;
    CalcCommand cc;
    std::cout << "commandless? " << cc.commandless() << std::endl;
    std::cout << std::endl;

    std::cout << "Testing CalcCommand{ 'add', {1,2,3} }" << std::endl;
    CalcCommand cc2{ "add", {1,2,3} };
    std::cout << "command? " << cc2.getOperation() << std::endl;
    std::cout << "first argument? " << cc2.getArguments()[0] << std::endl;
    std::cout << "commandless? " << cc2.commandless() << std::endl;
    std::cout << std::endl;
    

    return 0;
}