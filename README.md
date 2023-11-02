# Playable-Object-Control
Introduction
Welcome to the Border Wraparound Game, a simple yet engaging project that serves as one of my early coding challenges. The primary goal of this assignment was to construct a game backbone where the player can control an object to move freely within a game board area with border wraparound behavior.

Project Highlights
Game Backbone: The core of this project is a game backbone, providing the structure for a simple console-based game.

Border Wraparound: The player-controlled object can move freely within the game board area, and when it reaches the borders, it wraps around, creating a continuous and infinite playfield.

User Input: The game allows users to control the object using keyboard input (WASD keys) and provides various speed levels for added challenge.

Getting Started
To run the Border Wraparound Game on your system, follow these steps:

Clone this repository to your local machine.
Compile the code using your preferred C compiler (e.g., GCC).
Run the compiled executable to start the game within your console.
How to Play
Use the WASD keys to control the object's movement (W for up, A for left, S for down, D for right).
The object will wrap around the game board when it reaches the borders, providing a continuous play experience.
Change the speed level by pressing the corresponding numbers (1 to 5) for varying levels of challenge.
Use the semicolon (;) to exit the game.
Further Development
This project serves as a foundation for building more complex games and interactive applications. It introduces concepts of user input, game logic, and screen rendering. Feel free to explore and extend this project to add new features or enhance existing ones.

Challenges
While working on this project, I encountered several challenges, including:

Implementing asynchronous input handling for non-blocking character read-in.
Developing a game loop that updates the player's location based on user input and enforces border wraparound behavior.
Designing a screen drawing routine to display the game board, player object, and various debugging messages.
