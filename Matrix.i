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
/*
%typemap(in) double matrix[ANY][ANY] (double temp[$1_dim0][$1_dim1]) {
  PyObject *resultobj = 0;
  int arg1 ;
  int arg2 ;
  double *arg3 = (double *) 0 ;
  int val1 ;
  int ecode1 = 0 ;
  int val2 ;
  int ecode2 = 0 ;
  void *argp3 = 0 ;
  int res3 = 0 ;
  WF2::Matrix *result = 0 ;

  if (!PySequence_Check($input)) {
    PyErr_SetString(PyExc_ValueError, "Expected a sequence");
    SWIG_fail;
  }
  if (PySequence_Length($input) != $1_dim0) {
    PyErr_SetString(PyExc_ValueError, "Size mismatch. Expected $1_dim0 elements");
    SWIG_fail;
  }
  // Rectangular array.
  for (Py_ssize_t i = 0; i < $1_dim0; ++i) {
    if (PySequence_Length(PySequence_GetItem($input, i) != $1_dim1) {
      PyErr_SetString(PyExc_ValueError, "Size mismatch. Expected $1_dim1 elements");
      SWIG_fail;
    }
  }

  std::vector<double> array[$1_dim0 * $1_dim1];

  for (Py_ssize_t i = 0; i < $1_dim0; ++i) {
    for (Py_ssize_t j = 0; j < $1_dim1; ++j) {
        PyObject* oi = PySequence_GetItem($input, i);
        PyObject* oij = PySequence_GetItem(oi, j);
        if (PyNumber_Check(oij)) {
            array[i*$1_dim1 + j] = PyFloat_AsDouble(o);
    } else {
      PyErr_SetString(PyExc_ValueError, "Sequence elements must be numbers");
      SWIG_fail;
    }
  }

  result = (WF2::Matrix *)new WF2::Matrix($1_dim0,$1_dim1,array.data());
  resultobj = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_WF2__Matrix, SWIG_POINTER_NEW |  0 );
  return resultobj;
fail:
  return NULL;
}
*/