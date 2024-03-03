// Copyright (c) 2024 CASM
// All rights reserved

#pragma once

#include "module/instruction/include/instruction.hpp"

namespace casm {
namespace instructions {

const instruction::Instruction list[] = {
  {"HALT",  0x00, 0, instruction::InstructionType::kControl},
  {"ADD",   0x10, 2, instruction::InstructionType::kAluBinary},
  {"SUB",   0x20, 2, instruction::InstructionType::kAluBinary},
  {"AND",   0x30, 2, instruction::InstructionType::kAluBinary},
  {"OR",    0x40, 2, instruction::InstructionType::kAluBinary},
  {"XOR",   0x50, 2, instruction::InstructionType::kAluBinary},
  {"MUL",   0x60, 2, instruction::InstructionType::kAluBinary},
  {"CMP",   0x70, 2, instruction::InstructionType::kAluBinary},
  {"LD",    0x80, 2, instruction::InstructionType::kMemory},
  {"ST",    0x90, 2, instruction::InstructionType::kMemory},
  {"B",     0xA0, 1, instruction::InstructionType::kBranch},
  {"BZ",    0xA4, 1, instruction::InstructionType::kBranch},
  {"IN",    0xA8, 1, instruction::InstructionType::kInputOutput},
  {"OUT",   0xAC, 1, instruction::InstructionType::kInputOutput},
  {"NOT",   0xB0, 1, instruction::InstructionType::kAluUnary},
  {"NEG",   0xB4, 1, instruction::InstructionType::kAluUnary},
  {"INC",   0xB8, 1, instruction::InstructionType::kAluUnary},
  {"DEC",   0xBC, 1, instruction::InstructionType::kAluUnary},
  {"LI",    0xC0, 1, instruction::InstructionType::kImmediate}
};

}
}
