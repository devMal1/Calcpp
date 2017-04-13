#include "calcComputer.h"

CalcComputer::CalcComputer() {}

CalcComputer::~CalcComputer() {}

int CalcComputer::add(int a, int b) {
    return (a + b);
}

int CalcComputer::sub(int a, int b) {
    return (a - b);
}

int CalcComputer::mult(int a, int b) {
    return (a * b);
}

int CalcComputer::divi(int a, int b) {
    if (b == 0) { throw -3; } //TODO: throw error for invalid argument
    return (a / b);
}

int CalcComputer::reduce(const vector<int> &nums, int (*reducer)(int, int)) {
    if (nums.size() == 1) { return nums[0]; }

    int value{ (*reducer)(nums[0], nums[1]) };
    for (unsigned int i = 2; i < nums.size(); i ++) {
        value = (*reducer)(value, nums[i]);
    }
    return value;
}

int CalcComputer::compute(const CalcCommand &command) {
    if (command.getArguments().size() < 1) { throw -1; } //TODO: throw error, for not enough arguments
    switch (command.getOperation()) {
        case "add": //TODO: SHOULD BE ENUMS????
            return reduce(command.getArguments(), add);
        case "sub":
            return reduce(command.getArguments(), sub);
        case "mult":
            return reduce(command.getArguments(), mult);
        case "div":
            return reduce(command.getArguments(), divi);
        default:
            throw -2; //TODO: throw error, for invalid operation
    }
}