//Header file for input/output operations
#include <iostream>

//main function begin
int main() {
    //Declaration of two integers (and initialization)
    int num1 = 0, num2 = 0;

    //Output message for the user
    std::cout << "Enter two integers:\n";
    //Getting the input of the two numbers 
    std::cin >> num1 >> num2;

    //Checking if the second number is zero
    if(num2 == 0) {
        std::cout << "\nError: Cannot divide by zero!\n";
    } else {
        //Checking if num1 is multiple of num2 and printing the corresponding message
        if(num1 % num2 == 0) {
            std::cout << "\n" << num1 << " is a multiple of " << num2 << "!\n";
        } else {
            std::cout << "\n" << num1 << " is not a multiple of " << num2 << "!\n";
        }
    }

    return EXIT_SUCCESS; // == 0 -> (#define EXIT_SUCCESS 0)
}
//main function end