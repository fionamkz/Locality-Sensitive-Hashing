#include "utils.h"
#include <iostream>
#include <cmath>

// Imprime un solo vector en formato [ a b c ... ]
void imprimirVector(const std::vector<double>& v) {
    std::cout << "[ ";
    for (double val : v)
        std::cout << val << " ";
    std::cout << "]\n";
}

// Imprime todos vectores de datos con índice
void imprimirVectores(const std::vector<std::vector<double>>& datos) {
    for (size_t i = 0; i < datos.size(); ++i) {
        std::cout << "Vector " << i << ": ";
        imprimirVector(datos[i]);
    }
}

// Imprime contenido de buckets generados por LSH
void imprimirBuckets(const std::unordered_map<std::string, std::vector<int>>& buckets) {
    for (const auto& [hash, indices] : buckets) {
        std::cout << "Bucket " << hash << ": ";
        for (int idx : indices)
            std::cout << idx << " ";
        std::cout << "\n";
    }
}

// Calcula similitud coseno entre dos vectores
double similitudCoseno(const std::vector<double>& a, const std::vector<double>& b) {
    double dot = 0.0, normA = 0.0, normB = 0.0;
    for (size_t i = 0; i < a.size(); ++i) {
        dot += a[i] * b[i];         // Producto punto
        normA += a[i] * a[i];       // Norma del vector A
        normB += b[i] * b[i];       // Norma del vector B
    }
    if (normA == 0 || normB == 0) return 0.0; // Evita división por cero
    return dot / (std::sqrt(normA) * std::sqrt(normB));
}
