
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

Usage
------

After build completes you've got an executable `puddles`.
It's usage is simple: `puddles <file.in> <file.out>`

Upon success tool return zero.

`<file.in>` a file of following structure:

```
<height> <width>
<2D-array of non-negative numbers>
```

sample:

```
4 4
0 2 1 0
2 2 2 0
2 0 1 2
2 2 2 1
```

As a result you get `<file.out>` as follows

```
0000
0000
0##0
0000
```

where `#` denotes places of puddles.

Algorithm
----------

The algo is very simple. At every point we try to find a path to the edge using a kind of floodfill algorithm to see can we leak from that point or not.

The barrier for floodfill algorithm is a point with a height greater or equal then starting point value.

4-connectivity is assumed when finding barieirs.

