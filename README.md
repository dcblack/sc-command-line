# sc-command-line

## Description

An example of how to grab command-line arguments within any SystemC module.

## Instructions

Compile (roughly) and run with

    gcc -std=c++11 -o example.x -L$SYSTEMC/lib -lsystemc -I$SYSTEMC/include command_line_example.cpp
    ./example.x
    ./example.x -debug
    ./example.x -quiet
or use a properly configured cmake setup

## Dependencies

1. A reasonable implementation of C++11 (e.g. recent versions of clang or gcc)
2. A properly installed version of SystemC 2.3 or later.
