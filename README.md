# Activities

## Dependencies

On Ubuntu

```
$ sudo apt install swig4.0
```

On Windows 11  
Download [swigwin-4.1.2](https://sourceforge.net/projects/swig/files/swigwin/swigwin-4.1.2/swigwin-4.1.2.zip)
and extract to top level directory. 
Set the environment variable `SWIG_ROOT` to the path of the `swigwin-4.1.2` directory. (Thanks Derek!)

## Clone

```
$ git clone https://github.com/keithalewis/WF2  
$ cd WF2
```

To create or update test executable `WF2.t` and python module files `_Matrix.so` and `pyMatrix.py` in `build` direectory:

```
$ mkdir build
$ cd build
$ cmake ..
$ make
```

Or `make python`.

On Linux from the `build` directory  
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

On Windows open WF2 folder in Visual Studio.  
Wait for CMake to configure the project then build.  
Right click on the WF2 project and select `Open in terminal`  
```
PS C:\Users\kal\source\repos\keithalewis\WF2\out\build\x64-Debug> py
Python 3.12.4 (tags/v3.12.4:8e8a4ba, Jun  6 2024, 19:30:16) [MSC v.1940 64 bit (AMD64)] on win32
Type "help", "copyright", "credits" or "license" for more information.
>>> import Debug.pyMatrix as pm
>>> m = pm.Matrix([[1,2,],[3,4]])
>>> print(m+m)
[[2, 4], [6, 8]]
>>> m += m
>>> print(m)
[[2, 4], [6, 8]]
# however
>>> m += m
>>> print(m)
[[2, 4], [6, 8]]
# and
>>> n = m + m
>>> print(n)
[[2, 4], [6, 8]]
```

It seems the [SWIG documentation](https://www.swig.org/Doc1.3/Python.html#Python_nn24)
is not accurate. Perhaps this only works for POD types where shallow copy is sufficient.

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
