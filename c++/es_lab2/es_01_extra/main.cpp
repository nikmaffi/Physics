#include <iostream>

//XOR swapping function
void swap(int &a, int &b) {
    a ^= b;
    b ^= a;
    a ^= b;
}

//Euclidean algorithm (recursive)
int euclidean_alg_rec(int a, int b) {    
    //Base case
    if(a == 0) {
        return b;
    }

    if(a < b) {
        swap(a, b);
    }

    a -=b;

    return euclidean_alg_rec(a, b);
}

//Euclidean algorithm (loop)
int euclidean_alg(int a, int b) {
    while(a != 0) {
        if(a < b) {
            swap(a, b);
        }

        a -= b;
    }

    return b;
}

void min_terms(int &num, int &den) {
    //Converting num and den to positive numbers (sign check will be done later)
    int gcd = euclidean_alg_rec(std::abs(num), std::abs(den));

    //Dividing num and den by gcd
    num /= gcd;
    den /= gcd;

    //If den is negative, put the minus at the numerator (recalculating num and den)
    if(den < 0) {
        num *= -1;
        den *= -1;
    }
}

int main() {
    //Numerator and denominator
    int num = 0, den = 0;

    //getting num and den from user
    std::cout << "Enter the fraction (numerator and denominator):\n";
    std::cin >> num >> den;

    //Checking den
    if(den == 0) {
        //Printing the error
        std::cout << "\nError: The denominator cannot be 0!\n";
    } else {
        //Reducing the fraction
        min_terms(num, den);

        //Printing the results
        std::cout << "\nThe fraction reduced is: " << num;

        //Printing den only if den is not 1 
        if(den != 1) {
            std::cout << "/" << den;
        }

        std::cout << std::endl;
    }

    return EXIT_SUCCESS;
}
