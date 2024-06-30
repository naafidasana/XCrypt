#pragma once

#include <iostream>

namespace xcrypt {
    // Function to compute (a * b) % mod
    int modMult(int a, int b, int mod);

    // Function to compute (base^exp) % mod using modular exponentiation
    int modExp(int base, int exp, int mod);

    // Function to compute modular inverse of a under mod
    int modInverse(int a, int b);

    // Function to convert a string into an integer
    unsigned long long stringToInt(const std::string& str);

    // Function to convert an integer into a string
    std::string intToString(unsigned long long num);
}
