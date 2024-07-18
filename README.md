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
mkdir build
cd build
cmake ..
make
```

Add full path to `build` directory to `PYTHONPATH`. From `build` directory  
```
export PYTHONPATH=${PYTHONPATH}:$(pwd)
```

Import pyMatrix  
```
$ python3
>>> import pyMatrix
>>> pyMatrix.setUpLibrary()
```
