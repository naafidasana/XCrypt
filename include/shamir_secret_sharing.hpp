#pragma once

#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>


namespace xcrypt {
    // Function to generate random polynomial coefficients
    std::vector<int> generateCoefficients(int secret, int k,  int prime);

    // Function to evaluate a polynomial at a given `x` using Honer's method
    int evaluatePolynomial(const std::vector<int>& coeffs, int x, int prime);

    // Function to genearte `n` shards from a secret
    std::vector<std::pair<int, int>> generateShards(int secret, int n, int k, int prime);

    // Function to reconstruct the secret from shards using Lagrange interpolation
    int reconstructSecret(const std::vector<std::pair<int, int>>& shards, int prime);
}