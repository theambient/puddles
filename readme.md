
Test Assignment for TBricks
===========================

Problem statement
------------------

Consider a matrix of integers MxN, where each value represents a height of imaginary landscape.
Now, the whole figure is put into the water, deep enough to cover the highest peak, and is brought back to the light. Write a program to compute puddles remained in the landscape. Program
should compile and work on Windows and Unix, and must be accompanied with a description and a set of tests to prove its correctness.

Notes
------

Project uses git submodules. After clone do the following

```bash
	git submodule init
	git submodule update
```

Every time you change branch (checkout) don't forget to update submodules.

```bash
	git submodule update
```

Building
---------

Cmake build system is used. Make sure you have cmake installed on you system. For cmake installation instructions got to [http://cmake.org | cmake website].

To build the software do the following from project dir.

```bash
	git submodule init
	git submodule update
	mkdir build
	cd build
	cmake ..
	make
	make test
```
