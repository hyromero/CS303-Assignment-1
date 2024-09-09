#include <iostream>   // Include the standard I/O stream library for output
#include "Arrays.h"  // Include the header file to use the `add` function

using namespace std;  // Use the standard namespace to avoid prefixing `std::`

int main() {
    // Output test message
    cout << "Hello, World!" << endl;

    // Use the `add` function from Arrays.cpp
    // Call the `add` function to add 5 and 3, and store the result
    int result = add(5, 3);

    // Output the result of the addition
    cout << "The result of adding 5 and 3 is: " << result << endl;

    // Output another test message
    cout << "TEST";

    return 0;  // Return 0 to indicate successful completion
}
