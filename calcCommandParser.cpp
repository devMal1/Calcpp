#include "calcCommandParser.h"

CalcCommandParser::CalcCommandParser() {}

CalcCommandParser::~CalcCommandParser() {}

std::vector<std::string> CalcCommandParser::extractTokens(const std::string &input, char delimiter) const {
    std::vector<std::string> tokens{};
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

std::string CalcCommandParser::extractOperation(const std::vector<std::string> &tokens) const {
    std::string op = tokens[CalcCommandParser::OP_INDEX];
    for (unsigned int i = 0; i < CalcCommandParser::COMMANDS.size(); i ++) {
        if (op == CalcCommandParser::COMMANDS[i]) { //commands are in lowercase
            return op;
        }
    }
    return "";
}

std::vector<int> CalcCommandParser::extractArguments(const std::vector<std::string> &tokens) const {
    const int NUM_OF_OPS = CalcCommandParser::OP_INDEX + 1;
    std::vector<int> arguments{};
    for (unsigned int i = NUM_OF_OPS; i < tokens.size(); i ++) {
        arguments.push_back(stoi(tokens[i]));
    }
    return arguments;
}

CalcCommand CalcCommandParser::parse(const std::string &input) const {
    std::string operation{};
    std::vector<int> arguments{};

    std::vector<std::string> tokens = extractTokens(input, DELIMITER);
    operation = extractOperation(tokens);
    arguments = extractArguments(tokens);

    CalcCommand cc{ operation, arguments };
    return cc;
}

const char DELIMITER = ' ';
const int OP_INDEX = 0;
const std::vector<std::string> COMMANDS{ "add", "sub", "mult", "div" }; //TODO check cplusplus for sets!