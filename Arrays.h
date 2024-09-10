// Hiram Romero
// Assignment 1
// Arrays.cpp

#ifndef ARRAYS_H
#define ARRAYS_H

// Struct to hold the result of modifying a value
struct ModifyIndex {
    int oldValue;  // The old value before modification
    int newValue;  // The new value after modification
};

// Function used to find the index of a number in the array
int LocateIndex(const int array[], int size, int number);

// Function that modifies the value at an index and returns the values
ModifyIndex modifyValue(int array[], int size, int index, int newValue);

// Function that prints arrays
void printArray(const int array[], int size);

// Function that adds a new integer to the end of the array
bool addNewInt(int array[], int& size, int newValue, int maxSize);

// Function that replaces a value at a specific index with 0 or remove it
bool RemoveReplaceIndex(int array[], int& size, int index, bool remove);

#endif
