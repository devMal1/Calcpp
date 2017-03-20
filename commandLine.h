#pragma once

#include <string>

class CommandLine {
    private:
    const char LINE_FIRST_CHAR = '>';

    public:
    CommandLine();
    ~CommandLine();
    void write(const std::string &message) const;
    std::string read() const;
    std::string prompt(const std::string &message) const;
};