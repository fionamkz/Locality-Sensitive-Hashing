#include "lsh.h"
#include <random>
#include <bitset>
#include <sstream>

// Genera vector con valores aleatorios entre 0 y 1
std::vector<double> generarVectorAleatorio(int dimension) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist(0.0, 1.0);

    std::vector<double> vec(dimension);
    for (int i = 0; i < dimension; ++i)
        vec[i] = dist(gen);
    return vec;
}

// Genera lista de vectores de datos aleatorios
std::vector<std::vector<double>> generarDatosAleatorios(int cantidad, int dimension) {
    std::vector<std::vector<double>> datos;
    for (int i = 0; i < cantidad; ++i)
        datos.push_back(generarVectorAleatorio(dimension));
    return datos;
}

// Genera proyecciones aleatorias con distribución normal
std::vector<std::vector<double>> generarProyeccionesAleatorias(int cantidad, int dimension) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> dist(0.0, 1.0);

    std::vector<std::vector<double>> proyecciones(cantidad, std::vector<double>(dimension));
    for (auto& v : proyecciones)
        for (double& val : v)
            val = dist(gen);
    return proyecciones;
}

// Convierte vector a hash binario usando proyecciones
std::string hashearVector(const std::vector<double>& vec, const std::vector<std::vector<double>>& proyecciones) {
    std::bitset<K> hash;
    for (int i = 0; i < K; ++i) {
        double dp = 0.0;
        for (int j = 0; j < D; ++j)
            dp += vec[j] * proyecciones[i][j];
        hash[i] = (dp >= 0); // Si producto punto es positivo, el bit es 1
    }
    return hash.to_string();
}

// Aplica hashing a todos vectores de datos y agrupa en buckets
std::unordered_map<std::string, std::vector<int>> hashearDatos(const std::vector<std::vector<double>>& datos, const std::vector<std::vector<double>>& proyecciones) {
    std::unordered_map<std::string, std::vector<int>> buckets;
    for (int i = 0; i < (int)datos.size(); ++i) {
        std::string hash = hashearVector(datos[i], proyecciones);
        buckets[hash].push_back(i); // Agrupa índice según hash
    }
    return buckets;
}
