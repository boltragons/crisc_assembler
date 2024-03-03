// Copyright (c) 2024 CASM
// All rights reserved

#pragma once

#include <vector>
#include <string>

#include "module/instruction/include/instruction.hpp"

namespace casm {
namespace decoder {

int DecodeRegister(const std::string& reg);

int DecodeImmediate(const std::string& imm);

int DecodeInstruction(const std::vector<std::string>& instruction_elements);

}
}
