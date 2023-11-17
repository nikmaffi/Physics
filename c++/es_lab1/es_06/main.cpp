//Header file for input/output operations
#include <iostream>

//main function begin
int main() {
    double num = .0; //The variable used for getting the user input
    double min = .0, max = .0; //The variables used to store respectively the minimum and the maximum number
    int count = 10; //The counter used to get only 10 number as input

    //Continue to loop if count is greater (not equals) than 0
    while(count > 0) {
        //Printing the message for the user
        std::cout << "Enter a real number: ";
        //Getting the number from keyboard
        std::cin >> num;

        //If the iteration is the first then we need to set min and max with the value of num:
        /*Example: if the ten numbers are -1, -2, -3, ... then min = -10 but max = 0 since we have initialize it as 0 (line 7)
        similarly if the ten numbers are 1, 2, 3, ... then max = 10 but min = 0 for the same reason.
        
        With this correction --> ex: nums = -5, 1, -7, 9, 10, 555, -123, 0, 8, -33
        iter 1 --> min = -5 and max = -5
        iter 2 --> min = -5 and max = 1 (1 > -5)
        iter 3 --> min = -7 (-7 < -5) and max = 1
        ...
        iter 10 --> min = -123 and max = 555*/
        if(count == 10) {
            max = min = num; //same as: max = num; min = num;
        } else {
            //If the number is greater than max then the value of num is the new max
            if(num > max) {
                max = num;
            }

            //If the number is less than min then the value of num is the new min
            if(num < min) {
                min = num;
            }
        }

        //Updating the counter
        count--;
    }

    //Printing the result
    std::cout << "\nThe smallest number is: " << min << "\nThe biggest number is: " << max << std::endl;

    return EXIT_SUCCESS;
} //end of main function