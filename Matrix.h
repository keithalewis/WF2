#pragma once
#include <cassert>
#include <fstream>
#include <sstream>
#include <iostream>
#include <span>
#include <string>
#include <valarray>
#include <vector>

extern "C" {

	// To be called in %init %{ ... }%
    inline void setUpLibrary()
    {
    }
	// Don't know where this should go.
    inline void tearDownLibrary()
    {
    }
}

namespace WF2 {

	class Matrix {
		size_t rows;
		size_t columns;
		std::valarray<double> array;
    public:
		Matrix(size_t rows = 1, size_t columns = 1, double value = 0)
			: rows(rows), columns(columns), array(value, rows*columns)
		{ }
        Matrix(const Matrix& m) = default;
        Matrix& operator=(const Matrix& m)
		{
			if (this != &m) {
				rows = m.rows;
				columns = m.columns;
				array = m.array;
			}

			return *this;
		}
        ~Matrix() = default;

		// Construct from array of doubles.
		// Assumes array points at rows * columns doubles
		Matrix(size_t rows, size_t columns, const double* array)
			: rows(rows), columns(columns), array(array, rows*columns)
		{ }
        // Construct from ragged vector SWIG knows about.
		// Not memory efficient.
        Matrix(const std::vector<std::vector<double>>& vv)
        {
            size_t r = vv.size();
            size_t c = r > 0 ? vv[0].size() : 0;
            if (r*c == 0) {
                throw "Matrix: size must be positive";
            }

            // Flatten ragged vector.
            std::vector<double> v = vv[0];
            for (size_t i = 1; i < r; ++i) {
                if (vv[i].size() != c) {
                    throw "Matrix: all rows must be the same size";
                }
                v.insert(v.end(), vv[i].begin(), vv[i].end());
            }

            operator=(Matrix(r, c, v.data()));

        }
		// Read from parameter file.
		explicit Matrix(const char* path)
		{
			size_t rows, columns;
			double value;

			std::ifstream ifs(path);
			assert (ifs.is_open());
			assert (ifs >> rows >> columns >> value);
            ifs.close();

			operator=(Matrix(rows, columns, value));
		}

		Matrix& operator+=(const Matrix& b)
		{
			assert (rows == b.rows && columns == b.columns);

			array += b.array;

			return *this;
		}
		Matrix operator+(const Matrix& b) const
		{
			Matrix c(*this);
			c += b;

			return c;
		}

        std::string to_string() const
        {
            std::ostringstream oss;

            oss << "[";
            auto commai = "";
            for (size_t i = 0; i < rows; ++i) {
              oss << commai << "[";
              commai = ", ";
              auto commaj = "";
              for (size_t j = 0; j < columns; ++j) {
                oss << commaj << array[i * columns + j];
                commaj = ", ";
              }
              oss << "]";
            }
            oss << "]";

            return oss.str();
        }
#ifdef SWIG
        %extend {
          const char *__str__() {
            static std::string s = self->to_string();;

            return s.c_str();
          }
        }
#endif // SWIG

	};

} // namespace WF2

#ifndef SWIG
std::ostream& operator<<(std::ostream& os, const WF2::Matrix& m)
{
    os << m.to_string();

    return os;
}
#endif // SWIG
