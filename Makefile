CPPFLAGS = -g

WF2.t: WF2.t.cpp

clean:
	rm -f WF2.t

test: WF2.t
	./WF2.t

python:
	rm -rf build
	(mkdir build; cd build; cmake ..; make)
