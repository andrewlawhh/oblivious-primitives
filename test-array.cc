#include "obl_primitives.h"
#include <chrono>
#include <algorithm>
#include <iostream>

using namespace std::chrono;

size_t N = 10000;
size_t iters = N / 100;
size_t k = rand() % N;

void time_normal() {
    int A[N];
    for (int i = 0; i < N; i++) {
        A[i] = i;
    }

    int x;
    auto start = high_resolution_clock::now();
    for (int i = 0; i < iters; i++) {
        x = A[k]; 
        printf("");
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << "Time taken by normal access: "
        << duration.count() << " microseconds" << " | " << x << std::endl; 
}

void time_oblivious() {
    int B[N];
    for (int i = 0; i < N; i++) {
        B[i] = i;
    }
    int y;
    auto start = high_resolution_clock::now();
    for (int i = 0; i < iters; i++)
        y = ObliviousArrayAccess(B, k, N);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << "Time taken by oblivious access: "
        << duration.count() << " microseconds" << " | " << y << std::endl; 
    if (B[k] != y) {
        printf("result of oblivious incorrect..\n");
    }
}

void time_simd() {
    int B[N];
    // Generate Random values 
    for (int i = 0; i < N; i++) {
        B[i] = i;
    }
    int y;
    auto start = high_resolution_clock::now();
    for (int i = 0; i < iters; i++)
        y = ObliviousArrayAccessSimd(B, k, N);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << "Time taken by simd access: "
        << duration.count() << " microseconds" << " | " << y << std::endl; 
    if (B[k] != y) {
        printf("result of simd incorrect..\n");
    }
}
void time_simd_float() {
  float B[N];
  // Generate Random values 
  for (int i = 0; i < N; i++) {
    B[i] = i + 0.5;
  }
  float y;
  auto start = high_resolution_clock::now();
  for (int i = 0; i < iters; i++)
    y = ObliviousArrayAccessSimd(B, k, N);
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  printf("Time taken by simd access: %d microseconds | %f \n", duration.count(), y);
  if (B[k] != y) {
    printf("result of simd incorrect..\n");
  }
}
int main() {
    time_normal();
    time_oblivious();
    time_simd();
    time_simd_float();
}
