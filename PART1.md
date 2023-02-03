# Part 1

## Video Demo

Please provide the YouTube link to your [Video Demo](https://youtu.be/d-E-d4Y-1RQ).

## Minimum Requirements

### Completed

List all the features completed.

1. The game board
2. The movement control
3. Scoring features

### To Do

List all the features not yet done. Remove this section if there is no incomplete requirements.

1. Load and save
2. Alien & Zombie (health, damage)
3. Power ups
4. Obstacle (rock,pod)
5. Try to make different zombie, different damage
6. If users use different command other than (up,down, left,right) the system will said "invalid command"
7. Battlemode

## Additional Features

Describe the additional features that has been implemented.
1. I add features which is scoring features, this will help users to know what is thier score.




## Contributions

List down the contribution of each group members.

For example:

### Mohd Hafizul Hilmi Bin Mokhtar

1. Randomly generate game board.
2. Make the movement control
3. Make scroring features




## Problems Encountered & Solutions

Describe the problems encountered and provide the solutions / plan for the solutions.

Problem :
1. After every move the entire game board was redrawn to show the updated position of the alien. This could lead to confusion as it would leave a trace of the previous position of the alien on the game board


Solution :
1. By adding a line of code to replace the character 'A' (representing the alien) with a '.' (representing an empty space) in the previous position of the alien. This line of code is placed before the code block that updates the position of the alien in the moveAlien function.   **gameBoard[alienX][alienY] = '.'; // Clear the previous position of the alien** This modification ensures that the game board is updated time by time and does not leave any traces of the previous positions of the alien.

