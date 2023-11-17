//Header file for input/output operations
#include <iostream>
//Header file for math functions
#include <cmath>
//Header file for constants FLT_DIG, DBL_DIG, LDBL_DIG (https://cplusplus.com/reference/cfloat/)
#include <cfloat>
//Header file for std::setprecision() function
#include <iomanip>

void classic(void) {
    long long n = 0; //Degree of approximation (integer)
    float pi_flt = .0; //pi greek (calculated with float 32 bit precision)
    double pi_dbl = .0; //pi greek (calculated with float 64 bit --> double precision)
    long double pi_ldbl = .0; //pi greek (calculated with long double precision)

    //User message
    std::cout << "Enter the degree of approximation: ";
    //Getting the degree of approximation from the keyboard
    std::cin >> n;

    //Checking the degree f approximation (must be greather or equals to 0)
    if(n >= 0) {
        //For loop from 0 to n -> I: [0, n]
        for(long long j = 0; j <= n; j++) {
            //Computaion of the dum for each pi greek precision
            pi_flt += std::pow(-1, j) * 4/(2*j + 1);
            pi_dbl += std::pow(-1, j) * 4/(2*j + 1);
            pi_ldbl += std::pow(-1, j) * 4/(2*j + 1);
        }

        //Printing the results
        //with n = 1e9 we get only the first 8 decimal digit precisly (for floats, double and long double).
        std::cout << "Pi greek (float):\t" << std::setprecision(FLT_DIG) << pi_flt << std::endl;
        std::cout << "Pi greek (double):\t" << std::setprecision(DBL_DIG) << pi_dbl << std::endl;
        std::cout << "Pi greek (long double):\t" << std::setprecision(LDBL_DIG) << pi_ldbl << std::endl;
    } else {
        //Printing the error
        std::cout << "Error: Cannot enter a number less than zero!\n";
    }
}

void epsilon(void) {
    double epsilon = 0; //epsilon value (double)
    double pi = 0, term = 0; //pi value; term represents the single term of the sum (both double)
    unsigned long long j = 0; //The index used in the sum

    std::cout << "Enter the epsilon: ";
    std::cin >> epsilon;

    //Checking epsilon value (greater equals to )
    if(epsilon >= 0) {
        do {
            //Calculating a single term
            term = std::pow(-1, j) * 4/(2*j + 1);

            //Adding the term to the sum
            pi += term;

            j++;//Updating the index
        } while(std::abs(term) >= epsilon); //Continue until the abs(term) is not less than epsilon 

        //Printing the result
        //with n = 1e-9 we get only the first 8 decimal digit precisly (for floats, double and long double).
        std::cout << "Pi greek:\t" << std::setprecision(DBL_DIG) << pi << std::endl;
    } else {
        //Printing the error
        std::cout << "Error: Cannot enter a number less than zero!\n";
    }
}

//main function begin
int main() {
    epsilon();

    return EXIT_SUCCESS;
} //end of main function