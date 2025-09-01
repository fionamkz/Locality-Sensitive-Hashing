# 🔍 Locality Sensitive Hashing (LSH) en C++

Este proyecto implementa **LSH (Locality Sensitive Hashing)** en C++ para realizar búsquedas aproximadas de similitud en vectores de datos.

## ¿Qué hace?

- Genera vectores de datos aleatorios.
- Crea proyecciones aleatorias para calcular hashes.
- Agrupa los vectores en buckets según su hash.
- Genera un vector query aleatorio y encuentra coincidencias en su bucket.
- Calcula la **similitud coseno** entre el query y los vectores candidatos.

## Estructura

- `main.cpp` — Orquestador principal.
- `lsh.cpp/.h` — Lógica de hashing y proyección.
- `utils.cpp/.h` — Funciones auxiliares (impresión, distancia coseno).
