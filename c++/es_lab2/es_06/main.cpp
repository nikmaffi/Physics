#include <iostream>

void swap(int &a, int &b) {
    //XOR Swapping
    /*
    ^ is bitwise xor
    where xor truth table is:
     a | b | o
    ---+---+---
     0 | 0 | 0
     0 | 1 | 1
     1 | 0 | 1
     1 | 1 | 0

    if a is 6 (in binary 110) and b is 3 (in binary 011), xor swapping:
    1) a = a xor b -> a = 110 xor 011 = 101
    2) b = b xor a -> b = 011 xor 101 = 110 (6 in base 10)
    3) a = a xor b -> a = 101 xor 110 = 011 (3 in base 10)
    */

    a ^= b;
    b ^= a;
    a ^= b;
}

int main() {
    //The two numbers to swap
    int a = 0, b = 0;

    //Getting the numbers from the user
    std::cout << "Enter two integers to swap\n";
    std::cout << "A: "; std::cin >> a;
    std::cout << "B: "; std::cin >> b;

    //Printing "before swapping" state
    std::cout << "\nBefore swaping: A = " << a << " B = " << b << "\n";
    //Swapping
    swap(a, b);
    //Printing "after swapping" state
    std::cout << "After swaping:  A = " << a << " B = " << b << "\n";

    return EXIT_SUCCESS;
}