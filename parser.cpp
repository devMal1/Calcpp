#include "parser.h"

Parser::Parser() {}

Parser::~Parser() {}

std::vector<string> extractTokens(const std::string &input, const std::string &delimiter) {
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