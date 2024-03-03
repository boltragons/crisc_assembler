// Copyright (c) 2024 CASM
// All rights reserved

#pragma once

#include <stdexcept>

namespace casm {
namespace parser {

class ParserException : private std::exception {
public:
    ParserException(const std::string& message, int line) noexcept;
    virtual ~ParserException() = default;
    virtual char const* what() const noexcept;
    int GetLine() const noexcept;

private:
    std::string message;
    int line;
};

}
}
