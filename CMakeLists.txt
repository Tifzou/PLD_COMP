cmake_minimum_required(VERSION 3.13)
project(PLD_COMP)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_custom_target(generate COMMAND make antlr -C ${PLD_COMP_SOURCE_DIR}
        CLION_EXE_DIR=${PROJECT_BINARY_DIR})

add_custom_target(compilate COMMAND make exec -C ${PLD_COMP_SOURCE_DIR}
        CLION_EXE_DIR=${PROJECT_BINARY_DIR})
