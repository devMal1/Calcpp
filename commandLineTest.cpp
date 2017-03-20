#include "CommandLine.h"
#include <string>
#include <iostream>

int main() {

    CommandLine console;

    std::cout << "Testing the write command, passed ('what is your name?')" << std::endl;
    console.write("what is your name?");

    std::cout << "Testing the read command" << std::endl;
    std::string response = console.read();
    std::cout << "you wrote: " << response;

    std::cout << "Testing the prompt command, passed ('what is your age?')" << std::endl;
    response = console.prompt("what is your age?");
    std::cout << "you wrote: " << response;

    //test read/write empty string
    //test read/write numbers
    //test read/write with multiple words (space separated)

    return 0;
}