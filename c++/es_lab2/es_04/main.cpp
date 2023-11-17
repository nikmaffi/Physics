#include <iostream>

unsigned __global_fibonacci_calls = 0;

long long fibonacci(int n) {
    //Increasing the calls counter
    __global_fibonacci_calls++;
    
    //Base case
    if(n <= 1) {
        return n;
    }

    //Computing, recursively, the Fibonacci number
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    //Fibonacci number
    int n = 0;

    //Getting n from the user
    std::cout << "Enter the index (0 - n) of the Fibonacci number: ";
    std::cin >> n;

    //Checking the value of n
    if(n < 0) {
        //Printing the error
        std::cout << "\nError: You must enter a positive number!\n";
    } else {
        //Printing the result
        std::cout << "\nThe " << n << "th Fibonacci number is " << fibonacci(n)
            << " | Calls: " << __global_fibonacci_calls << "\n";
    }

    return EXIT_SUCCESS;
}