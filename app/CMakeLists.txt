# Copyright (c) 2024 CASM
# All rights reserved

set(project_name casm_app)

set(sources_dir ${CMAKE_CURRENT_LIST_DIR}/src)

set(sources
    ${sources_dir}/main.cpp
)

set(casm_executable casm)

add_executable(${casm_executable} ${sources})

target_link_libraries(${casm_executable} LINK_PUBLIC
    casm_module_instruction
    casm_module_decoder
    casm_module_parser
)