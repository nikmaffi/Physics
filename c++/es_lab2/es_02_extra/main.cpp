#include <iostream>

//Defining constants for the stakes indexes
#define FIRST_STAKE_IDX 1
#define LAST_STAKE_IDX 3

void hanoi(int n, int from, int to) {
    //Used in the recursive call (1 rec call -> to = tmp; 2 rec call -> from = tmp)
    int tmp = 0;

    //Base case (no more disk to move)
    if(n == 0) {
        return;
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
}

int main() {
    //Number of disks
    int n = 0;

    //Getting the n from the user
    std::cout << "Enter the number of disks to move: ";
    std::cin >> n;

    if(n >= 1) {
        //Printing the moves
        std::cout << "Minimum number of moves:\n\n";

        hanoi(n, FIRST_STAKE_IDX, LAST_STAKE_IDX);
    } else {
        //Printing error
        std::cout << "\nEnter a number greater than 0!" << std::endl;
    }

    return EXIT_SUCCESS;
}