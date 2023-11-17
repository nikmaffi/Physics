//Header file for input/output operations
#include <iostream>

void rectangle(int numOfStars) {
    /*Declaration, and initialization, of the counters used in the loops.
    CountOut in the "biggest" while and countIn in the inner while*/
    int countOut = 0, countIn = 0;

    //Continue to loop while countOut is less (not equals) than numOfStars
    while(countOut < numOfStars) {
        //We need to initialize countIn on each loop, otherwise the inner while wont run.
        countIn = 0;
        //Continue to loop while countIn is less (not equals) than numOfStars
        while(countIn < numOfStars) {
            //Printing the star
            std::cout << "*";

            //Updating the counter
            countIn++;
        }

        //Printing new line character, otherwise a line would be printed
        std::cout << "\n";
        
        //Updating the counter
        countOut++;
    }
}

void triangle_v1(int numOfStars) {
    /*Declaration, and initialization, of the counters used in the loops.
    CountOut in the "biggest" while and countIn in the inner while*/
    int countOut = 0, countIn = 0;
    
    //Inizialization of countOut to the value of numOfStars
    countOut = numOfStars;
    //Continue to loop while countOut is greater (not equals) than zero
    while(countOut > 0) {
        //We need to initialize countIn on each loop, otherwise the inner while wont run.
        countIn = 0;
        //Continue to loop while countIn is less (not equals) than numOfStars - countOut + 1
        //Table of "numOfStars - countOut + 1":
        /*
            numOfStart = 5
            
            iter 1 -> 1
            iter 2 -> 2
            ...
            iter 5 -> 5
        */
        while(countIn < numOfStars - countOut + 1) {
            //Printing the star
            std::cout << "*";

            //Updating the counter
            countIn++;
        }

        //Printing new line character, otherwise a line would be printed
        std::cout << "\n";
        
        //Updating the counter
        countOut--; //countOut = countOut - 1
    }
}

void triangle_v2(int numOfStars) {
    /*Declaration, and initialization, of the counters used in the loops.
    CountOut in the "biggest" while and countIn in the inner while*/
    int countOut = 0, countIn = 0;

    //Continue to loop while countOut is less (not equals) than numOfStars
    while(countOut < numOfStars) {
        //We need to initialize countIn on each loop, otherwise the inner while wont run.
        countIn = 0;
        //Continue to loop while countIn is less (not equals) than countOut
        //Table of "countOut":
        /* 
            numOfStars = 5

            iter 1 -> 0
            iter 2 -> 1
            ...
            iter 5 -> 4
        */
        while(countIn < countOut) {
            //Printing the space character
            std::cout << " ";

            //Updating the counter
            countIn++;
        }

        countIn = 0;
        //Continue to loop while countIn is less (not equals) than numOfStars - countOut + 1
        //Table of "numOfStars - countOut + 1":
        /* 
            numOfStars = 5

            iter 1 -> 1
            iter 2 -> 2
            ...
            iter 5 -> 5
        */
        while(countIn < numOfStars - countOut) {
            //Printing the star
            std::cout << "*";

            //Updating the counter
            countIn++;
        }

        //Printing new line character, otherwise a line would be printed
        std::cout << "\n";
        
        //Updating the counter
        countOut++;
    }
}

//main function begin
int main() {
    //Declaration, and initialization, of an integer variable (numOfStart is the side of the square)
    int numOfStars = 0;

    //Printing the instructions message for the user
    std::cout << "Enter the length of the stars square (greater than 0): ";
    //Getting the number from the keyboard
    std::cin >> numOfStars;

    //Checking if numOfStars is in the specified range
    if(numOfStars > 0) {
        //Printing new line for a prettier code
        std::cout << "\n";

        //Printing the triangle
        triangle_v2(numOfStars);
    } else {
        //Printing the error message
        std::cout << "\nError: You must enter a number greater than 0!\n";
    }

    return EXIT_SUCCESS;
} //end of main function