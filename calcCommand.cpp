#include "calcCommand.h"

CalcCommand::CalcCommand() {
    std::vector<int> empty{};
    CalcCommand(NO_OP, empty); 
}

CalcCommand::CalcCommand(const std::string &op, const std::vector<int> &args) :
    operation(op), arguments(args) {}

CalcCommand::~CalcCommand() {}

std::string CalcCommand::getOperation() const {
    return this->operation;
}

std::vector<int> CalcCommand::getArguments() const {
    return this->argumnets;
}

bool CalcCommand::commandless() const {
    return this->operation == NO_OP || this->arguments.length() == 0;
}