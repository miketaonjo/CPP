# Project name : CPP Module 02

The third module of the 42 c++ piscine explores the concepts of ad-hoc polymorphism, operator overloading and the Orthodox Canonical class form.

## Ex00 - Fixed Class
Because floating point types lack accuracy and can be slow, we must implement a new class for Fixed point numbers. This exercise is an introduction to the Orthodox Canonical form, in which a class should have a default constructor, a copy constructor, a destructor and an assignment operator overload.

### Usage

In order to compile : `make`

Execution :

```
./Fixed
```

The output shows the sequence of calls to constructors, destructors, assignment operators and getters.

## Ex01 - A More Useful Fixed Class
This exercise builds on the previous one. Now we must add an output stream overload to the class, as well as new constructors from int and float and member functions able to translate a Fixed number into an integer or a float.

### Usage

In order to compile : `make`

Execution :

```
./Fixed
```

## Ex02 - Overload Madness
The third exercise, again, builds on the previous one. Now we must implement overloads for all operators (comparison < > <= >= == !=, binary + - * /, unary prefix++ ++postfix prefix-- postfix--) as well as regular and const versions of functions that return the largest or smallest of two fixed numbers.

### Usage

In order to compile : `make`

Execution :

```
./Fixed
```
