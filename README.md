# Activities

## build

### Dependencies

On Ubuntu

```
$ sudo apt install swig4.0
$ sudo apt install python3-numpy
```

To create `_Matrix.so` and `pyMatrix.py` in `build` direectory:

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
>>> import pyMatrix as pm
>>> m = pm.Matrix(2,3,4)
>>> print(m)
[[4, 4, 4], [4, 4, 4]]
```

## Remarks

Guido van Rossum's primariy goal when designing Python was to 
create an easy and intuitive language. It was based on
his earier work on [ABC](https://en.wikipedia.org/wiki/ABC_(programming_language))
which, in turn, was based on [SETL](https://en.wikipedia.org/wiki/SETL)
developed by Jack Schwartz at NYU.

Guido was well aware of the perfomance tradeoffs of making
a language easy to use and making it fast. 
His [Python/C API](https://docs.python.org/3/c-api/index.html) makes it
possible to extend the Python interpreter with new modules.  Modules can
not only define new functions but also new object types and their methods.

This proved to be a key to Python's success. Heavy computational tasks
can be offloaded to code written in C, C++, or even Fortran.
Guido made it possible for other people to contribute their skills
to increase the usefulness of Python.
There is now a large ecosystem of easily available Python packages.
For numerical computation ([`numpy`](https://numpy.org/)), 
for data analysis and manipulation ([`pandas`])(https://pandas.pydata.org/),
and the succesor to [tensorflow](https://www.tensorflow.org/) ([`pytorch`](https://pytorch.org/)).

Although the Python/C API makes it possible to fully integrate native code with Python,
it is tedious to use and requires expert skills.
In the same spirit as Python, there have been many efforts to make this easier to use
but they all ultimately rely on this.




