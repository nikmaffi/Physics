#include <iostream>
#include <cmath>

//Function to compute the space
double space(double t, double a, double v0, double s0) {
    return 1/2 * a * std::pow(t, 2) + v0 * t + s0;
}

int main() {
    double delta = .0;
    //Number of iterations, loop counter
    int n = 0, i = 0;
    //Acceleration, init vel, init space
    double a = .0, v0 = .0, s0 = .0;
    //Time
    double t = .0;

    //Getting a, v0 and s0 from the user
    std::cout << "Enter the acceleration, the initial velocity and the initial position:\n";
    std::cin >> a >> v0 >> s0;

    //Getting delta time value from the user
    std::cout << "Enter the delta time value: ";
    std::cin >> delta;

    //Getting the number of iterations from the user
    std::cout << "Enter the number of iterations: ";
    std::cin >> n;

    //Checking delta value and n value
    if(delta < 0 || n < 0) {
        //Printing error
        std::cout << "\n\nBoth delta and number of iteration value must be positive!\n";
    } else {
        std::cout << "\n";

        //Calculating and printing the results
        while(i < n) {
            std::cout << "Pos: " << space(t, a, v0, s0) << " m at " << t << " s\n";

            //Increasing time by delta value and loop counter
            t += delta;
            i++;
        }
    }

    return EXIT_SUCCESS;
}