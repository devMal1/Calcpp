#include "CommandLine.h"
#include <string>
#include <iostream>

void testWrite(CommandLine &console, const std::string &message);
void testPrompt(CommandLine &console, const std::string &message);

int main() {

    CommandLine console;

    std::cout << "Testing write method..." << std::endl;
    //test read/write with multiple words (space separated)
    std::string message = "writing to the console!";
    testWrite(console, message);
    //test read/write empty string

    //test read/write numbers

    std::cout << "Testing prompt method..." << std::endl;
    message = "what is your age?";
    testPrompt(console, message);

    return 0;
}

void testWrite(CommandLine &console, const std::string &message) {
    std::cout << "Testing: passed ('" << message << "')'" << std::endl;
    std::cout << "____" << std::endl;
    console.write(message);
    std::cout << "____" << std::endl;
    std::cout << std::endl;
}

void testPrompt(CommandLine &console, const std::string &message) {
    std::cout << "Test: passed ('" << message << "')" << std::endl;
    std::cout << "____" << std::endl;
    std::string response = console.prompt(message);
    std::cout << "____" << std::endl;
    std::cout << "you wrote: " << response << std::endl;
}