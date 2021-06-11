// -*- coding: utf-8 -*-
/*
Created on Wed Jun  2 10:32:26 2021

@author: Biswajit Jena
*/



#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>

// Get time function for comparing speeds
auto get_time() { return std::chrono::high_resolution_clock::now(); }

int main() {
  // Size of our vector
  const int N = 1 << 15;

  std::vector<int> v(N);

  // Random number generator
  std::mt19937 rng;
  rng.seed(std::random_device()());
  std::uniform_int_distribution<int> dist(0, 255);

  // Generate our random input
  std::generate(begin(v), end(v), [&]() { return dist(rng); });

  // Sort our random input
  auto start = get_time();
  std::sort(begin(v), end(v));
  auto finish = get_time();

  // Execution time for Serial Sort
  auto duration =
      std::chrono::duration_cast<std::chrono::milliseconds>(finish - start);
  std::cout << "Elapsed time = " << duration.count() << " ms\n";

  return 0;
}

/*
We used STL Library to demonstrate the speeds for parallel and serial Sort.
Time for serial Sort - Order of 30ms
Time for Parallelised version of Sort - Order of 6ms
(Uses execution library to achieve this && thread building blocks library in gcc)
*/
