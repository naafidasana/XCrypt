#! /bin/bash

# Create bin directory
mkdir -p bin

# Define source files
SRCS=("src/XCrypt.cpp" "src/shamir_secret_sharing.cpp" "src/utils.cpp")

# Define executable name
OUTPUT="bin/xcrypt.o"

# Compile command
g++ -std=c++14 "${SRCS[@]}" -o "${OUTPUT}"