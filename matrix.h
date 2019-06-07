#include <vector>
#include <cassert>
#include <iostream>

template<typename T>
class Matrix {
  public:
	// allocate space in vectors to avoid resizing
	Matrix(size_t w, size_t h) : n{w}, m{h} {
	  values.resize(m);
	  for (size_t i = 0; i < m; ++i) {
		values[i].resize(n);
	  }
	}

	const std::vector<T> &operator[](size_t row_index) const {
	  return values[row_index];
	}

	std::vector<T> &operator[](size_t row_index) {
	  return values[row_index];
	}

	bool sameSize(Matrix &rhs) {
	  return n == rhs.getN() && m == rhs.getM();
	}

	// returns by value
	Matrix<T> operator+(Matrix &rhs) {
	  Matrix<T> ret{m, n};

	  for (size_t i = 0; i < m; ++i) {
		for (size_t j = 0; j < n; ++j) {
		  ret[i][j] = values[i][j] + rhs[i][j];	  
		}
	  }

	  return ret;
	}

	void print() const {
	  for (int i = 0; i < m; ++i) {
	    for (int j = 0; j < n; ++j) {
		  std::cout << values[i][j] << ' ';
	    }
		std::cout << '\n';
	  }
	  std::cout << '\n';
	}

	size_t getN()  const { return n; }
	size_t getM() const { return m; }

  private:
	std::vector<std::vector<T>> values;
	size_t n;
	size_t m;
};
