// Hiram Romero
// Assignment 1
// Arrays.cpp

#include "Arrays.h"  // Includes the header file
#include <iostream>  // input/output streams
#include <stdexcept> // For standard exception classes

using namespace std;

// Function to find the index of a number in the array
int LocateIndex(const int array[], int size, int number) {
    for (int i = 0; i < size; i++) {  // Loops through the array
        if (array[i] == number) {  // Checks if the current element matches the number
            return i;  // if number found, return the index
        }
    }
    return -1;  // If number not found, return -1
}

// The function to modify the value at a specific index and return old and new values
ModifyIndex modifyValue(int array[], int size, int index, int newValue) {
    ModifyIndex result;  // Creates ModifyIndex object to store the result
    if (index >= 0 && index < size) {  // Checksthe index is within bounds
        result.oldValue = array[index];  // Stores  old value
        array[index] = newValue;  // Updates value at the specified index
        result.newValue = newValue;  // Stores  new value
    } else {
        // if index out of bounds, set old and new values to -1 to indicate error
        result.oldValue = -1;
        result.newValue = -1;
    }
    return result;  // Return the result
}

// Function to print the array
void printArray(const int array[], int size) {
    for (int i = 0; i < size; i++) {  // Loop through the array
        cout << array[i] << " ";  // Print the current element
        if ((i + 1) % 10 == 0) cout << endl;  // Print a newline every 10 elements for better readability
    }
    cout << endl;  // Print a newline at the end of the array
}

// Function to add a new integer to the end of the array
bool addNewInt(int array[], int& size, int newValue, int maxSize) {
    if (size >= maxSize) {  // Check if the array has reached its maximum size
        return false;  // returns false if array full
    }
    array[size++] = newValue;  // Adds the new integer to the array and increment size
    return true;  // Returns true if successful
}

// Function to replace a value at a specific index with 0 or remove it
bool RemoveReplaceIndex(int array[], int& size, int index, bool remove) {
    if (index < 0 || index >= size) {  // Check if the index is out of bounds
        return false;  // false if index out of bounds
    }

    if (remove) {
        // Shifts elements left to fill the gap created by removal
        for (int i = index; i < size - 1; i++) {
            array[i] = array[i + 1];  // Move each element one position to the left
        }
        size--;  // Decrements size after removing the element
    } else {
        array[index] = 0;  // Replace the value at the index with 0
    }
    return true;  // Return true to indicate successful replacement or removal
}

