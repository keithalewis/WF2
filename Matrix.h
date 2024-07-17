#pragma once
#include <valarray>

namespace WF2 {

	class Matrix {
		std::size_t rows;
		std::size_t columns;
		std::valarray<double> array;
	public:
		Matrix(std::size_t rows = 1, std::size_t columns = 1, double value = 0)
			: rows(rows), columns(columns), array(value, rows*columns))
		{ }
		Matrix(std::size_t rows, std::size_t columns, const double* array)
			: rows(rows), columns(columns), array(array, rows*columns))
		{ }
		/*
		Matrix(const Matrix&) = default;
		Matrix& operator=(const Matrix&) = default;
		Matrix(const Matrix&&) = default;
		Matrix& operator=(const Matrix&&) = default;
		~Matrix() = default;
		*/

		friend class Matrix operator+(const Matrix& b)
		{
			if (rows != b.rows || a.columns != b.a.columns) {
				throw __FUNCTION__ ": rows and columns must be the same";
			}

			a += b.a;

			return Matrix(r, a.size()/r, a);
		}
	};

} // namespace WF2
