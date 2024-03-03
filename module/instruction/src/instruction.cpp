// Copyright (c) 2024 CASM
// All rights reserved

#include "module/instruction/include/instruction.hpp"

#include <sstream>
#include <stdexcept>
#include <algorithm>

#include "utils/strmanip/include/strmanip.hpp"
#include "module/instruction/include/instructionlist.hpp"

constexpr char kOperandSeparator = ','; 
constexpr char kCommentSymbol[] = "//"; 

void casm::instruction::CleanInstruction(std::string &line) {
  strmanip::RemoveComma(line);
  strmanip::RemoveChar(line, kOperandSeparator);
  strmanip::RightTrim(line);
  strmanip::LeftTrim(line);
  strmanip::MiddleTrim(line);
  strmanip::RemoveSubstring(line, kCommentSymbol);
  strmanip::ToUpperCase(line);
}

std::vector<std::string> casm::instruction::SplitInstruction(const std::string& line) {
  std::vector<std::string> elements;

  std::stringstream line_stream(line);
  
  std::string intermediate;
  
  while(std::getline(line_stream, intermediate, ' ')) {
    elements.push_back(intermediate);
  }

  return elements;
}

const casm::instruction::Instruction* casm::instruction::GetInstruction(const std::string& mnemonic) {
  const Instruction* instruction = std::find_if(std::begin(instructions::list), std::end(instructions::list), [&](const auto& instruction) {
    return mnemonic == instruction.mnemonic;
  });

  if(!instruction) {
    throw std::invalid_argument("Invalid mnemonic");
  }

  return instruction;
}