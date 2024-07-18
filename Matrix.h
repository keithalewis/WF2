#pragma once
#include <cassert>
#include <fstream>
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

	class Matrix {
		int rows;
		int columns;
		std::valarray<double> array;
	public:
		Matrix(int rows = 1, int columns = 1, double value = 0)
			: rows(rows), columns(columns), array(value, rows*columns)
		{ }
		// Construct from array of doubles.
		// Assumes array points at rows * columns doubles
		Matrix(int rows, int columns, const double* array)
			: rows(rows), columns(columns), array(array, rows*columns)
		{ }
		// Read from parameter file.
		/*
		Matrix(const char* path = "./Matrix.params")
		{
			int rows, columns;
			double value;

			std::ifstream ifs(path);
			if (ifs.is_open()) {
				assert(ifs >> rows >> columns >> value);
			}
			Matrix(rows, columns, value);
		}
		*/
		/*
		Matrix(const Matrix&) = default;
		Matrix& operator=(const Matrix&) = default;
		Matrix(const Matrix&&) = default;
		Matrix& operator=(const Matrix&&) = default;
		~Matrix() = default;
		*/

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
	};

} // namespace WF2

