#include <iostream>
#include"Leaderboard.h"


int main()
{
    Leaderboard tmp;
    tmp.addScore(1,13);
    tmp.addScore(2, 93);
    tmp.addScore(3, 84);
    tmp.addScore(4, 6);
    tmp.addScore(5, 89);

    tmp.addScore(6, 31);
    tmp.addScore(7, 7);
    tmp.addScore(8, 1);
    tmp.addScore(9, 98);
    tmp.addScore(10, 42);

    std::cout <<tmp.top(5) <<"\n";
    tmp.reset(1);
    tmp.reset(2);
    tmp.addScore(3, 76);
    tmp.addScore(4, 68);

    std::cout << tmp.top(1) << "\n";
    tmp.reset(3);
    tmp.reset(4);
    tmp.addScore(2, 70);
    tmp.reset(2);
    return 1;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
