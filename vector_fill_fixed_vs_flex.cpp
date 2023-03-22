// Example program
#include <chrono>
#include <iostream>
#include <string>
#include <vector>

// build and run
// g++ vector_fill_fixed_vs_flex.cpp -o vector_fill_fixed_vs_flex &&
// ./vector_fill_fixed_vs_flex

void fill_fixed_vector() {
  std::vector<int> vec_fixed(1e5);
  std::cout << "fill vector fixed by index\n";
  for (int i = 0; i < vec_fixed.size(); ++i) {
    vec_fixed[i] = i;
  }
}

void fill_flex_vector() {
  std::vector<int> vec_flex;
  std::cout << "fill vector flex size by index\n";
  for (int i = 0; i < 1e5; ++i) {
    vec_flex.push_back(i);
  }
}

int main() {
  using std::chrono::duration;
  using std::chrono::duration_cast;
  using std::chrono::high_resolution_clock;
  using std::chrono::milliseconds;

  auto fixed_begin = high_resolution_clock::now();
  fill_fixed_vector();
  auto fixed_end = high_resolution_clock::now();
  //   std::cout << fixed_begin << std::endl;

  auto flex_begin = high_resolution_clock::now();
  fill_flex_vector();
  auto flex_end = high_resolution_clock::now();

  auto duration_flex = flex_end - flex_begin;
  auto duration_fixed = fixed_end - fixed_begin;

  std::cout << "duration fixed:\t" << duration_fixed.count() << std::endl;
  std::cout << "duration flex:\t" << duration_flex.count() << std::endl;

  std::string faster_method = duration_fixed.count() < duration_flex.count()
                                  ? "fixed sized vector"
                                  : "flexbile sized vector";

  std::cout << "The faster Method is: " << faster_method << std::endl;
}
