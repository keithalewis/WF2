# Activities

## Dependencies

On Ubuntu

```
$ sudo apt install swig4.0
```

On Windows 11  
Download [swigwin-4.1.2](https://sourceforge.net/projects/swig/files/swigwin/swigwin-4.1.2/swigwin-4.1.2.zip)
and extract to top level directory.

## Clone

```
$ git clone https://github.com/keithalewis/WF2  
$ cd WF2
```

To create or update `_Matrix.so` and `pyMatrix.py` in `build` direectory:

```
$ mkdir build
$ cd build
$ cmake ..
$ make
```

Or `make python`.

From `build` directory  
```
$ python3
>>> import pyMatrix as My
>>> mat = My.Matrix([[3, 4, 5], [1, 4., 5]])
>>> print(mat)
[[3, 4, 5], [1, 4, 5]]
>>> mat_res = mat + mat
>>> print(mat_res)
[[6, 8, 10], [2, 8, 10]]
```

## Remarks

Guido van Rossum's primary goal when designing Python was to 
create an easy and intuitive language. It was based on
his earlier work on [ABC](https://en.wikipedia.org/wiki/ABC_(programming_language))
which, in turn, was based on [SETL](https://en.wikipedia.org/wiki/SETL)
developed by Jack Schwartz at NYU.

Guido was well aware of the performance trade offs of making
a language easy to use and making it fast. 
The [Python/C API](https://docs.python.org/3/c-api/index.html) makes it
possible to extend the Python interpreter with new modules.  Modules can
not only define new functions but also new object types and their methods.

This proved to be a key to Python's success. Heavy computational tasks
can be offloaded to code written in C, C++, or even Fortran.
Guido made it possible for other people to contribute their skills
to increase the usefulness of Python.
There is now a large ecosystem of easily available Python packages.
Three of the most popular are
[`numpy`](https://numpy.org/), 
for numerical computation,
[`pandas`](https://pandas.pydata.org/),
for data analysis and manipulation,
and the successor to [tensorflow](https://www.tensorflow.org/) [`pytorch`](https://pytorch.org/).

Although the Python/C API makes it possible to fully integrate native code with Python
it is tedious to use and requires expert skills.
In the same spirit as Python, there have been many efforts to make this easier to use.

### `ctypes`

The [`ctypes`](https://docs.python.org/3/library/ctypes.html)
package is now part of the standard Python distribution.
It makes it possible to call C functions in a dynamically linked library directly from Python.
After loading the libray any function can be called from Python
by wrapping its arguments using
[fundamental data type](https://docs.python.org/3/library/ctypes.html#fundamental-data-types)

The basic data type in the Python/C API is
a [`PyObject`](https://docs.python.org/3/c-api/structures.html).
All object types are extensions of this type.
The `ctypes` module provides functions to convert a `PyObject` to
a type a native C type that can be passed to C functions.

### [`nanobind`](https://github.com/wjakob/nanobind)
