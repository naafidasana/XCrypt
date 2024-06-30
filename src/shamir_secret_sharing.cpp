#include "../include/shamir_secret_sharing.hpp"
#include "../include/utils.hpp"
#include <iostream>


namespace xcrypt {
    // Function to generate random polynomial coefficients
    std::vector<int> generateCoefficients(int secret, int k,  int prime)
    {
        std::vector<int> coeffs(k);
        coeffs[0] = secret;
        for (int i = 1; i < k; ++i)
        {
            coeffs[i] = rand() % prime;
        }
        return coeffs;
    }

    // Function to evaluate a polynomial at a given `x` using Honer's method
    int evaluatePolynomial(const std::vector<int>& coeffs, int x, int prime)
    {
        int result = 0;
        for (int i = coeffs.size() - 1; i >= 0; --i)
        {
            result = (xcrypt::modMult(result, x, prime) + coeffs[i]) % prime;
        }
        return result;
    }

    // Function to genearte `n` shards from a secret
    std::vector<std::pair<int, int>> generateShards(int secret, int n, int k, int prime)
    {
        std::vector<std::pair<int, int>> shards;
        std::vector<int> coeffs = generateCoefficients(secret, k, prime);
        for (int i = 1; i <= n; ++i)
        {
            int x = i;
            int y = evaluatePolynomial(coeffs, x, prime);
            shards.emplace_back(x, y);
        }
        return shards;
    }

    // Function to reconstruct the secret from shards using Lagrange interpolation
    int reconstructSecret(const std::vector<std::pair<int, int>>& shards, int prime)
    {
        int secret = 0;
        for (size_t i = 0; i < shards.size(); ++i)
        {
            int xi = shards[i].first;
            int yi = shards[i].second;
            int li = 1;
            for (size_t j = 0; j < shards.size(); ++j)
            {
                if (i != j)
                {
                    int xj = shards[j].first;
                    int denominator = (xj - xi + prime) % prime;
                    if (denominator == 0)
                    {
                        std::cerr <<"Error: Denominator in Lagrange Basis Polynomial is zero." << std::endl;
                        exit(EXIT_FAILURE);
                    }
                    li = xcrypt::modMult(li, (xj * xcrypt::modInverse((xj - xi + prime) % prime, prime)) % prime, prime);
                }
            }
            secret = (secret + modMult(yi, li, prime)) % prime;
        }
        return secret;
    }
}