# Activities

## build

To create `_Matrix.so` and `pyMatrix.py` in `build` direectory:

```
mkdir build
cd build
cmake ..
make
```

Add full path to `build` directory to `PYTHONPATH`. From `build` directory  
```
export PYTHONPATH=${PYTHONPATH}:$(pwd)
```
Import py Matrix  
```
$ python3
>>> import pyMatrix
>>> pyMatrix.setUpLibrary()
```
