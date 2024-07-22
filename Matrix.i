// Matrix.i - Matrix interface
%module Matrix
%{
#define SWIG_FILE_WITH_INIT
#include "Matrix.h"
%}

%include "std_vector.i"

namespace std {
%template(List) vector<double>;
    %template(Array) vector<vector<double>>;
}

%rename(assign) WF2::Matrix::operator=;
%include "Matrix.h"
