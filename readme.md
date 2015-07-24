
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

Cmake build system is used. Make sure you have cmake installed on you system. For cmake installation instructions go to [cmake website](http://cmake.org).

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
0 0 0 0
0 0 0 0
0 2 1 0
0 0 0 0
```

where number denotes deepness of puddle at every point. 0 means no puddle.

Algorithm
----------

Not very efficient algo. We try to gradually pour water onto the landscape and see which parts are filled (below the watermark) and are not connected to the edge. Those parts are puddles with known deepness. The edge - those parts which are leaking outside the landscape is remembered and not considered in further determination of puddles.

At every given watermark puddles are searched by floodfill algorithm. If floodfill algo reached outsize of landscape (coords: 0 and MAX_X, MAX_Y) then this is leaking edge.

4-connectivity is assumed when finding barieirs.

Complexity of the algo is estimated as O(n^4).
