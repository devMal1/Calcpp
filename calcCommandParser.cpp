#include "calcCommandParser.h"
#include <iostream>
#include <string>
#include <vector>

CalcCommandParser::CalcCommandParser() {}

CalcCommandParser::~CalcCommandParser() {}

std::vector<string> extractTokens(const std::string &input, const std::string &delimiter) const {
    std::vector<string> tokens{};
    const std::size_t NEXT_CHAR{ 1 }; 
    std::size_t startIndex{ 0 };
    std::size_t delIndex{ input.find_first_of(delimiter) };
    while (delIndex != std::string::npos) {
        std::size_t numOfChars{ delIndex - startIndex };
        tokens.push_back(input.substr(startIndex, numOfChars));
        startIndex = delIndex + NEXT_CHAR;
        delIndex = input.find_first_of(delimiter, startIndex);
    }
    return tokens;
}

std::string extractOperation(const std::vector<string> &tokens) const {
    std::string op = tokens[CalcCommandParser::OP_INDEX];
    for (int i = 0; i < CalcCommandParser::COMMANDS.lenth(); i ++) {
        if (op == CalcCommandParser::COMMANDS[i]) { //commands are in lowercase
            return op;
        }
    }
    return "";
}

std::vector<int> extractArguments(const std::vector<string> &tokens) const {
    const NUM_OF_OPS = CalcCommandParser::OP_INDEX + 1;
    std::vector<int> arguments{};
    for (int i = NUM_OF_OPS; i < tokens.length(); i ++) {
        arguments.push_back(stoi(tokens[i]));
    }
    return arguments;
}

CalcCommand CalcCommandParser::parse(const std::string &input) {
    CalcCommand cc{};
    std::string operation{};
    std::vector<int> arguments{};

    std::vector<std::string> tokens = extractTokens(input, CalcCommandParser::DELIMITER);
    operation = extractOperation(tokens);
    arguments = extractArguments(tokens);

    CalcCommand cc{ operation, arguments };
    return cc;
}