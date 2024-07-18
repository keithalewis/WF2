// Matrix.i - Matrix interface
%module Matrix
%{
#define SWIG_FILE_WITH_INIT
#include "Matrix.h"
%}

%include "typemaps.i"
%include "numpy.i"
%init %{
import_array();
%}

%apply (double* IN_ARRAY2, int DIM1, int DIM2) {(double* a, int r, int c)};
%include "Matrix.h"

extern void setUpLibrary();
extern void tearDownLibrary();

