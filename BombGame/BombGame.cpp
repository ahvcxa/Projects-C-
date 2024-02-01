#include <iostream>
#include <time.h>

void gameboard(int space[3][3])
{

    std::cout << "  ----|----|----\n";
    std::cout << "   " << space[0][0] << "  | " << space[0][1] << "  | " << space[0][2] << "   \n ";
    std::cout << " ----|----|----\n";
    std::cout << "   " << space[1][0] << "  | " << space[1][1] << "  | " << space[1][2] << "   \n ";
    std::cout << " ----|----|----\n";
    std::cout << "   " << space[2][0] << "  | " << space[2][1] << "  | " << space[2][2] << "   \n ";
    std::cout << " ----|----|----\n";
}
void bomb(int space[3][3])
{
    srand(time(0));
    int row = rand() % 3;
    int col = rand() % 3;
    space[row][col] = 0;
}

bool check(int space[3][3], int plyrMove[2])
{
    return (space[plyrMove[0]][plyrMove[1]] == 0);
}

int player(int move, int plyrMove[2])
{
    switch (move)
    {
    case 1:
        plyrMove[0] = 0;
        plyrMove[1] = 0;
        break;
    case 2:
        plyrMove[0] = 0;
        plyrMove[1] = 1;
        break;
    case 3:
        plyrMove[0] = 0;
        plyrMove[1] = 2;
        break;
    case 4:
        plyrMove[0] = 1;
        plyrMove[1] = 0;
        break;
    case 5:
        plyrMove[0] = 1;
        plyrMove[1] = 1;
        break;
    case 6:
        plyrMove[0] = 1;
        plyrMove[1] = 2;
        break;
    case 7:
        plyrMove[0] = 2;
        plyrMove[1] = 0;
        break;
    case 8:
        plyrMove[0] = 2;
        plyrMove[1] = 1;
        break;
    case 9:
        plyrMove[0] = 2;
        plyrMove[1] = 2;
        break;
    }
}

bool checktie(int move, int tie[9])
{
    if (tie[move - 1] == move)
    {
        tie[move - 1] = 0;
        return true;
    }
    else
        return false;
}

int main()
{
    int space[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int move, plyrMove[2];
    int score = 0;
    int tie[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    gameboard(space);
    bomb(space);

    while (true)
    {
        std::cout << "Enter: ";
        std::cin >> move;
        if (move <= 9 && move > 0)
        {
            player(move, plyrMove);
        }
        else
        {
            std::cout << "You should enter between 1 to 9 !! " << std::endl;
            continue;
        }

        if (check(space, plyrMove))
        {
            std::cout << "\n\n";
            gameboard(space);
            std::cout << "---- Game Over ----\n";
            break;
        }
        else
        {

            if (checktie(move, tie))
            {
                std::cout << "---- You re lucky ^w^ ----\n";
                score++;
            }
            else
                std::cout << "You cannot chose same area !!\n";
        }
    }
    std::cout << "\nYour score is : " << score;

    return 0;
}