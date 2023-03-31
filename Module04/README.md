# Project name : CPP Module 04

This module of 42 school's C++ piscine explores issues of class inheritance, subtype polymorphism, abstract classes, and interfaces.

## Ex00 - Animals
In the first exercise, we must implement a simple class, Animal, and its two derived classes, Dog and Cat. All classes have their own makeSound function which displays a different message depending on the animal. We must manipulate cats and dogs through pointers of their parent class, Animal, and ensure that the sounds they make are appropriate to their type. 

### Usage

In order to compile : `make`

Execution :

```
./Animals
```
The output shows the results of a functionality test.

## Ex01 - Animals with brains
The second exercise builds on the first by implementing another class, Brain. Cat and Dog instances will have a Brain which can contain up to 100 ideas. Copies of Dogs and Cats musn't be shallow, and there should be no memory leaks. 

### Usage

In order to compile : `make`

Execution :

```
./Animals
```

## Ex02 - Abstract animals
The third exercise introduces us to the concept of abstract classes. The Animal base class should no longer be instantiable.

### Usage

In order to compile : `make`

Execution :

```
./Animals
```

## Ex03 - Materias
The fourth and last exercise in the series requires the implementation of pure abstract classes: interfaces. The Character class is implemented according to the ICharacter interface. A character has an inventory of up to 4 materia which can be equipped, unequipped or used. A materia can be one of two types: ice or cure. Materias are created with a MateriaSource class which implements the IMateriaSource interface.

### Usage

In order to compile : `make`

Execution :

```
./Amateria
```
