#pragma once

#include <string>

class CommandLine {
    private:
    
    public:
    CommandLine();
    ~CommandLine();
    void write(const &std::string message) const;
    std::string read() const;
};