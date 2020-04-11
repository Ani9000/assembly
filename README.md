# Assembly game using C made by Aniruddha Redkar and Sukhveer Sahota. Paste FinalProject.c in cpuLator, and the .c in file resources below it to play the game.

cpulator : https://cpulator.01xz.net/?sys=arm-de1soc

Game Instructions
Before starting the program, disable the Device-Specific warnings in CPULATOR. Also, insert the arrays from the arrayData.c file into the specified section near the top of the code file (FinalProject.c) before compiling.

On the initial start screen, press ENTER on the keyboard to begin

On each screen that displays the current level (e.g. “Level 1”), press ENTER on the keyboard to begin the level

Use the keyboard to control the players. The blue player on the right is controlled with the arrow keys (UP to shoot). The orange player on the left is controlled with WASD (W to shoot). 

You can change the number of players as well (the #define NUM_PLAYERS on line 14) to switch between single-player and double player (single player mode uses WASD).

Players should shoot the bouncing bubbles while avoiding getting hit by them. 

When a big bubble is shot, it will split into two bubbles. Small bubbles will disappear when shot. The level is complete when all bubbles disappear from the screen.

There are four levels in the game. You can customize the number of levels by changing the #define NUM_LEVELS on line 12)

If any of the players gets hit, the game is over. You will be shown a game over screen with losing music played, its a sad music.

If the player beats all the four levels, you will be shown a YOU WIN screen with winning music, its a guitar rock music (you can force this to happen by changing NUM_LEVELS to 0).

Each time a player shoots a bubble, their score increases by 1. The HEX maintains the score of each player separately.

A timer is shown using the LEDs. The LEDs start off all being on, and count down at regular intervals. If you run out of time to complete a level, you lose. (The timer resets after each level)
