#include "calcCommandParser.h"
#include "../Command/calcCommand.h"
#include <assert.h>
#include <iostream>
#include <sstream>
#include <string>

void testParse(const std::string &testInfo, const std::string &input, 
    const std::string &expected_op, const std::string &expected_args);

int main() {

    CalcCommandParser ccParser{};

    std::string testInfo{ "valid add command" };
    std::string input{ "add 2 4" };
    testParse(testInfo, input, "add", "2,4");

    testInfo = "no operation";
    input = "2 4";
    testParse(testInfo, input, CalcCommand::NO_OP, "");
    
    testInfo = "lots of arguments";
    input = "sub 2 4 1 2 3 4 5 6 7";
    testParse(testInfo, input, "sub", "2,4,1,2,3,4,5,6,7");

    testInfo = "float/double arguments";
    input = "mult 3.0 4.6";
    testParse(testInfo, input, "mult", "3,4");

    testInfo = "no arguments";
    input = "div";
    testParse(testInfo, input, "", "");

    testInfo = "multiple operations";
    input = "add sub 2 4";
    testParse(testInfo, input, "", "");

    testInfo = "out of order command";
    input = "2 4 add";
    testParse(testInfo, input, "", "");

    testInfo = "invalid delimiter";
    input = "add/2/4";
    testParse(testInfo, input, "", "");

    testInfo = "invalid operation";
    input = "exp 3 4";
    testParse(testInfo, input, "", "");

    testInfo = "invalid arguments";
    input = "add . t";
    testParse(testInfo, input, "", "");

    testInfo = "large int";
    input = "add 11111111223334444555686886868686868 2";
    testParse(testInfo, input, "", "");
    
    std::cout << "Woot woot, all tests passed!!" << std::endl;

    return 0;
}

std::string vectorToString(const std::vector<int> &v) {
    if (v.size() <= 0) { return ""; }

    std::stringstream ss;
    for (unsigned int i = 0; i < v.size() - 1; i ++) {
        ss << v[i] << ",";
    }
    ss << v[v.size() - 1];
    return ss.str();
}
void testParse(const std::string &testInfo, const std::string &input, 
    const std::string &expected_op, const std::string &expected_args) {
    std::cout << testInfo << std::endl;
    std::cout << "Testing parse() -> expecting a calc command with: " << 
        expected_op << " " << expected_args << std::endl << std::endl;
    CalcCommandParser ccParser{};
    
    CalcCommand cCommand{ ccParser.parse(input) };

    assert(cCommand.getOperation() == expected_op &&
        vectorToString(cCommand.getArguments()) == expected_args);
}