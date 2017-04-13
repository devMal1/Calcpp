#include "calcComputer.h"
#include "calcCommand.h"
#include <iostream>
#include <assert.h>
#include <string>
#include <vector>

void testCompute(const std::string &testInfo, const std::string &operation, 
    const std::vector<int> &arguments, int expected);

int main() {
    const int ERROR{ -9999 };

    testCompute("valid add", "add", {1,2,3}, 6);
    testCompute("valid sub", "sub", {1,2,3}, -4);
    testCompute("valid mult", "mult", {1,2,3}, 6);
    testCompute("valid div", "div", {6,-3,1}, -2);
    
    // testCompute("invalid operation", "exp", {6,-3,1}, ERROR);

    // testComputer("divide by zero", "div", {5,0}, ERROR); //TODO: Add errors in impl. then add try catch

    testCompute("one argument", "div", {6}, 6);

    // testCompute("no arguments", "div", {}, ERROR);

    // testCompute("no operation", "", {6,-3,1}, ERROR);

    // testCompute("multiple operations", "div add", {6,-3,1}, ERROR);

    std::cout << "Woot woot, all tests passed!!" << std::endl;

    return 0;
}

void testCompute(const std::string &testInfo, const std::string &operation, 
    const std::vector<int> &arguments, int expected) {
    std::cout << testInfo << std::endl;
    std::cout << "Testing compute() -> expecting: " << expected << " " << std::endl << std::endl;
    CalcComputer computer{};
    CalcCommand command{ operation, arguments };
    
    int ans = computer.compute(command);

    assert(ans == expected);
}