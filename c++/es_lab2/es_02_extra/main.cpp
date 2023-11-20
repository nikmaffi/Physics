#include <iostream>

//Defining constants for the stakes indexes
#define FIRST_STAKE_IDX 1
#define LAST_STAKE_IDX 3

int hanoi(int n, int from, int to) {
    //Used in the recursive call (1 rec call -> to = tmp; 2 rec call -> from = tmp)
    int tmp = 0;
    //Used to count the hanoi function calls
    static int calls = 0;

    //Increasing calls
    calls++;

    //Base case (no more disk to move)
    if(n == 0) {
        return calls;
    }

    /*
    Calculating the value of tmp
    The sum of all stake indexes is 6 (1 + 2 + 3), this allow to calculate
    the index of the temporary stake.
    example:
        from = 3 to = 2 (tmp must be 1)
        6 - 3 - 2 = 1
    */
    tmp = 6 - from - to;

    //Recursive calling (tmp as the next to)
    hanoi(n - 1, from, tmp);

    //Printing the result
    std::cout << from << " ==> " << to << std::endl;

    //Recursive callings (tmp as the next from)
    hanoi(n - 1, tmp, to);

    return calls;
}

int main() {
    //Number of disks
    int n = 0;
    //Number of hanoi function calls
    int calls = 0;

    //Getting the n from the user
    std::cout << "Enter the number of disks to move: ";
    std::cin >> n;

    if(n >= 1) {
        //Printing the moves
        std::cout << "Minimum number of moves:\n\n";

        calls = hanoi(n, FIRST_STAKE_IDX, LAST_STAKE_IDX);

        std::cout << "\n\nFunction calls: " << calls << "\n";
    } else {
        //Printing error
        std::cout << "\nEnter a number greater than 0!" << std::endl;
    }

    return EXIT_SUCCESS;
}
