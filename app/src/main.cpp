// Copyright (c) 2024 CASM
// All rights reserved

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

#include "module/parser/include/parser.hpp"
#include "module/decoder/include/decoder.hpp"
#include "module/instruction/include/instruction.hpp"
#include "module/parser/include/parser_exception.hpp"

constexpr int kSucessCode = 0;
constexpr int kTooMuchParametersErrorCode = 1;
constexpr int kNoInputFileErrorCode = 2;
constexpr int kInputFileNotFoundErrorCode = 3;
constexpr int kInvalidInputFileExtensionErrorCode = 4;
constexpr int kParsingErrorCode = 5;

constexpr char kOutputFileHeader[] = "v3.0 hex words addressed";

int main(int argc, char *argv[]) {

  if(argc > 3){
    std::cerr << "\033[1;37mCASM:\033[0m \033[1;31mfatal error\033[0m: Too much parameters.\nAborting.\n";
    return kTooMuchParametersErrorCode;
  }
  else if(argc < 2){
    std::cerr << "\033[1;37mCASM:\033[0m \033[1;31mfatal error\033[0m: No input file.\nAborting.\n";
    return kNoInputFileErrorCode;
  }

  std::string input_file_name;
  input_file_name = argv[1];

  std::ifstream input_file(input_file_name);
  if(!input_file.is_open()){
    std::cerr << "\033[1;37mCASM:\033[0m \033[1;31mfatal error\033[0m: "<< input_file_name << ": File doesn't exist.\nAborting.\n";
    return kInputFileNotFoundErrorCode;
  }

  if (input_file_name.find(".asm") == input_file_name.npos){
    std::cerr << "\033[1;37mCASM:\033[0m \033[1;31mfatal error\033[0m: "<< input_file_name << ": Invalid extension.\nAborting.\n";
    return kInvalidInputFileExtensionErrorCode;
  }

  std::string output_file_name;
  if(argc == 2) {
    output_file_name = input_file_name;
    output_file_name.erase(output_file_name.find(".asm"));
  }
  else {
    output_file_name = argv[2];
  }

  std::ofstream output_file(output_file_name);
  output_file << kOutputFileHeader;

  try {
    casm::parser::ParseInstructions(input_file, output_file);
  }
  catch(casm::parser::ParserException &e) {
    std::cerr << "\033[1;37m" << input_file_name << ":" << e.GetLine() << ":\033[0m \033[1;31merror\033[0m: " << e.what() << ".\nAborting.\n";
    std::remove(output_file_name.c_str());
    return kParsingErrorCode;
  }

  return kSucessCode;
}
