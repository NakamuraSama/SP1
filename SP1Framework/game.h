#ifndef _GAME_H
#define _GAME_H

#include "Framework\timer.h"

extern StopWatch g_timer;
extern bool g_quitGame;
extern int gamestate;
extern const unsigned char FPS; // FPS of this game
extern const unsigned int frameTime; // time for each frame

enum Keys
{
    K_UP,
    K_DOWN,
    K_LEFT,
    K_RIGHT,
	K_SPACE,
    K_ESCAPE,
    K_COUNT
};

enum Sequence //to check what screen the player is at
{
        MENU,
		GAME,
        ENDGAME,
};

void init();                // initialize your variables, allocate memory, etc
void getInput();            // get input from player
void update(double dt);     // update the game and the state of the game
void render();              // renders the current state of the game to the console
void shutdown();            // do clean up, free memory

void loadlevelone(); // Load level 1
void renderlevelone(); // Render level 1
//Character Movements
void jump(); //jump function...
void gravity(); //fall function...
void moveLeft(); //move left...
void moveRight(); //move right..

//player environment intewractions.
void trap();


#endif // _GAME_H