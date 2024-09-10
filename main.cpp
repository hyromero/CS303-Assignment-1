// Hiram Romero
// Assignment 1
// Main.cpp

#include <iostream>  // input/ output streams
#include <fstream>   // used for file handling
#include <sstream>   // string stream operations
#include <limits>    // numeric limits, e.g., clearing input
#include <stdexcept> // standard exception classes
#include "Arrays.h"  // Array file that has declarations

#define MAX_LINES 1000  // Maximum number of lines to read from the file set to 1000
#define MAX_NUMBERS (MAX_LINES * 10)  // Maximum number of integers to store, assuming up to 10 ints per line

using namespace std; // for cin and cout purposes

int main() {
    string filename;  // To store the filename input by the user
    ifstream file;    // Input file stream for reading the file
    int numbers[MAX_NUMBERS];  // Array to store integers read from the file
    int numCount = 0;  // Counter for the number of integers stored in the array

    // This loop to repeatedly ask for the filename until a valid file is opened
    while (true) {
        cout << "Enter Filename: ";  // Ask user for the filename
        cin >> filename;      // Read the filename from user input

        file.open(filename);  // Try to open the file with the user input

        if (!file.is_open()) {  // This checks if the user input file opens
            cout << "Unable to open file. Please try again." << endl;  // Error message if unable to open
        } else {
            break;  // Break exits the loop if the file was opened successfully
        }
    }

    string line;  // Stores each line read from the file
    int number;   // Stores each number read from the file

    // This reads files lines and stores numbers in the array
    try {
        while (getline(file, line)) {  // Reads each line from the file
            istringstream iss(line);  // Creates a string stream for reading the line
            while (iss >> number) {   // Takes numbers from line
                if (numCount >= MAX_NUMBERS) {  // Checks if array has reach max_numbers ( its capacity)
                    throw overflow_error("Array is full.");  // Throw an overflow error if the array is full
                }
                numbers[numCount++] = number;  // Stores the number in the array and then it increments the count
            }
        }
    } catch (const overflow_error& e) {  // This catch  is for the overflow errors
        cout << e.what() << endl;  // Displays the error message when needed
    }

    file.close();  // Closes the file after reading

    // Begin to output numbers
    cout << "Original array:" << endl;
    printArray(numbers, numCount);  // Displays original array

    // Searches for the number entered
    int searchNum;  // Variable to store the number to search for
    cout << "Enter a number: ";  // Prompt user to enter the number to search
    cin >> searchNum;  // input for searchNum

    int index;  // stores the index of the found number
    try {
        index = LocateIndex(numbers, numCount, searchNum);  // Searches for the number in the array
        if (index != -1) {  // Checks if number was found in index
            cout << "Number " << searchNum << " found at index " << index << "." << endl;  // Display the index if found
        } else {
            cout << "Number " << searchNum << " not found." << endl;  // Display if the index was not found
        }
    } catch (const out_of_range& e) {  // Catch for numbers out of range
        cout << e.what() << endl;  // Displays the error message
    }

    // This modifies a value at a specific index
    int modifyIndex, newValue;  // Variables to store the index and new value for users input
    while (true) {
        try {
            cout << "Enter index to modify: ";  // This prompts the user to enter a desired index they want modified
            cin >> modifyIndex;  // Reads user input

            if (cin.fail()) {  // Check if input was valid/invalid
                throw invalid_argument("Error. Invalid index. Please enter a valid number.");  // Throw an error
            }

            cout << "Enter new value: ";
            cin >> newValue;  // Reads the new value from user input

            if (cin.fail()) {  // Check if input was valid/invalid
                throw invalid_argument("Error. Invalid value input. Please enter a valid number.");  //throws error message
            }

            ModifyIndex result = modifyValue(numbers, numCount, modifyIndex, newValue);  // Modifies the value at specific index
            if (result.oldValue != -1) {  // Checks if change/modification worked
                cout << "Value at index " << modifyIndex << " changed from " << result.oldValue << " to " << result.newValue << "." << endl;  // Display the new result
                break;  // Exits the loop if everything was successful
            } else {
                cout << "Error. Index " << modifyIndex << " is out of bounds. Please enter a valid index." << endl;  // Outputs error message.
            }
        } catch (const invalid_argument& e) {  // This catches the  invalid argument errors
            cin.clear();  // Clear the error flag on cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard and deletes invalid input
            cout << e.what() << endl;  // Displays the error message
        }
    }

    // Output updated numbers
    cout << "Updated array:" << endl;  // Outputs updated array
    printArray(numbers, numCount);  // Calls the function to print the updated array

    // This adds a new integer to the array in the form of a while loop and bool
    while (true) {
        try {
            int newInt;  // newInt variable
            cout << "Please enter an integer to add to the array: ";  // Ask user for integer
            cin >> newInt;

            if (cin.fail()) {  // Checks if input is valid
                throw invalid_argument("Error. Invalid integer input. Please enter a valid number.");  // Output error message if invalid
            }

            if (addNewInt(numbers, numCount, newInt, MAX_NUMBERS)) {  // Try to add the new integer to the array
                cout << "Added " << newInt << " to the array." << endl;  // Iutputs new integer that was added to the array
                break;  // Exits the loop if successful
            } else {
                throw overflow_error("Error. Array is full. Cant add new integer.");  // Output error with throw
            }
        } catch (const invalid_argument& e) {  // Catches the invalid arguments
            cin.clear();  // This Clears the error flag on cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard and deletes invalid input
            cout << e.what() << endl;  // Display the error message for the user
        } catch (const overflow_error& e) {  // Catch overflow errors
            cout << e.what() << endl;  // Display the error message for the user
            break;  // Exit the loops when/if full
        }
    }

    // This outputs numbers after adding
    cout << "New Array after addition:" << endl;  // Displays new array
    printArray(numbers, numCount);  //The call function to print the array after addition

    // Replace or remove a value at a specific index in form of while/bool
    while (true) {
        try {
            int replaceIndex;  //stores the index to replace or remove
            char choice;  // stores the user's choice. either r or 0
            cout << "Please Enter index to replace or remove: ";
            cin >> replaceIndex;  // Reads the index from user input

            if (cin.fail()) {  // This checks if valid
                throw invalid_argument("Error. Invalid index input. Please enter a valid number.");  // Throws error message
            }

            cout << "Please Enter 'r' to remove or '0' to replace with 0: ";  // Prompt user to enter their choice of either r or 0
            cin >> choice;  // Reads input

            if (cin.fail() || (choice != 'r' && choice != '0')) {  // Check if input was invalid or choice was not recognized
                throw invalid_argument("Error. Invalid choice input. Please enter 'r' to remove or '0' to replace with 0.");  // Throw an error if input is invalid
            }

            if (RemoveReplaceIndex(numbers, numCount, replaceIndex, choice == 'r')) {  // Try to replace or remove the value at the specified index
                if (choice == 'r') {  // If r, removes
                    cout << "Removed value at index " << replaceIndex << "." << endl;  // outputs when removed
                } else {
                    cout << "Replaced value at index " << replaceIndex << " with 0." << endl;  // outputs when replaced
                }
                break;  // Exits tge loops
            } else {
                throw out_of_range("Error. Index is out of bounds.");  // Throws an out of range error if the index is invalid
            }
        } catch (const invalid_argument& e) {  // Catches for  invalid argument errors
            cin.clear();  // Clears the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discards and deleted invalid input
            cout << e.what() << endl;  // Display the error message
        } catch (const out_of_range& e) {  // Catches out of range errors
            cout << e.what() << endl;  // Displays the error message
        }
    }

    // This outputs numbers after replacement/removal
    cout << "New Array after modification:" << endl;  // Outputs array after modification will be displayed
    printArray(numbers, numCount);  // Calls function to print the array after modification

    return 0;  // Return 0 to indicate successful completion
}
