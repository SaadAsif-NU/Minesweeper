# Minesweeper.io
Here is the project of 2nd Semster.Minesweeper in C++ using Object Oriented Programming principle.
This project consist of three classes.
First class is to set difficulty level i.e begineer, intermediate or advance.
The second class mygame is an abstarct class (contain the pure virtual functions) to follow the concept of polymorphism.
The third class board is a child class of difficultylevel and mygame ,follow the concept of inheritance.
The main function ask for the difficulty level and set it through class difficulty level.
The table of the game apperaed on the screen and can be play by entering number of row and column.


The Mine Sweeper Game with Scorecard is a final project developed to showcase the principles of Object-Oriented Programming (OOP). This game is designed as a table-based game where the player interacts with a grid of hidden boxes by providing row and column numbers to reveal the contents of each box. The game also includes a scorecard that keeps track of the player's performance.

Features:

Grid-Based Gameplay: The game is based on a grid of hidden boxes represented as rows and columns. The player interacts with the grid by providing row and column numbers to reveal the contents of a specific box.

Hidden Boxes: Each box in the grid is  initiallyhidden, concealing its contents(Contain numbers or bombs). The goal of the game is to uncover all the boxes and reveal their contents by strategically selecting the row and column numbers.

Scorecard: The game includes a scorecard that tracks the player's performance. It displays relevant information such as the number of moves taken, the number of successful reveals, and the overall score.

User Input: The game prompts the player to input the row and column numbers to reveal a specific box. It validates the input and provides feedback on whether the reveal was successful or not.

Randomized Content: The contents of the boxes are generated randomly for each game session, adding an element of unpredictability and replayability to the game.

Score Calculation: The player's score is calculated based on factors such as the number of successful reveals, the time taken to complete the game, and any additional criteria you may decide to implement.

Winning Condition: The game determines whether the player has won by checking if all the boxes with no bomb were explored 
