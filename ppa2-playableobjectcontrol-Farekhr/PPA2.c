#include <stdio.h>
#include "MacUILib.h"

// PPA2 GOAL: 
//       Construct the game backbone where the player can control an object 
//       to move freely in the game board area with border wraparound behaviour.

// Watch Briefing Video and Read Lab Manual before starting on the activity!



// PREPROCESSOR CONSTANTS DEFINITION HERE
/////////////////////////////////////////



// GLOBAL VARIABLE DEFINITION HERE
/////////////////////////////////////////

int exitFlag; // Program Exiting Flag - old stuff

// For storing the user input - from PPA1
char input;


// [TODO] : Define objPos structure here as described in the lab document

struct objPos
{
    int x;  // x-coordinate of the object
    int y;  //y-coordinate of the object
    char symbol;    // ASCII symbol of the object to be drawn
};

struct objPos position = {10, 5, '#'};

// [TODO] : Define the Direction enumeration here as described in the lab document
//          This will be the key ingredient to construct a simple Finite State Machine
//          For our console game backbone.

enum Dir
{
    IDLE,
    UP,
    DOWN,
    LEFT,
    RIGHT
};

enum Dir currentMotion = IDLE;

int play_speed = 100000;
float level;


// FUNCTION PROTOTYPING DEFINITION HERE
/////////////////////////////////////////

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);

// You may insert additional helper function prototypes below.
// 
// As a good practice, always insert prototype before main() and implementation after main()
// For ease of code management.



// MAIN PROGRAM LOOP
/////////////////////////////////////////
// This part should be intuitive by now.
// DO NOT TOUCH

int main(void)
{

    Initialize();

    while(!exitFlag)  
    {
        GetInput();

        RunLogic();

        DrawScreen();

        LoopDelay();
    }

    CleanUp();

}


// INITIALIZATION ROUTINE
/////////////////////////////////////////
void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    input = 0; // NULL
    exitFlag = 0;  // not exiting  
    
   
    // [TODO] : Initialize more variables here as seen needed.
    //          PARTICULARLY for the structs!!

    
    


}


// INPUT PROCESSING ROUTINE
/////////////////////////////////////////
void GetInput(void)
{
    // [TODO] : Implement Asynchronous Input - non blocking character read-in    
    //          (Same as PPA1)

    if (MacUILib_hasChar())
    {
        input = MacUILib_getChar();
    }

    else 
    {
        input = 0;
    }
    



}


// PROGRAM LOGIC ROUTINE
/////////////////////////////////////////
void RunLogic(void)
{
    // [TODO] : First, process the input by mapping
    //          WASD to the corresponding change in player object movement direction

    if(input != 0)  // if not null character
    {
        switch(input)
        {                      
            case ';':  // exit
                exitFlag = 1;
                break;

            // Add more key processing here
            
            case 'w':  // exit
                if (currentMotion == IDLE || currentMotion == LEFT || currentMotion == RIGHT)
                    currentMotion = UP;
                break;
            // Add more key processing here

            case 'a':  // exit
                if (currentMotion == IDLE || currentMotion == UP || currentMotion == DOWN)
                    currentMotion = LEFT;
                break;
            // Add more key processing here  

            case 's':  // exit
                if (currentMotion == IDLE || currentMotion == LEFT || currentMotion == RIGHT)
                    currentMotion = DOWN;
                break;

            case 'd':  // exit
                if (currentMotion == IDLE || currentMotion == UP || currentMotion == DOWN)
                    currentMotion = RIGHT;
                break;  

            case '1':  // exit
                play_speed = 100000;
                break;
            
            case '2':  // exit
                play_speed = 200000;
                break;

            case '3':  // exit
                play_speed = 300000;
                break;

            case '4':  // exit
                play_speed = 400000;
                break;

            case '5':  // exit
                play_speed = 500000;
                break;

            

        }
        input = 0;

        level = play_speed / 1000;
        
    }



    // [TODO] : Next, you need to update the player location by 1 unit 
    //          in the direction stored in the program

    if (currentMotion == UP)
    {
        position.y--;
        if (position.y < 1)
        {
            position.y = 8; 
        }
    }

    if (currentMotion == LEFT)
    {
        position.x--;
        if (position.x < 1)
        {
            position.x = 18; 
        }
        
    }

    if (currentMotion == DOWN)
    {
        position.y++;
        if (position.y > 8)
        {
            position.y = 1; 
        }
    }

    if (currentMotion == RIGHT)
    {
        position.x++;
        if (position.x > 18)
        {
            position.x = 1; 
        }
        
    }

    
    // [TODO] : Heed the border wraparound!!!

    

}



// SCREEN DRAWING ROUTINE
/////////////////////////////////////////
void DrawScreen(void)
{
    // [TODO] : Implement the latest drawing logic as described in the lab manual
    //
    //  1. clear the current screen contents

    //  2. Iterate through each character location on the game board
    //     using the nested for-loop row-scanning setup.

    //  3. For every visited character location on the game board
    //          If on border on the game board, print a special character
    //          If at the player object position, print the player symbol
    //          Otherwise, print the space character
    //     Think about how you can format the screen contents to achieve the
    //     same layout as presented in the lab manual

    //  4. Print any debugging messages as seen needed below the game board.
    //     As discussed in class, leave these debugging messages in the program
    //     throughout your dev process, and only remove them when you are ready to release
    //     your code. 

    int i = 0;
    int j = 0;

    MacUILib_clearScreen();

    
        for (i = 0; i < 10; i++)
        {
            

            for (j = 0; j < 20; j++)
            {
                if (i == 0 || i == 9 || j == 0 || j == 19)
                {
                    MacUILib_printf("&");
                }

                else if (j == position.x && i == position.y)
                {
                    MacUILib_printf("%c", position.symbol);
                }
                 
                

                else 
                {
                    MacUILib_printf(" ");
                }
            }

            printf("\n");

            


            
        }

        MacUILib_printf("\nStandard WASD controls (w = up, a = left, s = down, d = right)");
        MacUILib_printf("\nplayer x-coordinate %d", position.x);
        MacUILib_printf("\nplayer y-coordinate %d\n", position.y);
        MacUILib_printf("\nClick any number 1-5 to play the according speed level");
        MacUILib_printf("\n1 being the fastest, 5 being the slowest");
        
        MacUILib_printf("\nCurrent Game Speed Delay: %f milliseconds\n", level);
        MacUILib_printf("\nsemi colon (;) to escape\n");

    

   


}



// PROGRAM LOOOP DELAYER ROUTINE
/////////////////////////////////////////
void LoopDelay(void)
{
    // Change the delaying constant to vary the movement speed.
    MacUILib_Delay(play_speed);    
}



// PROGRAM CLEANUP ROUTINE
/////////////////////////////////////////
// Recall from PPA1 - this is run only once at the end of the program
// for garbage collection and exit messages.
void CleanUp(void)
{
    MacUILib_uninit();
}



