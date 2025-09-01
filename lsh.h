#pragma once
#include <vector>
#include <unordered_map>
#include <string>

const int N = 8;   // Número de vectores de datos
const int D = 6;   // Dimensión de cada vector
const int K = 8;   // Número de proyecciones aleatorias

// vector aleatorio (valores entre 0 y 1)
std::vector<double> generarVectorAleatorio(int dimension);

// N vectores de datos aleatorios
std::vector<std::vector<double>> generarDatosAleatorios(int cantidad, int dimension);

// K vectores de proyección aleatorios (con distribución normal)
std::vector<std::vector<double>> generarProyeccionesAleatorias(int cantidad, int dimension);

// Hashea vector según proyecciones
std::string hashearVector(const std::vector<double>& vec, const std::vector<std::vector<double>>& proyecciones);

// Hashea todos los datos y mete en buckets
std::unordered_map<std::string, std::vector<int>> hashearDatos(const std::vector<std::vector<double>>& datos, const std::vector<std::vector<double>>& proyecciones);
