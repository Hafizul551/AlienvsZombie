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
#include <fstream>

const int MAX_ROWS = 100;
const int MAX_COLUMNS= 100;

int rows, columns, zombies, points;
std::vector<std::vector<char>> gameBoard;
int alienX, alienY;
int alienHealth = 100;
int zombieHealth = 30;
int alienDamage = 30;
int zombieDamage = 20;

// Board function
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
    // Place alien on board
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
            std::cout << gameBoard[i][j] << ' ';
        }
        std::cout << '\n';
    }
    std::cout << "Points: " << points << '\n';
    std::cout << "Alien Health: " << alienHealth << '\n';
}

// movement control
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
    else
    {
        std::cout << "Invalid command" << std::endl;
    }

    // battle fight
    if (gameBoard[alienX][alienY] == 'Z')
    {
        alienHealth -= 20;
        if (alienHealth <= 0)
        {
            std::cout << "The alien died!\n";
            std::cout << "Game over!\n";
            exit(0);
        }
    }

    // check if alien and zombie are in the same position
    if (gameBoard[alienX][alienY] == 'Z')
    {
        int zombieHealth = 30;
        int alienHealth = 100;
        int zombieDamage = 20;
        int alienDamage = 30;
        while (zombieHealth > 0 && alienHealth > 0)
        {
            //extra command whenever the alien meet the zombie
            std::cout << "Press 'x' to attack the zombie: ";
            std::string attack;
            std::cin >> attack;

            if (attack == "x")
            {
                zombieHealth -= alienDamage;
                alienHealth -= zombieDamage;
            }
            else
            {
                std::cout << "invalid input, try again" << std::endl;
            }
        }
        if (zombieHealth <= 0)
        {
            std::cout << "You have defeated the zombie!" << std::endl;
            points++;
            gameBoard[alienX][alienY] = 'A';
        }
        else if (alienHealth <= 0)
        {
            std::cout << "You have been defeated by the zombie!" << std::endl;
            gameBoard[alienX][alienY] = '.';
        }
        
    }
    else
    {
        gameBoard[alienX][alienY] = 'A';
    }
}

// save and load function
void saveGame(const std::string  &filename)
{
    std::ofstream outfile(filename);
    if (!outfile)
    {
        std::cerr << "Failed to open file" << filename << '\n';
        return;
    }
    outfile << rows << ' ' << columns << ' ' << zombies << ' ' << points << ' ' << alienX << ' '  << alienY << ' ' << '\n';
    for (int i = 0; i < rows; i++)
    {   
        for (int j = 0; j < columns; j++)
        {   
            outfile << gameBoard[i][j] << ' ';
        }
        outfile << '\n';
    } 
    outfile.close();
}
bool loadGame(const std::string &filename)
{
    std::ifstream infile(filename);
    if (!infile)
    {
        std::cerr << "File not found: " << filename << '\n';
        return false;
    }
    infile >> rows >> columns >> zombies >> points >> alienX >> alienY;
    intializeBoard();

    return true;
}

int main()
{   std::cout << "Hello! Welcome to Alien vs Zombie" << std::endl;
    std::cout << "Enter 'l' to load saved game or 'p' to start a new game: ";
    std::string choice;
    std::cin >> choice;

    if (choice == "l")
    {
        std::string filename;
        std::cout << "Enter the file name to load the game from: ";
        std::cin >> filename;
        if (loadGame(filename))
        {
            displayBoard();
            std::cout << "You have " << points << "points.n";
        }
        else
        {
            std::cout << "No file detected.\n";
            return 0;
        }
    }
    else if (choice == "p")
    {
        std::cout << "Enter number of rows, columns and zombies: ";
        std::cin >> rows >> columns >> zombies;
        intializeBoard();
        displayBoard();
    }
    else
    {
        std::cout << "Invalid input.\n";
        return 0; 
    }
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
            std::cout << "Enter 's' to save the game or 'q' to quit without saving: ";
            std::string saveChoice;
            std::cin >> saveChoice;
            if (saveChoice == "s")
            {
                std::string filename;
                std::cout << "Enter the file name: ";
                std::cin >> filename;
                saveGame (filename);
                std::cout << "Game saved!\n";
            }
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
            std::cout << "You have " << points << " points.\n";
        }
        if (points == zombies)
        {
            std::cout << "You won! All zombies are defeated.\n";
            break;
        }
    }
    return 0;
}
