// Copyright (c) 2024 CASM
// All rights reserved

#pragma once

#include <string>

namespace casm {
namespace strmanip {

void LeftTrim(std::string &line) noexcept;

void RightTrim(std::string &line) noexcept;

void MiddleTrim(std::string &line) noexcept;

void RemoveComma(std::string& line) noexcept;

void RemoveSubstring(std::string& line, const char *substring) noexcept;

void RemoveChar(std::string& line, char c) noexcept;

void ToUpperCase(std::string& line) noexcept;

}
}
