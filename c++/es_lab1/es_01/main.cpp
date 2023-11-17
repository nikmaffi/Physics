//Header file for input/output operations
#include <iostream>

//main function begin
int main() {
    //Declaration of two integers (and initialization)
    int n1 = 0, n2 = 0;

    //Output message for the user
    std::cout << "Enter two integers:\n";
    //Getting the input of the two numbers 
    std::cin >> n1 >> n2;

    //Computing the product of the variables and printing it
    std::cout << "\n" << n1 << " * " << n2 << " = " << n1 * n2 << std::endl;

    return EXIT_SUCCESS; // == 0 --> (#define EXIT_SUCCESS 0)
}
//main function end