#pragma once
#include <cassert>
#include <fstream>
#include <sstream>
#include <iostream>
#include <span>
#include <string>
#include <valarray>

extern "C" {
    inline void setUpLibrary()
    {
        puts("setUpLibrary");
    }
    inline void tearDownLibrary()
    {
        puts("tearDownLibrary");
    }
}

namespace WF2 {

	struct Matrix {
		int rows;
		int columns;
		std::valarray<double> array;

		Matrix(int rows = 1, int columns = 1, double value = 0)
			: rows(rows), columns(columns), array(value, rows*columns)
		{ }
		// Construct from array of doubles.
		// Assumes array points at rows * columns doubles
		Matrix(int rows, int columns, double* array)
			: rows(rows), columns(columns), array(array, rows*columns)
		{ }
		// Read from parameter file.
		explicit Matrix(const char* path)
		{
			int rows, columns;
			double value;

			std::ifstream ifs(path);
			assert (ifs.is_open());
			assert(ifs >> rows >> columns >> value);
            ifs.close();

			operator=(Matrix(rows, columns, value));
		}

		Matrix& operator+=(const Matrix& b)
		{
			assert (rows == b.rows && columns == b.columns);

			array += b.array;

			return *this;
		}
		
		Matrix operator+(const Matrix& b)
		{
			return operator+=(b);
		}
        std::string to_string() const
        {
            std::ostringstream oss;

            oss << "[";
            auto commai = "";
            for (int i = 0; i < rows; ++i) {
              oss << commai << "[";
              commai = ", ";
              auto commaj = "";
              for (int j = 0; j < columns; ++j) {
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
