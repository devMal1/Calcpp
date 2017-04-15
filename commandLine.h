#pragma once

#include <string>

class CommandLine {
    private:
    const char LINE_FIRST_CHAR = '>';
    std::string read() const;

    public:
    CommandLine();
    ~CommandLine();
    void write(const std::string &message) const;
    void write(int number) const;
    std::string prompt(const std::string &message) const;
};