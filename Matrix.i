// Matrix.i - Matrix interface
%module Matrix
%{
#define SWIG_FILE_WITH_INIT
#include "Matrix.h"
%}

%include "typemaps.i"
%include "std_vector.i"

namespace std {
%template(Line) vector<double>;
    %template(Array) vector<vector<double>>;
}


%include "Matrix.h"

extern void setUpLibrary();
extern void tearDownLibrary();
