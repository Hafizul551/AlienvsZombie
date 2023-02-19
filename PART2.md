# Part 2

## Video Demo

Please provide the YouTube link to your [Video Demo] https://youtu.be/-Mr6ddWvJcg

## Minimum Requirements

### Completed

List all the features completed.

1. The game board
2. The movement control
3. Scoring features
4. Load and save
5. Alien & Zombie (health, damage)
6. If users use different command other than (up,down, left,right) the system will not respond
7. Battlemode

### To Do

List all the features not yet done. Remove this section if there is no incomplete requirements.

1. Power ups
2. Obstacle (rock,pod)
3. Different zombie different damage


## Additional Features

Describe the additional features that has been implemented.

1. I add features which is scoring features, this will help users to know what is thier score.
2. Whenever the Alien at the Zombie location, the program will ask to enter 'x' to attack.
3. There are win and lose feautures, I make each zombie damage is 20, if user put 5 zombies in the game, the Alien will defeated because the alien health only have 100. 
4. Before the game start, I make a simple menu which the program will ask the user to load or new game.

## Contributions

List down the contribution of each group members.

For example:

### Mohd Hafizul Hilmi Bin Mokhtar

1. Randomly generate game board.
2. Make the movement control.
3. Make scroring features.
4. Make save and load function.
5. Make the Alien & Zombie (health, damage)
6. Make some change if users use different command other than (up,down, left,right) the system will not respond
7. Make Battlemode feautures.



## Problems Encountered & Solutions

Describe the problems encountered and provide the solutions / plan for the solutions.

Problem :

1. After every move the entire game board was redrawn to show the updated position of the alien. This could lead to confusion as it would leave a trace of the previous position of the alien on the game board

2. There is the problem where the progress of the player can be saved but cannot load. This means that the code is trying to access the file from a location that does not exist.

3. There is problem in line 155 until 158, which cause Alien is dissapeared in the game whenever the Alien move.

4. The problem is there is no battlefight between the alien and the zombie. It should be like whenever Alien find the zombie, the Alien's health should decrease -20 because the zombie damage is 20.




Solution :

1. By adding a line of code to replace the character 'A' (representing the alien) with a '.' (representing an empty space) in the previous position of the alien. This line of code is placed before the code block that updates the position of the alien in the moveAlien function. gameBoard[alienX][alienY] = '.'; // Clear the previous position of the alien This modification ensures that the game board is updated time by time and does not leave any traces of the previous positions of the alien.

2. I need to checking the file name, the directory it is located in, and the path to the directory and I need to make sure that the file path specified in my code is correct.

3. I notice that I put the code at the wrong place and it should be under line 119 then the problem gone.

4. I need to add this code into my coding, the code is at line 107 until 115.

if (gameBoard[alienX][alienY] == 'Z')
    {
        alienHealth -= 20;
        if (alienHealth <= 0)
        {
            std::cout << "The alien died!\n";
            std::cout << "Game over!\n";
            exit(0);
        }

It means that, whenever the Alien is in a fight with the Zombie, and the Alien's health is decreased by 20 (as the game logic). Then, the code checks if the Alien's health has fallen to or below 0, then system will tell a message that the Alien has died, "Game over!" to indicate that the game has ended.