//Header file for input/output operations
#include <iostream>

//main function begin
int main() {
    long long num = 0; //Declaration, and initialization, of an integer variable (used for getting the number from the keyboard)
    long long temp = 0; //Used for decreasing the original number without losing its value 
    long long fact = 0; //Used for storing the final result (factorial)

    //Printing the instructions message for the user
    std::cout << "Enter a natural number: ";
    //Getting the number from the keyboard
    std::cin >> num;

    //Checking if numOfStars is a natural number
    if(num >= 0) {
        temp = num; //temp contains the same value of num
        fact = 1; //Initializing fact to 1, otherwise the product would be zero

        //Continue to loop until the value of temp is not <= 1
        while(temp > 1) {
            fact *= temp; //fact = fact * temp;

            //Updating temp;
            temp--;

            /*
            Note: Shortest instruction (one line) --> fact *= temp--;
            We could do that since "temp--"" first use the current value of temp, and than decrement it (post decrement operator)
            */
        }

        //SHORT: The program "breaks" if num >= 8 (since 8! > 2^(sizeof(short)*8 - 1) - 1) ---> 8! = -25216
        //INT:   The program "breaks" if num >= 13 (since 13! > 2^(sizeof(int)*8 - 1) - 1) ---> 13! = 1932053504
        /*
        LONG:
            Linux PopOS --> sizeof(long) = 8
            SAME AS LONG LONG.
            Windows 11 --> sizeof(long) = 4
            SAME AS INT.
        */

        //LONG LONG: The program "breaks" if num >= 21 (since 21! > 2^(sizeof(long long)*8 - 1) - 1) ---> 21! = -4249290049419214848
        std::cout << "\n" << num << "! = " << fact << std::endl;
    } else {
        //Printing the error message
        std::cout << "\nError: You must enter a natural number!\n";
    }

    return EXIT_SUCCESS;
} //end of main function