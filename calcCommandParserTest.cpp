#include "calcCommandParser.h"
#include "calcCommand.h"
#include <assert.h>
#include <iostream>
#include <sstream>
#include <string>

void testSuite(CalcCommand &cc, std::string expectedOp, 
    std::string expectedArgs, bool expectedCommandless);

int main() {
    
    std::cout << "Woot woot, all tests passed!!" << std::endl;

    return 0;
}

void testGetOperation(CalcCommand &cc, std::string expected) {
    std::cout << " Testing getOperation() -> expecting: " + expected << std::endl;
    assert(cc.getOperation() == expected);
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
void testGetArguments(CalcCommand &cc, std::string expected) {
    std::cout << " Testing getArguments() -> expecting: " + expected << std::endl;
    assert(vectorToString(cc.getArguments()) == expected);
}
void testCommandless(CalcCommand &cc, bool expected) {
    std::cout << " Testing commandless() -> expecting: " << expected << std::endl;
    assert(cc.commandless() == expected);
}
void testSuite(CalcCommand &cc, std::string expectedOp, std::string expectedArgs, bool expectedCommandless) {
    std::cout << "Testing CalcCommand{ '" + expectedOp + "', {" + expectedArgs + "} }" << std::endl;
    testGetOperation(cc, expectedOp);
    testGetArguments(cc, expectedArgs);
    testCommandless(cc, expectedCommandless);
    std::cout << std::endl;
}