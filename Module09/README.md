# Project name : CPP Module 01

In this series of c++ exercises, we learn about containers such as map, stack, list, vector or deque.Once a container is used, it will not be usable for the rest of this module.

## Ex00 - Bitcoin Exchange
The first exercise is about outputs the value of a certain amount of bitcoin on a certain date. It takes a database in csv format which will represent bitcoin price over time. We must use as input a second database, storing the different prices/dates to evaluate.

### Usage

In order to compile : `make`

Execution :

```
./btc input.txt
```

## Ex01 - Reverse Polish Notation
The second exercice is a program which must take an inverted Polish mathematical expression as an argument with numbers between 0 and 9 and outputs the correct result on the standard output

### Usage

In order to compile : `make`

Execution :

```
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
```

## Ex02 - PmergeMe
The third exercise is about sorting a positive integer sequence taken as argument. We must use at least two different containers and use a merge-insert sort algorithm.

### Usage

In order to compile : `make`

Execution :

```
./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`
```
The output must respect those following guidelines :

• On the first line you must display an explicit text followed by the unsorted positive
integer sequence.
• On the second line you must display an explicit text followed by the sorted positive
integer sequence.
• On the third line you must display an explicit text indicating the time used by
your algorithm by specifying the first container used to sort the positive integer
sequence.
• On the last line you must display an explicit text indicating the time used by
your algorit
