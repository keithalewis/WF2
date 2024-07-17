// Matrix.i - Matrix interface
%module Matrix
%{
#define SWIG_FILE_WITH_INIT
#include "Matrix.h"
%}
%include "Matrix.h"

extern void setUpLibrary();
