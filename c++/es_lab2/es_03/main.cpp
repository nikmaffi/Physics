#include <iostream>

//Floyd triangle printer
void floyd_triangle(int height) {
    //Floyd number
    int num = 1;
    
    //Triangular iteration
    for(int row = 0; row < height; row++) {
        for(int col = 0; col <= row; col++) {
            //Printing the number and a space
            //(num++ is post increment - first prints num and then increments its value)
            std::cout << num++ << " ";
        }
        //New row of the triangle
        std::cout << "\n";
    }
}

int main() {
    //Height of the triangle
    int height = 0;

    //Getting the triangle height from the user
    std::cout << "Enter the height of the Floyd triangle: ";
    std::cin >> height;

    //Checking the triangle height
    if(height < 0) {
        //Printing the error
        std::cout << "\nThe height must be positive!\n";
    } else {
        //Printing the Floyd triangle
        floyd_triangle(height);
    }

    return EXIT_SUCCESS;
}