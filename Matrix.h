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
		std::size_t rows;
		std::size_t columns;
		std::valarray<double> array;
	public:
		Matrix(std::size_t rows = 1, std::size_t columns = 1, double value = 0)
			: rows(rows), columns(columns), array(value, rows*columns)
		{ }
		// Construct from array of doubles.
		// Assumes array points at rows * columns doubles
		Matrix(std::size_t rows, std::size_t columns, const double* array)
			: rows(rows), columns(columns), array(array, rows*columns)
		{ }
		// "[[1,2,3],[4,5,6]]" -> Matrix(2, 3, {1,2,3,4,5,6})
        /*
		Matrix(const char* path = "./Matrix.params")
		{
			size_t r = 0, c = 0; // rows, columns
			std::ifstream matrix(path);
			if (matrix.is_open()) {
			}
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

