// Copyright (c) 2024 CASM
// All rights reserved

#include "module/parser/include/parser_exception.hpp"

casm::parser::ParserException::ParserException(const std::string& message, int line) noexcept
    : std::exception(), message(message), line(line) {}

char const* casm::parser::ParserException::what() const noexcept {
    return message.c_str();
}

int casm::parser::ParserException::GetLine() const noexcept {
    return line;
}
