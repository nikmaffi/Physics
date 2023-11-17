#include <iostream>

/*
Calls number of power_v1:
Since each calls n is reduced by 1 until it reachs 0,
the number of calls is n + 1.
example:
    n = 5           | 1 call
    n = (5 - 1) = 4 | 2 call
    n = (4 - 1) = 3 | 3 call
    n = (3 - 1) = 2 | 4 call
    n = (2 - 1) = 1 | 5 call
    n = (1 - 1) = 0 | 6 call | base case | stop calling

Calls number of power_v2:
If the base is a, since each calls a is reduced by 1 until it reachs 0, and
for each calls there are 2 more calls, the total number of calls is the nmber
of elements of the binary tree, created from the calls (2^bin_tree_height - 1)
example: n = 5 -> height = 4 -> calls = 2^4 - 1 = 15
n = 5
|
+---n = 2
|   |
|   +---n = 1
|   |   |
|   |   +---n = 0
|   |   |
|   |   +---n = 0
|   |
|   +---n = 1
|       |
|       +---n = 0
|       |
|       +---n = 0
|
+---n = 2
    |
    +---n = 1
    |   |
    |   +---n = 0
    |   |
    |   +---n = 0
    |
    +---n = 1
        |
        +---n = 0
        |
        +---n = 0
*/

unsigned __global_power_v1_calls = 0, __global_power_v2_calls = 0;

long long power_v1(int a, unsigned n) {
    //Increasing calls counter
    __global_power_v1_calls++;
    
    //Base case
    if(n == 0) {
        return 1;
    }

    //Computing power (recursion)
    return a * power_v1(a, n - 1);
}

long long power_v2(int a, unsigned n) {
    //Next exponent
    unsigned next_exp = 0;

    //Increasing calls counter
    __global_power_v2_calls++;
    
    //Base case
    if(n == 0) {
        return 1;
    }

    //Computing the next exponent
    next_exp = n / 2;

    //Computing the power (recursion)
    //Checking if the number is even or odd
    if(n % 2 == 0) {
        //n is even
        return power_v2(a, next_exp) * power_v2(a, next_exp);
    } else {
        //n is odd
        return a * power_v2(a, next_exp) * power_v2(a, next_exp);
    }
}

int main() {
    //Base and exponent
    int a = 0, n = 0;

    //Getting a and n from the user
    std::cout << "Enter the base and the exponent:\n";
    std::cin >> a >> n;

    //Checking the value of n
    if(n < 0) {
        //Printing the error
        std::cout << "\nError: Enter a positive number!\n";
    } else {
        std::cout << "\nPower v1: " << power_v1(a, n) << " | calls: " << __global_power_v1_calls
            << "\nPower v2: " << power_v2(a, n) << " | calls: " << __global_power_v2_calls << "\n";
    }

    return EXIT_SUCCESS;
}