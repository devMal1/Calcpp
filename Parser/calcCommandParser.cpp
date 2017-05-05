#include "calcCommandParser.h"
#include <exception>

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
    tokens.push_back(input.substr(startIndex, std::string::npos)); //add last part of string
    
    return tokens;
}

std::string CalcCommandParser::extractOperation(const std::vector<std::string> &tokens) const {
    std::string op = tokens[CalcCommandParser::OP_INDEX];
    for (unsigned int i = 0; i < CalcCommandParser::COMMANDS.size(); i ++) {
        if (op == CalcCommandParser::COMMANDS[i]) { //commands are in lowercase
            return op;
        }
    }
    return CalcCommand::NO_OP;
}

std::vector<int> CalcCommandParser::extractArguments(const std::vector<std::string> &tokens) const {
    const int NUM_OF_OPS = CalcCommandParser::OP_INDEX + 1;
    std::vector<int> arguments{};
    for (unsigned int i = NUM_OF_OPS; i < tokens.size(); i ++) {
        try {
            arguments.push_back(stoi(tokens[i]));
        } catch (const std::exception &ex) {
            std::vector<int> empty{};
            return empty;
        }
    }
    return arguments;
}

CalcCommand CalcCommandParser::parse(const std::string &input) const {
    std::string operation{};
    std::vector<int> arguments{};

    std::vector<std::string> tokens = extractTokens(input, DELIMITER);
    operation = extractOperation(tokens);
    arguments = extractArguments(tokens);

    bool invalidCommand = (operation.length() == 0 || arguments.size() == 0);
    if (invalidCommand) {
        CalcCommand cc{};
        return cc;
    } else {
        CalcCommand cc{ operation, arguments };
        return cc;
    }
}

const char CalcCommandParser::DELIMITER = ' ';
const int CalcCommandParser::OP_INDEX = 0;
const std::vector<std::string> CalcCommandParser::COMMANDS{ "add", "sub", "mult", "div" }; //TODO check cplusplus for sets!