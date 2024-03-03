# Copyright (c) 2024 CASM
# All rights reserved

cmake_minimum_required(VERSION ${CMAKE_VERSION})
project("CRISC Assembler" C CXX)

set(casm_dir ${PROJECT_SOURCE_DIR})

add_subdirectory(${casm_dir}/module)
add_subdirectory(${casm_dir}/utils)
add_subdirectory(${casm_dir}/app)
