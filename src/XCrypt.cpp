#include <iostream>
#include "../include/shamir_secret_sharing.hpp"


int main()
{
    int secret;         // Secret to be sharded
    int n = 6;          // Total number of shards
    int k = 3;          // Mimimum number of shards needed to reconstruct key
    int prime = 7919;   // A prime number larger than the secret and number of shards

    // Prompt the user to enter the secret they wish to shard
    std::cout << "Enter secret key (Only integers are supported for now. Your input should be less than 7919)." << std::endl;
    std::cin >> secret;

    // Generate shards
    std::vector<std::pair<int, int>>shards = xcrypt::generateShards(secret, n, k, prime);

    // Display shards
    std::cout << "Generated Shards:" << std::endl;
    for (const auto& shard : shards)
    {
        std::cout << "(" << shard.first <<", " << shard.second << ")" << std::endl;
    }

    // Select K shares to reconstruct the key
    std::vector<std::pair<int, int>> selectedShards(shards.begin(), shards.begin() + k);

    // Reconstruct key
    int reconstructedSecret = xcrypt::reconstructSecret(selectedShards, prime);
    std::cout << "Reconstructed Secret: " << reconstructedSecret << std::endl;

    return 0;
}