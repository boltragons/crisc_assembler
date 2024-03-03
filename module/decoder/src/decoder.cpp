// Copyright (c) 2024 CASM
// All rights reserved

#include "module/decoder/include/decoder.hpp"

#include <stdexcept>

int casm::decoder::DecodeRegister(const std::string& reg) {
  if(reg.length() != 2 && reg.at(0) != 'R' || reg.at(1) < '0' || reg.at(1) > '3') {
    throw std::invalid_argument("Invalid register identifier");
  }

  return reg.at(1) - '0';
}

int casm::decoder::DecodeImmediate(const std::string& imm) {
  if(imm.length() != 1) {
    throw std::invalid_argument("Invalid 4-bit immediate");
  }

  int imm_val = 0;
  try {
    imm_val = std::stoi(imm, nullptr, 16);
  }
  catch(...) {
    throw std::invalid_argument("Invalid 4-bit immediate");
  }

  return imm_val;
}

int casm::decoder::DecodeInstruction(const std::vector<std::string>& instruction_elements) {
  const instruction::Instruction* instruction_ptr = nullptr;

  instruction_ptr = instruction::GetInstruction(instruction_elements[0]);

  if((instruction_ptr->type != instruction::InstructionType::kImmediate && instruction_elements.size() - 1 != instruction_ptr->register_number)
    || (instruction_ptr->type == instruction::InstructionType::kImmediate && instruction_elements.size() != 3)) {
    throw std::invalid_argument("Invalid combination of operands");
  }

  int operand = 0;
  switch(instruction_ptr->register_number) {
    case 0:
      break;
    case 1:
      operand = DecodeRegister(instruction_elements[1]);
      if(instruction_ptr->type == instruction::InstructionType::kImmediate) {
        operand |= DecodeImmediate(instruction_elements[2]) << 2;
      }
      break;
    case 2:
      operand = DecodeRegister(instruction_elements[2]) << 2;
      operand |= DecodeRegister(instruction_elements[1]);
      break;
  }

  return instruction_ptr->opcode | operand;
}
