// Matrix.i - Matrix interface
%module Matrix

%begin %{
#define SWIG_FILE_WITH_INIT
// use release Python interpreter (and C runtime by extension)
#ifdef _MSC_VER
#define SWIG_PYTHON_INTERPRETER_NO_DEBUG
#endif  // _MSC_VER
#include "Matrix.h"
%}

%include "std_vector.i"

namespace std {
%template(List) vector<double>;
    %template(Array) vector<vector<double>>;
}

%rename(assign) WF2::Matrix::operator=;
%include "Matrix.h"
/*
%extend WF2::Matrix {
    WF2::Matrix __add__(const WF2::Matrix& b) {
         WF2::Matrix a(*self);

         return a + b;
    }
}
*/
