# 🔍 Locality Sensitive Hashing (LSH) in C++

This project implements **Locality Sensitive Hashing (LSH)** in C++ to perform approximate similarity searches on data vectors.

---

## 📌 What does it do?

- Generates random data vectors.  
- Creates random projections to compute hashes.  
- Groups vectors into buckets according to their hash.  
- Generates a random query vector and finds matches in its bucket.  
- Calculates the **cosine similarity** between the query and candidate vectors.  

---

## 🗂️ Project Structure

- `main.cpp` — Main orchestrator.  
- `lsh.cpp/.h` — Hashing and projection logic.  
- `utils.cpp/.h` — Helper functions (printing, cosine similarity).  
