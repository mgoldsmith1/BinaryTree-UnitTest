![screenshot](https://travis-ci.org/mgoldsmith1/BinaryTree-UnitTest.svg?branch=master)
# BinaryTree-UnitTest

Finds the Max Distinct Path of a Binary tree from root to leaf.

## Unit Testing
This project uses the Google C++ Test framework

## Instructions
From the BinaryTree-UnitTest directory:

Build:
```bash
$./build.sh
```
```bash
rm -f unittest gtest.a gtest_main.a *.o
make: *** No rule to make target `make'.  Stop.
c++ -isystem ../include -g -Wall -Wextra -pthread -c ../src/binTreePath.cc
c++ -isystem ../include -g -Wall -Wextra -pthread -c ../src/unittest.cc
c++ -isystem ../include -I.. -g -Wall -Wextra -pthread -c \
            ../dependencies/gtest-all.cc
c++ -isystem ../include -I.. -g -Wall -Wextra -pthread -c \
            ../dependencies/gtest_main.cc
ar rv gtest_main.a gtest-all.o gtest_main.o
ar: creating archive gtest_main.a
a - gtest-all.o
a - gtest_main.o
c++ -isystem ../include -g -Wall -Wextra -pthread -lpthread binTreePath.o unittest.o gtest_main.a -o unittest
```
Run:
```bash
$./run.sh
```
```bash
Running...
[==========] Running 2 tests from 2 test cases.
[----------] Global test environment set-up.
[----------] 1 test from BinartTreeTest
[ RUN      ] BinartTreeTest.Trivial

Given an input: 1 2 3 4 5 6 7 8 9 10 11 12 

Max Distinct Path from Root to Leaf is: 4
[       OK ] BinartTreeTest.Trivial (0 ms)
[----------] 1 test from BinartTreeTest (0 ms total)

[----------] 1 test from CodilityBinaryTree
[ RUN      ] CodilityBinaryTree.Trivial

Given an input: 5 6 4 1 6 5 1 

Max Distinct Path from Root to Leaf is: 3
[       OK ] CodilityBinaryTree.Trivial (0 ms)
[----------] 1 test from CodilityBinaryTree (0 ms total)

[----------] Global test environment tear-down
[==========] 2 tests from 2 test cases ran. (0 ms total)
[  PASSED  ] 2 tests.
Complete.
```
Clean:
```bash
$./clean.sh
```
```bash
rm -f unittest gtest.a gtest_main.a *.o
make: *** No rule to make target `make'.  Stop.
```
## Project Modification
To modify the project. Navigate to the src folder. 
