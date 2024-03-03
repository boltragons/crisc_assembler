// Copyright (c) 2024 CASM
// All rights reserved

#include "module/parser/include/parser.hpp"

#include <stdexcept>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

#include "module/decoder/include/decoder.hpp"
#include "module/instruction/include/instruction.hpp"
#include "module/parser/include/parser_exception.hpp"

constexpr int kMemorySpaces = 256;

inline static void WriteLineOffset(std::ofstream &output_file, int current_line) noexcept {
  if(current_line % 0x10 == 0) {
    output_file << "\n" << std::setfill('0') << std::setw(2) << std::hex << current_line << ":";
  }
}

inline static void FillRemainingMemory(std::ofstream &output_file, int last_line) noexcept {
  for(int i = last_line; i < kMemorySpaces; i++) {
    WriteLineOffset(output_file, i);
    output_file << " 00";
  }
}

void casm::parser::ParseInstructions(std::ifstream& input_file, std::ofstream &output_file) {
  int input_file_line = 0;
  int output_file_line = 0;

  std::string line;

  while(std::getline(input_file, line)) {
    try {
      input_file_line++;
      
      casm::instruction::CleanInstruction(line);

      if(line.empty()) {
        continue;
      }
  
      int machine_code = casm::decoder::DecodeInstruction(casm::instruction::SplitInstruction(line));

      WriteLineOffset(output_file, output_file_line);

      output_file << " " << std::setfill('0') << std::setw(2) << std::hex << machine_code;

      output_file_line++;
    }
    catch(std::exception &e) {
      throw ParserException(e.what(), input_file_line);
    }
  }
  FillRemainingMemory(output_file, output_file_line);
}
