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
    return this->arguments;
}

bool CalcCommand::commandless() const {
    return this->operation == NO_OP || this->arguments.size() == 0;
}

const std::string CalcCommand::NO_OP = "";