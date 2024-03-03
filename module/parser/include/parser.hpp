// Copyright (c) 2024 CASM
// All rights reserved

#pragma once

#include <fstream>

namespace casm {
namespace parser {

void ParseInstructions(std::ifstream& input_file, std::ofstream &output_file);

}
}
