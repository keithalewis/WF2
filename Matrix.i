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

%include "Matrix.h"
%apply (int DIM1, int DIM2, double* IN_ARRAY2) {(int r, int c, double* a)};

extern void setUpLibrary();
extern void tearDownLibrary();

