// *********************************************
// Course: TCP1101 PROGRAMMING FUNDAMENTALS
// Year: Trimister 1, 2022/23 (T2215)
// Lab: T13L
// Name: Mohd Hafizul Hilmi Bin Mokhtar
// ID: 1211304050
// Email: 1211304050@student.mmu.edu.my
// Phone: +60148636793
//**********************************************

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

const int MAX_ROWS = 100;
const int MAX_COLUMNS= 100;

int rows, columns, zombies, points;
std::vector<std::vector<char>> gameBoard;
int alienX, alienY;

void intializeBoard()
{
    gameBoard.resize(rows);
    for (int i=0; i < rows; i++)
    {
        gameBoard[i].resize(columns);
        for (int j = 0; j < columns; j++)
        {
            gameBoard[i][j] = '.';
        }
    }
    // Places zombie randomly on board
    srand(time(0));
    for (int i = 0; i < zombies; i++)
    {
        int x = rand() % rows;
        int y = rand() % columns;
        gameBoard[x][y] = 'Z';
    }
    // Place alien ob board
    std::cout << "Enter alien starting position (x y): ";
    std::cin >> alienX >> alienY;
    gameBoard[alienX][alienY] = 'A';
    points = 0;
}
void displayBoard()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            std::cout << gameBoard[i][j] << '.';
        }
        std::cout << '\n';
    }
    std::cout << "Points: " << points << '\n';
}
// command control
void moveAlien(const std::string &direction)
{
    gameBoard[alienX][alienY] = '.';
    if (direction == "up")
    {
        if (alienX > 0)
        {
            alienX--;
        }
    }
    else if (direction == "down")
    {
        if (alienX < rows - 1)
        {
            alienX++;
        }
    }
    else if (direction == "right")
    {
        if (alienX < columns - 1)
        {
            alienY++;
        }
    }
    else if (direction == "left")
    {
        if (alienY > 0)
        {
            alienY--;
        }
    }
    if (gameBoard[alienX][alienY] == 'Z')
    {
        gameBoard[alienX][alienY] = '.';
        points++;
    }
    else
    {
        gameBoard[alienX][alienY] = 'A';
    }
}

int main()
{
    std::cout << "Enter number of rows, columns, and zombies: ";
    std::cin >> rows >> columns >> zombies;
    intializeBoard();
    displayBoard();
    while (true)
    {
        std::cout << "Enter direction ('h' for help or 'q' for quit): ";
        std::string direction;
        std::cin >> direction;
        if (direction =="h")
        {
            std::cout << "Enter 'up', 'down', 'right', 'left' to move the alien or 'q' to quit\n";
        }
        else if (direction == "q")
        {
            std::cout << "Thank you for playing!\n";
            break;
        }
        else
        {
            moveAlien(direction);
            if (gameBoard[alienX][alienY] == 'Z')
            {
                points++;
            }
            displayBoard();
            std::cout << "You have" << points << " points.\n";
        }
        if (points == zombies)
        {
            std::cout << "You won! All zombies are defeated.\n";
            break;
        }
    }
    return 0;
}