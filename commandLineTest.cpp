#include "CommandLine.h"
#include <string>
#include <iostream>

void testWrite(CommandLine &console, const std::string &message);
void testWrite(CommandLine &console, int message);
void testPrompt(CommandLine &console, const std::string &message);

int main() {

    CommandLine console;

    std::cout << "Testing write method..." << std::endl;
    //test write with multiple words (space separated)
    std::string message = "writing to the console!";
    testWrite(console, message);
    //test write empty string
    testWrite(console, "");
    message = "";
    testWrite(console, message);
    //test write single word
    message = "hello";
    testWrite(console, message);
    //test write undefined
    std::string undefinedMessage;
    testWrite(console, undefinedMessage);
    //test write numbers
    message = "1 20 300 4";
    testWrite(console, message);
    //test write number
    testWrite(console, -59848474);

    std::cout << "Testing prompt method..." << std::endl;
    //test prompt number input
    message = "what is your age?";
    testPrompt(console, message);
    //test prompt string input
    message = "what is your first name?";
    testPrompt(console, message);
    //test prompt string multiple words input
    message = "what is your first and last name?";
    testPrompt(console, message);
    //test prompt string multiple lines(?)

    //test prompt empty string input
    message = "Just hit return (testing empty string)";
    testPrompt(console, message);
    //test prompt whitespace string input
    message = "Just type <spaces> and hit return";
    testPrompt(console, message);

    return 0;
}

void testWrite(CommandLine &console, const std::string &message) {
    std::cout << "Testing ('" << message << "')" << std::endl;
    std::cout << "____" << std::endl;
    console.write(message);
    std::cout << "____" << std::endl;
    std::cout << std::endl;
}

void testWrite(CommandLine &console, int message) {
    std::cout << "Testing ('" << message << "')" << std::endl;
    std::cout << "____" << std::endl;
    console.write(message);
    std::cout << "____" << std::endl;
    std::cout << std::endl;
}

void testPrompt(CommandLine &console, const std::string &message) {
    std::cout << "Testing ('" << message << "')" << std::endl;
    std::cout << "____" << std::endl;
    std::string response = console.prompt(message);
    std::cout << "____" << std::endl;
    std::cout << "you wrote: " << response << std::endl;
}