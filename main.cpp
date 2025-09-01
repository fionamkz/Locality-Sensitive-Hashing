// LSH Implementation in C++
// Project: Locality Sensitive Hashing for Similarity Search

#include <iostream>
#include "lsh.h"
#include "utils.h"

int main() {
    std::cout << "Locality Sensitive Hashing (LSH)\n";

    // Generar datos aleatorios
    std::vector<std::vector<double>> data = generarDatosAleatorios(N, D);

    // Mostrar vectores generados
    std::cout << "\nVectores generados:\n";
    imprimirVectores(data);

    // Crear proyecciones aleatorias
    std::vector<std::vector<double>> proyecciones = generarProyeccionesAleatorias(K, D);

    // Crear los buckets LSH
    std::unordered_map<std::string, std::vector<int>> buckets = hashearDatos(data, proyecciones);

    std::cout << "\nBuckets generados\n";
    imprimirBuckets(buckets);

    // Generar query aleatorio
    std::vector<double> query = generarVectorAleatorio(D);
    std::string hashQuery = hashearVector(query, proyecciones);

    std::cout << "\nQuery generado: ";
    imprimirVector(query);
    std::cout << "Hash del query: " << hashQuery << "\n";

    // Buscar candidatos
    if (buckets.count(hashQuery)) {
        std::vector<int> candidatos = buckets[hashQuery];

        std::cout << "\nCandidatos en el mismo bucket:\n";
        double maxSim = -1;
        int mejorIndice = -1;
        for (int idx : candidatos) {
            double sim = similitudCoseno(query, data[idx]);
            std::cout << "Índice " << idx << "Similitud: " << sim << "\n";
            if (sim > maxSim) {
                maxSim = sim;
                mejorIndice = idx;
            }
        }

        std::cout << "\nEl vector más similar al query es el índice " << mejorIndice 
                  << " con similitud " << maxSim << "\n";
    } else {
        std::cout << "No se encontraron coincidencias en el bucket del query.\n";
    }

    return 0;
}
