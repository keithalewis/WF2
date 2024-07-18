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
