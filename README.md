# Activities

## Dependencies

On Ubuntu

```
$ sudo apt install swig4.0
```

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
