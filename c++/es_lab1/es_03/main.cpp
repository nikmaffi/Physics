//Header file for input/output operations
#include <iostream>

//main function begin
int main() {
    //Declaration, and initialization, of an integer variable (the number of the *)
    int numOfStars = 0;
    //Declaration, and initialization, of the counter used in the while
    int count = 0;

    //Printing the instructions message for the user
    std::cout << "Enter the number of the stars you want to print (greater than 0): ";
    //Getting the number from the keyboard
    std::cin >> numOfStars;

    //Checking if numOfStars is in the specified range
    if(numOfStars > 0) {
        //Printing new line for a prettier code
        std::cout << "\n";
        
        //Continue to loop while count is less (not equals) than numOfStars
        while(count < numOfStars) {
            //Printing the star
            std::cout << "*";
            
            //Updating the counter
            count++; //count = count + 1
        }

        //Printing an "empty line"
        std::cout << std::endl;
    } else {
        //Printing the error message
        std::cout << "\nError: You must enter a number greater than 0!\n";
    }

    return EXIT_SUCCESS;
} //end of main function