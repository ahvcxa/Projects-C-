#include <iostream>
#include <cstdlib>
#include <ctime>

class Player
{
public:
    virtual std::string move() = 0;
};

class Humanplayer : public Player
{
private:
    std::string humanMove;

public:
    std::string move() override
    {
        std::cout << "Write your move:  ";
        std::cin >> humanMove;
        std::cout << "\n\n";
        return humanMove;
    }
};

class Computerplayer : public Player
{
public:
    std::string move() override
    {
        int randmove = rand() % 3 + 1;

        switch (randmove)
        {
        case 1:
            return "Paper";
        case 2:
            return "Rock";
        case 3:
            return "Scissors";
        }
    }
};

void check(Player *playerPtr, Player *computerPtr)
{
    static int score[2] = {0, 0};
    std::string playerMove = playerPtr->move();
    std::string computerMove = computerPtr->move();

    std::cout << "Human move: " << playerMove << std::endl;
    std::cout << "Computer move: " << computerMove << std::endl;

    if (playerMove == computerMove)
    {
        std::cout << "\n\nIt's a tie!" << std::endl;
    }
    else if ((playerMove == "Rock" && computerMove == "Scissors") ||
             (playerMove == "Paper" && computerMove == "Rock") ||
             (playerMove == "Scissors" && computerMove == "Paper"))
    {
        std::cout << "\n\nHuman wins!" << std::endl;
        score[0]++;
    }
    else
    {
        std::cout << "\n\nComputer wins!" << std::endl;
        score[1]++;
    }
    std::cout << "Human : " << score[0] << " - " << score[1] << " : Computer";
}

int main()
{
    srand(time(0));

    Humanplayer player1;
    Computerplayer computer1;

    int round = 1;

    while (true)
    {
        std::cout << "\nRound " << round << "\n";

        check(&player1, &computer1);
        std::cout << "\n\n";
        round++;
        if (round == 7)
        {
            std::cout << "\n---GAME FINISHED---\n ";
            break;
        }
    }

    return 0;
}
