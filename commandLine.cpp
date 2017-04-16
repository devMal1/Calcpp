#include "CommandLine.h"
#include <iostream>

CommandLine::CommandLine() {}

CommandLine::~CommandLine() {}

std::string CommandLine::read() const {
    std::string message;
    getline(std::cin, message);
    return message;
}

void CommandLine::write(const std::string &message) const {
    std::cout << message << std::endl;
}

void CommandLine::write(int number) const {
    std::cout << number << std::endl;
}

std::string CommandLine::prompt(const std::string &message) const {
    write(message);
    std::cout << LINE_FIRST_CHAR;
    return read();
}

std::string CommandLine::prompt() const {
    std::cout << LINE_FIRST_CHAR;
    return read();
}