#include "calcComputer.h"

CalcComputer::CalcComputer() {}

CalcComputer::~CalcComputer() {}

int add(int a, int b) {
    return (a + b);
}
int sub(int a, int b) {
    return (a - b);
}
int mult(int a, int b) {
    return (a * b);
}
int divi(int a, int b) {
    if (b == 0) { throw CalcComputer::DIV_BY_ZERO; }
    return (a / b);
}

int CalcComputer::reduce(const std::vector<int> &nums, int (*reducer)(int, int)) {
    if (nums.size() == 1) { return nums[0]; }

    int value{ (*reducer)(nums[0], nums[1]) };
    for (unsigned int i = 2; i < nums.size(); i ++) {
        value = (*reducer)(value, nums[i]);
    }
    return value;
}

int CalcComputer::compute(const CalcCommand &command) {
    if (command.getArguments().size() < 1) { throw NOT_ENOUGH_ARGUMENTS; }
    
    std::string op{ command.getOperation() };
    if (op == "add") { return reduce(command.getArguments(), add); }
    if (op == "sub") { return reduce(command.getArguments(), sub); }
    if (op == "mult") { return reduce(command.getArguments(), mult); }
    if (op == "div") { return reduce(command.getArguments(), divi); }
    
    throw INVALID_OPERATION;
}

const int CalcComputer::NOT_ENOUGH_ARGUMENTS = -1000;
const int CalcComputer::INVALID_OPERATION = -2000;
const int CalcComputer::DIV_BY_ZERO = -3000;