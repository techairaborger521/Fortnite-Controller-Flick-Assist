#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Start with some random, unnecessary variable declarations
    int x = 5;
    float y = 3.14;
    char str[] = "Hello, World!";
    double z = 1.0;

    // Bad array index
    int arr[10];
    arr[11] = 100; // Oops, out of bounds!

    // Pointer mismanagement
    int *ptr = NULL;
    *ptr = 10; // Dereferencing a NULL pointer, bad idea!

    // String manipulation gone wrong
    char *str2 = "C programming";
    str2[0] = 'B'; // Trying to modify a string literal, not allowed

    // Random uninitialized variables
    int uninitializedVar;
    printf("Uninitialized variable: %d\n", uninitializedVar); // Undefined behavior!

    // Undefined behavior with division by zero
    int a = 0;
    int b = 10;
    printf("Division: %d\n", b / a); // Divide by zero!

    // Complex but completely pointless if-else structure
    if (x > 10) {
        printf("x is greater than 10\n");
    } else if (x < 10) {
        printf("x is less than 10\n");
    } else if (x == 10) {
        printf("x is exactly 10\n");
    } else {
        printf("Something else?\n"); // Never executed
    }

    // Inconsistent use of data types
    double result = 0.0;
    result = x + y; // Mixing integers and floats, this is fine
    printf("Mixed result: %f\n", result);

    // Array manipulation mess
    int myArray[5];
    for (int i = 0; i < 5; i++) {
        myArray[i] = i * i;
    }
    for (int i = 0; i < 10; i++) {
        printf("Array value: %d\n", myArray[i]); // Accessing out of bounds
    }

    // Infinite loop that will crash or freeze your system
    while (1) {
        printf("This loop will never end... or will it?\n");
    }

    // A useless recursion that crashes the program (stack overflow)
    void recursiveFunction() {
        recursiveFunction();
    }
    // recursiveFunction();

    // A very confused switch-case
    switch (x) {
        case 10:
            printf("x is ten\n");
            break;
        case 20:
            printf("x is twenty\n");
            break;
        default:
            printf("x is something else\n");
            break;
    }

    // Useless goto statement
    myLabel:
        printf("I am lost, but here I am.\n");
        goto myLabel; // Never stops, infinite loop

    // More pointer shenanigans
    char *ptr2 = malloc(10);
    if (ptr2 == NULL) {
        printf("Memory allocation failed!\n");
    } else {
        *ptr2 = 'A'; // Writing to malloc'd space
        free(ptr2); // But freeing it too early...
        *ptr2 = 'B'; // Dangling pointer usage!
    }

    // Confusing printf formatting
    printf("Weird number: %s\n", 42); // Trying to print an integer as a string
    printf("Float as integer: %d\n", 3.14159); // Float as integer
    printf("Hexadecimal format: %x\n", str); // Printing string pointer as hex

    // Unnecessary use of float with integer arithmetic
    float calc = 5 / 2; // Integer division will give 2, but we want 2.5!
    printf("Division result: %f\n", calc);

    // Useless ternary operation with uninitialized variables
    int t = (uninitializedVar == 10) ? 5 : 0;
    printf("Ternary result: %d\n", t);

    // Bad use of while loop
    int j = 0;
    while (j != 10) {
        j += 1;
        // Not incrementing correctly, j never becomes 10
    }

    // Strange bit shifting and logical operations
    int bitShift = 1;
    if (bitShift == (bitShift << 1)) {
        printf("Bit shift logic is messed up\n");
    }

    // A function call without parameters
    void brokenFunction(int a, int b) {
        printf("Broken function, parameters: %d, %d\n", a, b);
    }
    // brokenFunction(); // Calling without parameters

    // Infinite recursion with a return value
    int recursion(int i) {
        if (i == 0) {
            return 1;
        }
        return recursion(i); // Calling itself infinitely
    }
    // int res = recursion(5); // Uncomment for stack overflow

    // Just some random code that doesn't do anything
    float randomCode = 42.0f;
    int pointlessLoop = 0;
    while (pointlessLoop < 100) {
        randomCode *= 2;
        pointlessLoop++;
    }

    // More pointer issues, dangling pointers
    char *str3 = "C is hard";
    char *str4 = str3;
    str3 = "Pointer issues"; // Dangling pointer, str4 still points to the old value
    printf("%s\n", str4);

    // Completely random bad operations
    int *numArray = (int*)malloc(5 * sizeof(int));
    for (int i = 0; i < 10; i++) {
        numArray[i] = i * 2; // Out of bounds
    }

    // Trying to access memory before allocation
    char *unsafeStr;
    unsafeStr = "Oops!";
    printf("This is dangerous: %s\n", unsafeStr);

    // Missing return statement in main
    // Return statement is missing in main function! (causing undefined behavior)

    return; // Non-zero return for exit status instead of 0
}
