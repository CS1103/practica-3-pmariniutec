#include <iostream>
#include <algorithm>
#include <cassert>
#include <deque>

#include "matrix.h"
#include "section.h"

// Ejercicio 2
template<typename T>
std::deque<T> dequeMins(std::deque<T> &d, size_t n) {
  assert(d.size() >= n);
  std::deque<T> ret;  

  for (size_t i = 0; i < ret.size() - n - 1; ++i) {
	auto m = std::min_element(d.begin() + i, d.begin() + i + n);
	ret.emplace_back(*m);
  }

  return ret;
}

int main() {
  // START MATRIX (Ejercicio 1)
  Matrix<int> m1{3, 3};
  Matrix<int> m2{3, 3};
  if(m1.sameSize(m2)) {
	for (size_t i = 0; i < 3; ++i) {
	  for (size_t j = 0; j < 3; ++j) {
		m1[i][j] = i * j;
		m2[i][j] = i + j;
	  }
	}
	auto m3 = m1 + m2;
	m3.print();
  }

  Matrix<float> m4{3, 3};
  Matrix<float> m5{3, 3};
  if(m4.sameSize(m5)) {
	for (size_t i = 0; i < 3; ++i) {
	  for (size_t j = 0; j < 3; ++j) {
		m4[i][j] = i * j / 0.3f;
		m5[i][j] = i + j * 0.47f;
	  }
	}
	auto m6 = m4 + m5;
	m6.print();
  }

  Matrix<float> m7{6, 8};
  Matrix<float> m8{6, 5};
  if(m7.sameSize(m8)) {
	for (size_t i = 0; i < 5; ++i) {
	  for (size_t j = 0; j < 6; ++j) {
		m7[i][j] = i * j / 0.3f;
		m8[i][j] = i + j * 0.47f;
	  }
	}
	auto m9 = m7 + m8;
	m9.print();
  }


  // END MATRIX

  // START DEQUE (Ejercicio 2)
  std::deque<int> d {1, 3, 4, 5, 6, 5};
  auto r = dequeMins<int>(d, 3);
  for (auto &i : r) {
	std::cout << i << ' ';
  }
  std::cout << "\n\n";

  std::deque<int> d2 {2, 3, 5, 7, 34, 56, 7, 7, 2};
  auto r2 = dequeMins<int>(d2, 3);
  for (auto &i : r2) {
	std::cout << i << ' ';
  }
  std::cout << "\n\n";
  // END DEQUE

  // START SECTION
  
  Section section{"data.txt"};

  // END SECTION
}

