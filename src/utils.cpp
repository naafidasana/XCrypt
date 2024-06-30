#include "../include/utils.hpp"


namespace xcrypt {
    // Function to compute (a * b) % mod
    int modMult(int a, int b, int mod)
    {
        return (static_cast<long long>(a) * b) % mod;
    }

    // Function to compute (base^exp) % mod using modular exponentiation
    int modExp(int base, int exp, int mod)
    {
        int result = 1;
        base = base % mod;
        while (exp > 0)
        {
            if (exp % 2 == 1)
                result = (result * base) % mod;
            exp = exp >> 1;
            base = (base * base) % mod;
        }
        return result;
    }

    // Function to compute modular inverse of a under mod
    int modInverse(int a, int mod)
    {
        a = a % mod;
        if (a == 0)
        {
            std::cerr << "Error: Attempt to find modular inverse of zero." << std::endl;
            exit(EXIT_FAILURE);
        }
        int m0 = mod, t, q;
        int x0 =  0, x1 = 1;
        if (mod == 1)
            return 0;
        while (a > 1) {
            q = a / mod;
            t = mod;
            mod = a % mod;
            a = t;
            t = x0;
            x0 = x1 - q * x0;
            x1 = t;
        }
        if (x1 < 0)
            x1 += m0;
        return x1;
    }
}