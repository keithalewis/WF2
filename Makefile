CPPFLAGS = -g

WF2.t: WF2.t.cpp

clean:
	rm -f WF2.t *.o

test: WF2.t
	./WF2.t

WF2.t.cpp: Matrix.h

python:
	mkdir -p build
	(mkdir build; cd build; rm -rf *; cmake ..; make)
