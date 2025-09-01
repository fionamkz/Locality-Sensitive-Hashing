#pragma once
#include <vector>
#include <string>
#include <unordered_map>

// un vector en consola
void imprimirVector(const std::vector<double>& v);

// todos los vectores
void imprimirVectores(const std::vector<std::vector<double>>& datos);

// buckets LSH
void imprimirBuckets(const std::unordered_map<std::string, std::vector<int>>& buckets);

// Calcula similitud coseno entre dos vectores
double similitudCoseno(const std::vector<double>& a, const std::vector<double>& b);
