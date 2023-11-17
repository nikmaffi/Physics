#include <iostream>

long long fibonacci(int n) {
    //k1 is current - 1, k2 is current - 2
    long long k1 = 1, k2 = 0;

    for(int i = 0; i < n; i++) {
        //Computing next Fibonacci number (save it on k1)
        k1 = k1 + k2;
        //Setting k2 to k1 - k2 (k2 is our Fibonacci number)
        k2 = k1 - k2;
    }

    return k2;
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
        std::cout << "\nThe " << n << "th Fibonacci number is " << fibonacci(n) << "\n";
    }

    return EXIT_SUCCESS;
}