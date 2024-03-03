// Copyright (c) 2024 CASM
// All rights reserved

#pragma once

#include <string>
#include <vector>

namespace casm {
namespace instruction {

enum class InstructionType {
  kControl,
  kAluBinary,
  kAluUnary,
  kMemory,
  kInputOutput,
  kBranch,
  kImmediate,
};

struct Instruction {
  std::string mnemonic;
  int opcode;
  int register_number;
  InstructionType type;
};

const Instruction* GetInstruction(const std::string& mnemonic);

std::vector<std::string> SplitInstruction(const std::string& line);

void CleanInstruction(std::string &line);

}
}
