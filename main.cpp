// LSH Implementation in C++
// Author: Fiona Kuang Z.
// Project: Locality Sensitive Hashing for Similarity Search

#include <iostream>
#include <vector>
#include <random>
#include <unordered_map>
#include <bitset>
#include <cmath>
#include <string>
#include <sstream>

const int N = 8; // Number of data vectors
const int D = 6; // Dimension of each vector
const int K = 8; // Number of random projection vectors

// Generate a random vector with normal distribution
std::vector<double> generateGaussianVector(int size, double stddev = 1.0) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<double> dist(0.0, stddev);

    std::vector<double> vec(size);
    for (int i = 0; i < size; ++i)
        vec[i] = dist(gen);
    return vec;
}

// Generate a dataset of N vectors with dimension D
std::vector<std::vector<double>> generateDataset(int numVectors, int dimension) {
    std::vector<std::vector<double>> dataset(numVectors);
    for (int i = 0; i < numVectors; ++i)
        dataset[i] = generateGaussianVector(dimension);
    return dataset;
}

// Compute dot product of two vectors
double dotProduct(const std::vector<double>& a, const std::vector<double>& b) {
    double result = 0.0;
    for (size_t i = 0; i < a.size(); ++i)
        result += a[i] * b[i];
    return result;
}

// Hash a vector using k random projections
std::string computeHash(const std::vector<double>& dataVec, const std::vector<std::vector<double>>& projections) {
    std::stringstream hashBits;
    for (const auto& proj : projections)
        hashBits << (dotProduct(dataVec, proj) >= 0 ? "1" : "0");
    return hashBits.str();
}

int main() {
    // Step 1: Generate dataset
    auto dataset = generateDataset(N, D);

    // Step 2: Generate k random projection vectors
    std::vector<std::vector<double>> projections;
    for (int i = 0; i < K; ++i)
        projections.push_back(generateGaussianVector(D));

    // Step 3: Compute hashes for all vectors and store them in buckets
    std::unordered_map<std::string, std::vector<int>> hashTable;
    for (int i = 0; i < N; ++i) {
        std::string hashKey = computeHash(dataset[i], projections);
        hashTable[hashKey].push_back(i);
    }

    // Step 4: Query - compare a new vector
    std::cout << "--- LSH Buckets ---\n";
    for (const auto& [key, indices] : hashTable) {
        std::cout << "Bucket " << key << ": ";
        for (int idx : indices)
            std::cout << idx << " ";
        std::cout << "\n";
    }

    // Step 5: Simulate a query
    std::vector<double> query = generateGaussianVector(D);
    std::string queryHash = computeHash(query, projections);

    std::cout << "\nQuery Hash: " << queryHash << "\n";
    std::cout << "Candidate matches in bucket: ";
    for (int idx : hashTable[queryHash])
        std::cout << idx << " ";
    std::cout << "\n";

    return 0;
}
