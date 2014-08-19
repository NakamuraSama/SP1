// This is the main file for the game logic and function
//
//
#include "game.h"
#include "Framework\console.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

double elapsedTime;
double deltaTime;
bool keyPressed[K_COUNT];
int gamestate;
COORD charLocation;
COORD consoleSize;

std::string line0, line1, line2, line3, line4, line5, line6, line7, line8, line9, line10, line11, line12, line13, line14, line15, line16, line17, line18, line19, line20, line21, line22, line23; // Stores the level map
double jumpDelay = 0; //delay between change of Y coordinate when jumping.
double fallDelay = 0; //delay between change of Y coordinate when falling.
int hasLevelLoaded = 0; // to check if level has been rendered. if yes, stop 
int isJumping = 0, iJumped = 0; // check if player is jumping
int isFalling = 0; // check if player is falling. 
int playerhealth = 10; // Player health, default 100. Change accordingly

void init()
{
    // Set precision for floating point output
    std::cout << std::fixed << std::setprecision(3);

    SetConsoleTitle(L"SP1 Framework");

    // Get console width and height
    CONSOLE_SCREEN_BUFFER_INFO csbi; /* to get buffer info */     

    /* get the number of character cells in the current buffer */ 
    GetConsoleScreenBufferInfo( GetStdHandle( STD_OUTPUT_HANDLE ), &csbi );
    consoleSize.X = csbi.srWindow.Right + 1;
    consoleSize.Y = csbi.srWindow.Bottom + 1;

    // set the character's spawn location.
    charLocation.X = 5;
    charLocation.Y = 5;

    elapsedTime = 0.0;
	jumpDelay = 0.0;
	fallDelay = 0.0;
	isJumping = 0;
	isFalling = 0;
	hasLevelLoaded = 0;

	loadlevelone();

}

void jump()
{
	if ( charLocation.Y == 4 )
		{
			if ( line3[charLocation.X] != '#' && isJumping == 0 && line5[charLocation.X] == '#')
			{
				isJumping = 1; // currently jumping. can't jump again while midair

				if ( jumpDelay > 0.05 ) // when ready to jump~
				{
					gotoXY(charLocation);
					std::cout << " "; // clears only character
					charLocation.Y--; // JUMP!
					jumpDelay = 0; // reset jumpDelay.
				}

				while ( jumpDelay < 0.015 ) // until ready to make next jump... continue taking input
				{

					getInput();
					update(g_timer.getElapsedTime());
					render();
					g_timer.waitUntil(frameTime);
				}
				// started from 4, Y coordinate is now 3
				// jumpDelay will be high enough here!
				if ( line2[charLocation.X] != '#' ) // No wall above me!
				{
					if ( jumpDelay > 0.05 ) // when ready to jump~
					{
						gotoXY(charLocation);
						std::cout << " "; // clears only character
						charLocation.Y--; // JUMP!
						jumpDelay = 0; // reset jumpDelay.
						iJumped = 1; // Made the second jump!
					}

					while ( jumpDelay < 0.015 ) // until ready to make next jump... continue taking input
					{
						getInput();
						update(g_timer.getElapsedTime());
						render();
						g_timer.waitUntil(frameTime);
					}
				}
				// started from 4, Y coordinate is now 2
				// jumpDelay will be high enough here!
				if ( line1[charLocation.X] != '#' && iJumped == 1 ) // No wall above me!
				{
					if ( jumpDelay > 0.05 ) // when ready to jump~
					{
						gotoXY(charLocation);
						std::cout << " "; // clears only character
						charLocation.Y--; // JUMP!
					}
				}
			}
		} // if charLocation.Y == 4
		if ( charLocation.Y == 5 )
		{
			if ( line4[charLocation.X] != '#' && isJumping == 0  && line6[charLocation.X] == '#')
			{
				isJumping = 1; // currently jumping. can't jump again while midair

				if ( jumpDelay > 0.05 ) // when ready to jump~
				{
					gotoXY(charLocation);
					std::cout << " "; // clears only character
					charLocation.Y--; // JUMP!
					jumpDelay = 0; // reset jumpDelay.
				}

				while ( jumpDelay < 0.015 ) // until ready to make next jump... continue taking input
				{

					getInput();
					update(g_timer.getElapsedTime());
					render();
					g_timer.waitUntil(frameTime);
				}
				// started from 5, Y coordinate is now 4
				// jumpDelay will be high enough here!
				if ( line3[charLocation.X] != '#' ) // No wall above me!
				{
					if ( jumpDelay > 0.05 ) // when ready to jump~
					{
						gotoXY(charLocation);
						std::cout << " "; // clears only character
						charLocation.Y--; // JUMP!
						jumpDelay = 0; // reset jumpDelay.
						iJumped = 1; // Made the second jump!
					}

					while ( jumpDelay < 0.015 ) // until ready to make next jump... continue taking input
					{
						getInput();
						update(g_timer.getElapsedTime());
						render();
						g_timer.waitUntil(frameTime);
					}
				}
				// started from 5, Y coordinate is now 3
				// jumpDelay will be high enough here!
				if ( line2[charLocation.X] != '#' && iJumped == 1 ) // No wall above me!
				{
					if ( jumpDelay > 0.05 ) // when ready to jump~
					{
						gotoXY(charLocation);
						std::cout << " "; // clears only character
						charLocation.Y--; // JUMP!
					}
				}
			}
		} // if charLocation.Y == 5
		if ( charLocation.Y == 6 )
		{
			if ( line5[charLocation.X] != '#' && isJumping == 0  && line7[charLocation.X] == '#')
			{
				isJumping = 1; // currently jumping. can't jump again while midair

				if ( jumpDelay > 0.05 ) // when ready to jump~
				{
					gotoXY(charLocation);
					std::cout << " "; // clears only character
					charLocation.Y--; // JUMP!
					jumpDelay = 0; // reset jumpDelay.
				}

				while ( jumpDelay < 0.015 ) // until ready to make next jump... continue taking input
				{

					getInput();
					update(g_timer.getElapsedTime());
					render();
					g_timer.waitUntil(frameTime);
				}
				// started from 6, Y coordinate is now 5
				// jumpDelay will be high enough here!
				if ( line4[charLocation.X] != '#' ) // No wall above me!
				{
					if ( jumpDelay > 0.05 ) // when ready to jump~
					{
						gotoXY(charLocation);
						std::cout << " "; // clears only character
						charLocation.Y--; // JUMP!
						jumpDelay = 0; // reset jumpDelay.
						iJumped = 1; // Made the second jump!
					}

					while ( jumpDelay < 0.015 ) // until ready to make next jump... continue taking input
					{
						getInput();
						update(g_timer.getElapsedTime());
						render();
						g_timer.waitUntil(frameTime);
					}
				}
				// started from 6, Y coordinate is now 4
				// jumpDelay will be high enough here!
				if ( line3[charLocation.X] != '#' && iJumped == 1 ) // No wall above me!
				{
					if ( jumpDelay > 0.05 ) // when ready to jump~
					{
						gotoXY(charLocation);
						std::cout << " "; // clears only character
						charLocation.Y--; // JUMP!
					}
				}
			}
		} // if charLocation.Y == 6
		if ( charLocation.Y == 7 )
		{
			if ( line6[charLocation.X] != '#' && isJumping == 0  && line8[charLocation.X] == '#')
			{
				isJumping = 1; // currently jumping. can't jump again while midair

				if ( jumpDelay > 0.05 ) // when ready to jump~
				{
					gotoXY(charLocation);
					std::cout << " "; // clears only character
					charLocation.Y--; // JUMP!
					jumpDelay = 0; // reset jumpDelay.
				}

				while ( jumpDelay < 0.015 ) // until ready to make next jump... continue taking input
				{

					getInput();
					update(g_timer.getElapsedTime());
					render();
					g_timer.waitUntil(frameTime);
				}
				// started from 7, Y coordinate is now 6
				// jumpDelay will be high enough here!
				if ( line5[charLocation.X] != '#' ) // No wall above me!
				{
					if ( jumpDelay > 0.05 ) // when ready to jump~
					{
						gotoXY(charLocation);
						std::cout << " "; // clears only character
						charLocation.Y--; // JUMP!
						jumpDelay = 0; // reset jumpDelay.
						iJumped = 1; // Made the second jump!
					}

					while ( jumpDelay < 0.015 ) // until ready to make next jump... continue taking input
					{
						getInput();
						update(g_timer.getElapsedTime());
						render();
						g_timer.waitUntil(frameTime);
					}
				}
				// started from 7, Y coordinate is now 5
				// jumpDelay will be high enough here!
				if ( line4[charLocation.X] != '#' && iJumped == 1 ) // No wall above me!
				{
					if ( jumpDelay > 0.05 ) // when ready to jump~
					{
						gotoXY(charLocation);
						std::cout << " "; // clears only character
						charLocation.Y--; // JUMP!
					}
				}
			}
		} // if charLocation.Y == 7
		if ( charLocation.Y == 8 )
		{
			if ( line7[charLocation.X] != '#' && isJumping == 0  && line9[charLocation.X] == '#')
			{
				isJumping = 1; // currently jumping. can't jump again while midair

				if ( jumpDelay > 0.05 ) // when ready to jump~
				{
					gotoXY(charLocation);
					std::cout << " "; // clears only character
					charLocation.Y--; // JUMP!
					jumpDelay = 0; // reset jumpDelay.
				}

				while ( jumpDelay < 0.015 ) // until ready to make next jump... continue taking input
				{

					getInput();
					update(g_timer.getElapsedTime());
					render();
					g_timer.waitUntil(frameTime);
				}
				// started from 8, Y coordinate is now 7
				// jumpDelay will be high enough here!
				if ( line6[charLocation.X] != '#' ) // No wall above me!
				{
					if ( jumpDelay > 0.05 ) // when ready to jump~
					{
						gotoXY(charLocation);
						std::cout << " "; // clears only character
						charLocation.Y--; // JUMP!
						jumpDelay = 0; // reset jumpDelay.
						iJumped = 1; // Made the second jump!
					}

					while ( jumpDelay < 0.015 ) // until ready to make next jump... continue taking input
					{
						getInput();
						update(g_timer.getElapsedTime());
						render();
						g_timer.waitUntil(frameTime);
					}
				}
				// started from 8, Y coordinate is now 6
				// jumpDelay will be high enough here!
				if ( line5[charLocation.X] != '#' && iJumped == 1 ) // No wall above me!
				{
					if ( jumpDelay > 0.05 ) // when ready to jump~
					{
						gotoXY(charLocation);
						std::cout << " "; // clears only character
						charLocation.Y--; // JUMP!
					}
				}
			}
		} // if charLocation.Y == 8
		if ( charLocation.Y == 9 )
		{
			if ( line8[charLocation.X] != '#' && isJumping == 0  && line10[charLocation.X] == '#')
			{
				isJumping = 1; // currently jumping. can't jump again while midair

				if ( jumpDelay > 0.05 ) // when ready to jump~
				{
					gotoXY(charLocation);
					std::cout << " "; // clears only character
					charLocation.Y--; // JUMP!
					jumpDelay = 0; // reset jumpDelay.
				}

				while ( jumpDelay < 0.015 ) // until ready to make next jump... continue taking input
				{

					getInput();
					update(g_timer.getElapsedTime());
					render();
					g_timer.waitUntil(frameTime);
				}
				// started from 9, Y coordinate is now 8
				// jumpDelay will be high enough here!
				if ( line7[charLocation.X] != '#' ) // No wall above me!
				{
					if ( jumpDelay > 0.05 ) // when ready to jump~
					{
						gotoXY(charLocation);
						std::cout << " "; // clears only character
						charLocation.Y--; // JUMP!
						jumpDelay = 0; // reset jumpDelay.
						iJumped = 1; // Made the second jump!
					}

					while ( jumpDelay < 0.015 ) // until ready to make next jump... continue taking input
					{
						getInput();
						update(g_timer.getElapsedTime());
						render();
						g_timer.waitUntil(frameTime);
					}
				}
				// started from 9, Y coordinate is now 7
				// jumpDelay will be high enough here!
				if ( line6[charLocation.X] != '#' && iJumped == 1 ) // No wall above me!
				{
					if ( jumpDelay > 0.05 ) // when ready to jump~
					{
						gotoXY(charLocation);
						std::cout << " "; // clears only character
						charLocation.Y--; // JUMP!
					}
				}
			}
		} // if charLocation.Y == 9
		if ( charLocation.Y == 10 )
		{
			if ( line9[charLocation.X] != '#' && isJumping == 0 && line11[charLocation.X] == '#')
			{
				isJumping = 1; // currently jumping. can't jump again while midair

				if ( jumpDelay > 0.05 ) // when ready to jump~
				{
					gotoXY(charLocation);
					std::cout << " "; // clears only character
					charLocation.Y--; // JUMP!
					jumpDelay = 0; // reset jumpDelay.
				}

				while ( jumpDelay < 0.015 ) // until ready to make next jump... continue taking input
				{

					getInput();
					update(g_timer.getElapsedTime());
					render();
					g_timer.waitUntil(frameTime);
				}
				// started from 10, Y coordinate is now 9
				// jumpDelay will be high enough here!
				if ( line8[charLocation.X] != '#' ) // No wall above me!
				{
					if ( jumpDelay > 0.05 ) // when ready to jump~
					{
						gotoXY(charLocation);
						std::cout << " "; // clears only character
						charLocation.Y--; // JUMP!
						jumpDelay = 0; // reset jumpDelay.
						iJumped = 1; // Made the second jump!
					}

					while ( jumpDelay < 0.015 ) // until ready to make next jump... continue taking input
					{
						getInput();
						update(g_timer.getElapsedTime());
						render();
						g_timer.waitUntil(frameTime);
					}
				}
				// started from 10, Y coordinate is now 8
				// jumpDelay will be high enough here!
				if ( line7[charLocation.X] != '#' && iJumped == 1 ) // No wall above me!
				{
					if ( jumpDelay > 0.05 ) // when ready to jump~
					{
						gotoXY(charLocation);
						std::cout << " "; // clears only character
						charLocation.Y--; // JUMP!
					}
				}
			}
		} // if charLocation.Y == 10
		if ( charLocation.Y == 11 )
		{
			if ( line10[charLocation.X] != '#' && isJumping == 0 && line12[charLocation.X] == '#')
			{
				isJumping = 1; // currently jumping. can't jump again while midair

				if ( jumpDelay > 0.05 ) // when ready to jump~
				{
					gotoXY(charLocation);
					std::cout << " "; // clears only character
					charLocation.Y--; // JUMP!
					jumpDelay = 0; // reset jumpDelay.
				}

				while ( jumpDelay < 0.015 ) // until ready to make next jump... continue taking input
				{

					getInput();
					update(g_timer.getElapsedTime());
					render();
					g_timer.waitUntil(frameTime);
				}
				// started from 11, Y coordinate is now 10
				// jumpDelay will be high enough here!
				if ( line9[charLocation.X] != '#' ) // No wall above me!
				{
					if ( jumpDelay > 0.05 ) // when ready to jump~
					{
						gotoXY(charLocation);
						std::cout << " "; // clears only character
						charLocation.Y--; // JUMP!
						jumpDelay = 0; // reset jumpDelay.
						iJumped = 1; // Made the second jump!
					}

					while ( jumpDelay < 0.015 ) // until ready to make next jump... continue taking input
					{
						getInput();
						update(g_timer.getElapsedTime());
						render();
						g_timer.waitUntil(frameTime);
					}
				}
				// started from 11, Y coordinate is now 9
				// jumpDelay will be high enough here!
				if ( line8[charLocation.X] != '#' && iJumped == 1 ) // No wall above me!
				{
					if ( jumpDelay > 0.05 ) // when ready to jump~
					{
						gotoXY(charLocation);
						std::cout << " "; // clears only character
						charLocation.Y--; // JUMP!
					}
				}
			}
		} // if charLocation.Y == 11
		if ( charLocation.Y == 12 )
		{
			if ( line11[charLocation.X] != '#' && isJumping == 0 && line13[charLocation.X] == '#')
			{
				isJumping = 1; // currently jumping. can't jump again while midair

				if ( jumpDelay > 0.05 ) // when ready to jump~
				{
					gotoXY(charLocation);
					std::cout << " "; // clears only character
					charLocation.Y--; // JUMP!
					jumpDelay = 0; // reset jumpDelay.
				}

				while ( jumpDelay < 0.015 ) // until ready to make next jump... continue taking input
				{

					getInput();
					update(g_timer.getElapsedTime());
					render();
					g_timer.waitUntil(frameTime);
				}
				// started from 12, Y coordinate is now 11
				// jumpDelay will be high enough here!
				if ( line10[charLocation.X] != '#' ) // No wall above me!
				{
					if ( jumpDelay > 0.05 ) // when ready to jump~
					{
						gotoXY(charLocation);
						std::cout << " "; // clears only character
						charLocation.Y--; // JUMP!
						jumpDelay = 0; // reset jumpDelay.
						iJumped = 1; // Made the second jump!
					}

					while ( jumpDelay < 0.015 ) // until ready to make next jump... continue taking input
					{
						getInput();
						update(g_timer.getElapsedTime());
						render();
						g_timer.waitUntil(frameTime);
					}
				}
				// started from 12, Y coordinate is now 10
				// jumpDelay will be high enough here!
				if ( line9[charLocation.X] != '#' && iJumped == 1 ) // No wall above me!
				{
					if ( jumpDelay > 0.05 ) // when ready to jump~
					{
						gotoXY(charLocation);
						std::cout << " "; // clears only character
						charLocation.Y--; // JUMP!
					}
				}
			}
		} // if charLocation.Y == 12
		if ( charLocation.Y == 13 )
		{
			if ( line12[charLocation.X] != '#' && isJumping == 0  && line14[charLocation.X] == '#')
			{
				isJumping = 1; // currently jumping. can't jump again while midair

				if ( jumpDelay > 0.05 ) // when ready to jump~
				{
					gotoXY(charLocation);
					std::cout << " "; // clears only character
					charLocation.Y--; // JUMP!
					jumpDelay = 0; // reset jumpDelay.
				}

				while ( jumpDelay < 0.015 ) // until ready to make next jump... continue taking input
				{

					getInput();
					update(g_timer.getElapsedTime());
					render();
					g_timer.waitUntil(frameTime);
				}
				// started from 13, Y coordinate is now 12
				// jumpDelay will be high enough here!
				if ( line11[charLocation.X] != '#' ) // No wall above me!
				{
					if ( jumpDelay > 0.05 ) // when ready to jump~
					{
						gotoXY(charLocation);
						std::cout << " "; // clears only character
						charLocation.Y--; // JUMP!
						jumpDelay = 0; // reset jumpDelay.
						iJumped = 1; // Made the second jump!
					}

					while ( jumpDelay < 0.015 ) // until ready to make next jump... continue taking input
					{
						getInput();
						update(g_timer.getElapsedTime());
						render();
						g_timer.waitUntil(frameTime);
					}
				}
				// started from 13, Y coordinate is now 11
				// jumpDelay will be high enough here!
				if ( line10[charLocation.X] != '#' && iJumped == 1 ) // No wall above me!
				{
					if ( jumpDelay > 0.05 ) // when ready to jump~
					{
						gotoXY(charLocation);
						std::cout << " "; // clears only character
						charLocation.Y--; // JUMP!
					}
				}
			}
		} // if charLocation.Y == 13
		if ( charLocation.Y == 14 )
		{
			if ( line13[charLocation.X] != '#' && isJumping == 0  && line15[charLocation.X] == '#')
			{
				isJumping = 1; // currently jumping. can't jump again while midair

				if ( jumpDelay > 0.05 ) // when ready to jump~
				{
					gotoXY(charLocation);
					std::cout << " "; // clears only character
					charLocation.Y--; // JUMP!
					jumpDelay = 0; // reset jumpDelay.
				}

				while ( jumpDelay < 0.015 ) // until ready to make next jump... continue taking input
				{

					getInput();
					update(g_timer.getElapsedTime());
					render();
					g_timer.waitUntil(frameTime);
				}
				// started from 14, Y coordinate is now 13
				// jumpDelay will be high enough here!
				if ( line12[charLocation.X] != '#' ) // No wall above me!
				{
					if ( jumpDelay > 0.05 ) // when ready to jump~
					{
						gotoXY(charLocation);
						std::cout << " "; // clears only character
						charLocation.Y--; // JUMP!
						jumpDelay = 0; // reset jumpDelay.
						iJumped = 1; // Made the second jump!
					}

					while ( jumpDelay < 0.015 ) // until ready to make next jump... continue taking input
					{
						getInput();
						update(g_timer.getElapsedTime());
						render();
						g_timer.waitUntil(frameTime);
					}
				}
				// started from 14, Y coordinate is now 12
				// jumpDelay will be high enough here!
				if ( line11[charLocation.X] != '#' && iJumped == 1 ) // No wall above me!
				{
					if ( jumpDelay > 0.05 ) // when ready to jump~
					{
						gotoXY(charLocation);
						std::cout << " "; // clears only character
						charLocation.Y--; // JUMP!
					}
				}
			}
		} // if charLocation.Y == 14
		if ( charLocation.Y == 15 )
		{
			if ( line14[charLocation.X] != '#' && isJumping == 0  && line16[charLocation.X] == '#')
			{
				isJumping = 1; // currently jumping. can't jump again while midair

				if ( jumpDelay > 0.05 ) // when ready to jump~
				{
					gotoXY(charLocation);
					std::cout << " "; // clears only character
					charLocation.Y--; // JUMP!
					jumpDelay = 0; // reset jumpDelay.
				}

				while ( jumpDelay < 0.015 ) // until ready to make next jump... continue taking input
				{

					getInput();
					update(g_timer.getElapsedTime());
					render();
					g_timer.waitUntil(frameTime);
				}
				// started from 15, Y coordinate is now 14
				// jumpDelay will be high enough here!
				if ( line13[charLocation.X] != '#' ) // No wall above me!
				{
					if ( jumpDelay > 0.05 ) // when ready to jump~
					{
						gotoXY(charLocation);
						std::cout << " "; // clears only character
						charLocation.Y--; // JUMP!
						jumpDelay = 0; // reset jumpDelay.
						iJumped = 1; // Made the second jump!
					}

					while ( jumpDelay < 0.015 ) // until ready to make next jump... continue taking input
					{
						getInput();
						update(g_timer.getElapsedTime());
						render();
						g_timer.waitUntil(frameTime);
					}
				}
				// started from 15, Y coordinate is now 13
				// jumpDelay will be high enough here!
				if ( line12[charLocation.X] != '#' && iJumped == 1 ) // No wall above me!
				{
					if ( jumpDelay > 0.05 ) // when ready to jump~
					{
						gotoXY(charLocation);
						std::cout << " "; // clears only character
						charLocation.Y--; // JUMP!
					}
				}
			}
		} // if charLocation.Y == 15
		if ( charLocation.Y == 16 )
		{
			if ( line15[charLocation.X] != '#' && isJumping == 0  && line17[charLocation.X] == '#')
			{
				isJumping = 1; // currently jumping. can't jump again while midair

				if ( jumpDelay > 0.05 ) // when ready to jump~
				{
					gotoXY(charLocation);
					std::cout << " "; // clears only character
					charLocation.Y--; // JUMP!
					jumpDelay = 0; // reset jumpDelay.
				}

				while ( jumpDelay < 0.015 ) // until ready to make next jump... continue taking input
				{

					getInput();
					update(g_timer.getElapsedTime());
					render();
					g_timer.waitUntil(frameTime);
				}
				// started from 16, Y coordinate is now 15
				// jumpDelay will be high enough here!
				if ( line14[charLocation.X] != '#' ) // No wall above me!
				{
					if ( jumpDelay > 0.05 ) // when ready to jump~
					{
						gotoXY(charLocation);
						std::cout << " "; // clears only character
						charLocation.Y--; // JUMP!
						jumpDelay = 0; // reset jumpDelay.
						iJumped = 1; // Made the second jump!
					}

					while ( jumpDelay < 0.015 ) // until ready to make next jump... continue taking input
					{
						getInput();
						update(g_timer.getElapsedTime());
						render();
						g_timer.waitUntil(frameTime);
					}
				}
				// started from 16, Y coordinate is now 14
				// jumpDelay will be high enough here!
				if ( line13[charLocation.X] != '#' && iJumped == 1 ) // No wall above me!
				{
					if ( jumpDelay > 0.05 ) // when ready to jump~
					{
						gotoXY(charLocation);
						std::cout << " "; // clears only character
						charLocation.Y--; // JUMP!
					}
				}
			}
		} // if charLocation.Y == 16
		if ( charLocation.Y == 17 )
		{
			if ( line16[charLocation.X] != '#' && isJumping == 0  && line18[charLocation.X] == '#')
			{
				isJumping = 1; // currently jumping. can't jump again while midair

				if ( jumpDelay > 0.05 ) // when ready to jump~
				{
					gotoXY(charLocation);
					std::cout << " "; // clears only character
					charLocation.Y--; // JUMP!
					jumpDelay = 0; // reset jumpDelay.
				}

				while ( jumpDelay < 0.015 ) // until ready to make next jump... continue taking input
				{

					getInput();
					update(g_timer.getElapsedTime());
					render();
					g_timer.waitUntil(frameTime);
				}
				// started from 17, Y coordinate is now 16
				// jumpDelay will be high enough here!
				if ( line15[charLocation.X] != '#' ) // No wall above me!
				{
					if ( jumpDelay > 0.05 ) // when ready to jump~
					{
						gotoXY(charLocation);
						std::cout << " "; // clears only character
						charLocation.Y--; // JUMP!
						jumpDelay = 0; // reset jumpDelay.
						iJumped = 1; // Made the second jump!
					}

					while ( jumpDelay < 0.015 ) // until ready to make next jump... continue taking input
					{
						getInput();
						update(g_timer.getElapsedTime());
						render();
						g_timer.waitUntil(frameTime);
					}
				}
				// started from 17, Y coordinate is now 15
				// jumpDelay will be high enough here!
				if ( line14[charLocation.X] != '#' && iJumped == 1 ) // No wall above me!
				{
					if ( jumpDelay > 0.05 ) // when ready to jump~
					{
						gotoXY(charLocation);
						std::cout << " "; // clears only character
						charLocation.Y--; // JUMP!
					}
				}
			}
		} // if charLocation.Y == 17
		if ( charLocation.Y == 18 )
		{
			if ( line17[charLocation.X] != '#' && isJumping == 0  && line19[charLocation.X] == '#')
			{
				isJumping = 1; // currently jumping. can't jump again while midair

				if ( jumpDelay > 0.05 ) // when ready to jump~
				{
					gotoXY(charLocation);
					std::cout << " "; // clears only character
					charLocation.Y--; // JUMP!
					jumpDelay = 0; // reset jumpDelay.
				}

				while ( jumpDelay < 0.015 ) // until ready to make next jump... continue taking input
				{

					getInput();
					update(g_timer.getElapsedTime());
					render();
					g_timer.waitUntil(frameTime);
				}
				// started from 18, Y coordinate is now 17
				// jumpDelay will be high enough here!
				if ( line16[charLocation.X] != '#' ) // No wall above me!
				{
					if ( jumpDelay > 0.05 ) // when ready to jump~
					{
						gotoXY(charLocation);
						std::cout << " "; // clears only character
						charLocation.Y--; // JUMP!
						jumpDelay = 0; // reset jumpDelay.
						iJumped = 1; // Made the second jump!
					}

					while ( jumpDelay < 0.015 ) // until ready to make next jump... continue taking input
					{
						getInput();
						update(g_timer.getElapsedTime());
						render();
						g_timer.waitUntil(frameTime);
					}
				}
				// started from 18, Y coordinate is now 16
				// jumpDelay will be high enough here!
				if ( line15[charLocation.X] != '#' && iJumped == 1 ) // No wall above me!
				{
					if ( jumpDelay > 0.05 ) // when ready to jump~
					{
						gotoXY(charLocation);
						std::cout << " "; // clears only character
						charLocation.Y--; // JUMP!
					}
				}
			}
		} // if charLocation.Y == 18
		if ( charLocation.Y == 19 )
		{
			if ( line18[charLocation.X] != '#' && isJumping == 0  && line20[charLocation.X] == '#')
			{
				isJumping = 1; // currently jumping. can't jump again while midair

				if ( jumpDelay > 0.05 ) // when ready to jump~
				{
					gotoXY(charLocation);
					std::cout << " "; // clears only character
					charLocation.Y--; // JUMP!
					jumpDelay = 0; // reset jumpDelay.
				}

				while ( jumpDelay < 0.015 ) // until ready to make next jump... continue taking input
				{

					getInput();
					update(g_timer.getElapsedTime());
					render();
					g_timer.waitUntil(frameTime);
				}
				// started from 19, Y coordinate is now 18
				// jumpDelay will be high enough here!
				if ( line17[charLocation.X] != '#' ) // No wall above me!
				{
					if ( jumpDelay > 0.05 ) // when ready to jump~
					{
						gotoXY(charLocation);
						std::cout << " "; // clears only character
						charLocation.Y--; // JUMP!
						jumpDelay = 0; // reset jumpDelay.
						iJumped = 1; // Made the second jump!
					}

					while ( jumpDelay < 0.015 ) // until ready to make next jump... continue taking input
					{
						getInput();
						update(g_timer.getElapsedTime());
						render();
						g_timer.waitUntil(frameTime);
					}
				}
				// started from 19, Y coordinate is now 17
				// jumpDelay will be high enough here!
				if ( line16[charLocation.X] != '#' && iJumped == 1 ) // No wall above me!
				{
					if ( jumpDelay > 0.05 ) // when ready to jump~
					{
						gotoXY(charLocation);
						std::cout << " "; // clears only character
						charLocation.Y--; // JUMP!
					}
				}
			}
		} // if charLocation.Y == 19
		if ( charLocation.Y == 20 )
		{
			if ( line19[charLocation.X] != '#' && isJumping == 0  && line21[charLocation.X] == '#')
			{
				isJumping = 1; // currently jumping. can't jump again while midair

				if ( jumpDelay > 0.00 ) // when ready to jump~
				{
					gotoXY(charLocation);
					std::cout << " "; // clears only character
					charLocation.Y--; // JUMP!
					jumpDelay = 0; // reset jumpDelay.
				}

				while ( jumpDelay < 0.015 ) // until ready to make next jump... continue taking input
				{

					getInput();
					update(g_timer.getElapsedTime());
					render();
					g_timer.waitUntil(frameTime);
				}
				// started from 20, Y coordinate is now 19
				// jumpDelay will be high enough here!
				if ( line18[charLocation.X] != '#' ) // No wall above me!
				{
					if ( jumpDelay > 0.00 ) // when ready to jump~
					{
						gotoXY(charLocation);
						std::cout << " "; // clears only character
						charLocation.Y--; // JUMP!
						jumpDelay = 0; // reset jumpDelay.
						iJumped = 1; // Made the second jump!
					}

					while ( jumpDelay < 0.015 ) // until ready to make next jump... continue taking input
					{
						getInput();
						update(g_timer.getElapsedTime());
						render();
						g_timer.waitUntil(frameTime);
					}
				}
				// started from 20, Y coordinate is now 18
				// jumpDelay will be high enough here!
				if ( line17[charLocation.X] != '#' && iJumped == 1 ) // No wall above me!
				{
					if ( jumpDelay > 0.00 ) // when ready to jump~
					{
						gotoXY(charLocation);
						std::cout << " "; // clears only character
						charLocation.Y--; // JUMP!
					}
				}
			}
		} // if charLocation.Y == 20
		if ( charLocation.Y == 21 )
		{
			if ( line20[charLocation.X] != '#' && isJumping == 0  && line22[charLocation.X] == '#')
			{
				isJumping = 1; // currently jumping. can't jump again while midair

				if ( jumpDelay > 0.05 ) // when ready to jump~
				{
					gotoXY(charLocation);
					std::cout << " "; // clears only character
					charLocation.Y--; // JUMP!
					jumpDelay = 0; // reset jumpDelay.
				}

				while ( jumpDelay < 0.015 ) // until ready to make next jump... continue taking input
				{

					getInput();
					update(g_timer.getElapsedTime());
					render();
					g_timer.waitUntil(frameTime);
				}
				while ( jumpDelay < 0.015 ) // until ready to make next jump... continue taking input
				{

					getInput();
					update(g_timer.getElapsedTime());
					render();
					g_timer.waitUntil(frameTime);
				}
				// started from 21, Y coordinate is now 20
				// jumpDelay will be high enough here!
				if ( line19[charLocation.X] != '#' ) // No wall above me!
				{
					if ( jumpDelay > 0.05 ) // Jump!
					{
						gotoXY(charLocation);
						std::cout << " "; // clears only character
						charLocation.Y--; // JUMP!
						jumpDelay = 0; // reset jumpDelay.
						iJumped = 1; // Made the second jump!
					}

					while ( jumpDelay < 0.015 ) // until ready to make next jump... continue taking input
					{
						getInput();
						update(g_timer.getElapsedTime());
						render();
						g_timer.waitUntil(frameTime);
					}
				}
				// started from 21, Y coordinate is now 19
				// jumpDelay will be high enough here!
				if ( line18[charLocation.X] != '#' && iJumped == 1 ) // No wall above me!
				{
					if ( jumpDelay > 0.05 ) // Jump!
					{
						gotoXY(charLocation);
						std::cout << " "; // clears only character
						charLocation.Y--; // JUMP!
					}
				}
			}
		} // if charLocation.Y == 21
		if ( charLocation.Y == 22 )
		{
			if ( line21[charLocation.X] != '#' && isJumping == 0  && line23[charLocation.X] == '#')
			{
				isJumping = 1; // currently jumping. can't jump again while midair

				if ( jumpDelay > 0.05 ) // when ready to jump~
				{
					gotoXY(charLocation);
					std::cout << " "; // clears only character
					charLocation.Y--; // JUMP!
					jumpDelay = 0; // reset jumpDelay.
				}

				while ( jumpDelay < 0.015 ) // until ready to make next jump... continue taking input
				{

					getInput();
					update(g_timer.getElapsedTime());
					render();
					g_timer.waitUntil(frameTime);
				}
				// started from 22, Y coordinate is now 21
				// jumpDelay will be high enough here!
				if ( line20[charLocation.X] != '#' ) // No wall above me!
				{
					if ( jumpDelay > 0.05 ) // Jump!
					{
						gotoXY(charLocation);
						std::cout << " "; // clears only character
						charLocation.Y--; // JUMP!
						jumpDelay = 0; // reset jumpDelay.
						iJumped = 1; // Made the second jump!
					}

					while ( jumpDelay < 0.015 ) // until ready to make next jump... continue taking input
					{
						getInput();
						update(g_timer.getElapsedTime());
						render();
						g_timer.waitUntil(frameTime);
					}
				}
				// started from 22, Y coordinate is now 20
				// jumpDelay will be high enough here!
				if ( line19[charLocation.X] != '#' && iJumped == 1 ) // No wall above me!
				{
					if ( jumpDelay > 0.51 ) // Jump!
					{
						gotoXY(charLocation);
						std::cout << " "; // clears only character
						charLocation.Y--; // JUMP!
					}
				}
			}
		} // if charLocation.Y == 22
		if ( charLocation.Y == 23 )
		{
			if ( line22[charLocation.X] != '#' && isJumping == 0 )
			{
				isJumping = 1; // currently jumping. can't jump again while midair

				if ( jumpDelay > 0.05 ) // when ready to jump~
				{
					gotoXY(charLocation);
					std::cout << " "; // clears only character
					charLocation.Y--; // JUMP!
					jumpDelay = 0; // reset jumpDelay.
				}

				while ( jumpDelay < 0.015 ) // until ready to make next jump... continue taking input
				{

					getInput();
					update(g_timer.getElapsedTime());
					render();
					g_timer.waitUntil(frameTime);
				}
				// started from 23, Y coordinate is now 22
				// jumpDelay will be high enough here!
				if ( line21[charLocation.X] != '#' ) // No wall above me!
				{
					if ( jumpDelay > 0.05 ) // Jump!
					{
						gotoXY(charLocation);
						std::cout << " "; // clears only character
						charLocation.Y--; // JUMP!
						jumpDelay = 0; // reset jumpDelay.
						iJumped = 1; // Made the second jump!
					}

					while ( jumpDelay < 0.015 ) // until ready to make next jump... continue taking input
					{
						getInput();
						update(g_timer.getElapsedTime());
						render();
						g_timer.waitUntil(frameTime);
					}
				}
				// started from 23, Y coordinate is now 21
				// jumpDelay will be high enough here!
				if ( line20[charLocation.X] != '#' && iJumped == 1 ) // No wall above me!
				{
					if ( jumpDelay > 0.05 ) // Jump!
					{
						gotoXY(charLocation);
						std::cout << " "; // clears only character
						charLocation.Y--; // JUMP!
					}
				}
			}
		} // if charLocation.Y == 23
		isJumping = 0;
		iJumped = 0;
}

void moveLeft()
{
	if ( charLocation.Y == 2 )
	{
		if ( line2[charLocation.X -1] != '#' ) // There is no wall on the left!
		{
			gotoXY(charLocation);
			std::cout << " "; // clears only character
			--charLocation.X; // Move left!
		}
	} // if charLocation.Y == 2
	if ( charLocation.Y == 3 )
	{
		if ( line3[charLocation.X -1] != '#' ) // There is no wall on the left!
		{
			gotoXY(charLocation);
			std::cout << " "; // clears only character
			--charLocation.X; // Move left!
		}
	} // if charLocation.Y == 3
	if ( charLocation.Y == 4 )
	{
		if ( line4[charLocation.X -1] != '#' ) // There is no wall on the left!
		{
			gotoXY(charLocation);
			std::cout << " "; // clears only character
			--charLocation.X; // Move left!
		}
	} // if charLocation.Y == 4
	if ( charLocation.Y == 5 )
	{
		if ( line5[charLocation.X -1] != '#' ) // There is no wall on the left!
		{
			gotoXY(charLocation);
			std::cout << " "; // clears only character
			--charLocation.X; // Move left!
		}
	} // if charLocation.Y == 5
	if ( charLocation.Y == 6 )
	{
		if ( line6[charLocation.X -1] != '#' ) // There is no wall on the left!
		{
			gotoXY(charLocation);
			std::cout << " "; // clears only character
			--charLocation.X; // Move left!
		}
	} // if charLocation.Y == 6
	if ( charLocation.Y == 7 )
	{
		if ( line7[charLocation.X -1] != '#' ) // There is no wall on the left!
		{
			gotoXY(charLocation);
			std::cout << " "; // clears only character
			--charLocation.X; // Move left!
		}
	} // if charLocation.Y == 7
	if ( charLocation.Y == 8 )
	{
		if ( line8[charLocation.X -1] != '#' ) // There is no wall on the left!
		{
			gotoXY(charLocation);
			std::cout << " "; // clears only character
			--charLocation.X; // Move left!
		}
	} // if charLocation.Y == 8
	if ( charLocation.Y == 9 )
	{
		if ( line9[charLocation.X -1] != '#' ) // There is no wall on the left!
		{
			gotoXY(charLocation);
			std::cout << " "; // clears only character
			--charLocation.X; // Move left!
		}
	} // if charLocation.Y == 9
	if ( charLocation.Y == 10 )
	{
		if ( line10[charLocation.X -1] != '#' ) // There is no wall on the left!
		{
			gotoXY(charLocation);
			std::cout << " "; // clears only character
			--charLocation.X; // Move left!
		}
	} // if charLocation.Y == 10
	if ( charLocation.Y == 11 )
	{
		if ( line11[charLocation.X -1] != '#' ) // There is no wall on the left!
		{
			gotoXY(charLocation);
			std::cout << " "; // clears only character
			--charLocation.X; // Move left!
		}
	} // if charLocation.Y == 11
	if ( charLocation.Y == 12 )
	{
		if ( line12[charLocation.X -1] != '#' ) // There is no wall on the left!
		{
			gotoXY(charLocation);
			std::cout << " "; // clears only character
			--charLocation.X; // Move left!
		}
	} // if charLocation.Y == 12
	if ( charLocation.Y == 13 )
	{
		if ( line13[charLocation.X -1] != '#' ) // There is no wall on the left!
		{
			gotoXY(charLocation);
			std::cout << " "; // clears only character
			--charLocation.X; // Move left!
		}
	} // if charLocation.Y == 13
	if ( charLocation.Y == 14 )
	{
		if ( line14[charLocation.X -1] != '#' ) // There is no wall on the left!
		{
			gotoXY(charLocation);
			std::cout << " "; // clears only character
			--charLocation.X; // Move left!
		}
	} // if charLocation.Y == 14
	if ( charLocation.Y == 15 )
	{
		if ( line15[charLocation.X -1] != '#' ) // There is no wall on the left!
		{
			gotoXY(charLocation);
			std::cout << " "; // clears only character
			--charLocation.X; // Move left!
		}
	} // if charLocation.Y == 15
	if ( charLocation.Y == 16 )
	{
		if ( line16[charLocation.X -1] != '#' ) // There is no wall on the left!
		{
			gotoXY(charLocation);
			std::cout << " "; // clears only character
			--charLocation.X; // Move left!
		}
	} // if charLocation.Y == 16
	if ( charLocation.Y == 17 )
	{
		if ( line17[charLocation.X -1] != '#' ) // There is no wall on the left!
		{
			gotoXY(charLocation);
			std::cout << " "; // clears only character
			--charLocation.X; // Move left!
		}
	} // if charLocation.Y == 17
	if ( charLocation.Y == 18 )
	{
		if ( line18[charLocation.X -1] != '#' ) // There is no wall on the left!
		{
			gotoXY(charLocation);
			std::cout << " "; // clears only character
			--charLocation.X; // Move left!
		}
	} // if charLocation.Y == 18
	if ( charLocation.Y == 19 )
	{
		if ( line19[charLocation.X -1] != '#' ) // There is no wall on the left!
		{
			gotoXY(charLocation);
			std::cout << " "; // clears only character
			--charLocation.X; // Move left!
		}
	} // if charLocation.Y == 19
	if ( charLocation.Y == 20 )
	{
		if ( line20[charLocation.X -1] != '#' ) // There is no wall on the left!
		{
			gotoXY(charLocation);
			std::cout << " "; // clears only character
			--charLocation.X; // Move left!
		}
	} // if charLocation.Y == 20
	if ( charLocation.Y == 21 )
	{
		if ( line21[charLocation.X -1] != '#' ) // There is no wall on the left!
		{
			gotoXY(charLocation);
			std::cout << " "; // clears only character
			--charLocation.X; // Move left!
		}
	} // if charLocation.Y == 21
	if ( charLocation.Y == 22 )
	{
		if ( line22[charLocation.X -1] != '#' ) // There is no wall on the left!
		{
			gotoXY(charLocation);
			std::cout << " "; // clears only character
			--charLocation.X; // Move left!
		}
	} // if charLocation.Y == 22
}

void moveRight()
{
	if ( charLocation.Y == 2 )
	{
		if ( line2[charLocation.X +1] != '#' ) // There is no wall on the right!
		{
			gotoXY(charLocation);
			std::cout << " "; // clears only character
			++charLocation.X; // Move right!
		}
	} // if charLocation.Y == 2
	if ( charLocation.Y == 3 )
	{
		if ( line3[charLocation.X +1] != '#' ) // There is no wall on the right!
		{
			gotoXY(charLocation);
			std::cout << " "; // clears only character
			++charLocation.X; // Move right!
		}
	} // if charLocation.Y == 3
	if ( charLocation.Y == 4 )
	{
		if ( line4[charLocation.X +1] != '#' ) // There is no wall on the right!
		{
			gotoXY(charLocation);
			std::cout << " "; // clears only character
			++charLocation.X; // Move right!
		}
	} // if charLocation.Y == 4
	if ( charLocation.Y == 5 )
	{
		if ( line5[charLocation.X +1] != '#' ) // There is no wall on the right!
		{
			gotoXY(charLocation);
			std::cout << " "; // clears only character
			++charLocation.X; // Move right!
		}
	} // if charLocation.Y == 5
	if ( charLocation.Y == 6 )
	{
		if ( line6[charLocation.X +1] != '#' ) // There is no wall on the right!
		{
			gotoXY(charLocation);
			std::cout << " "; // clears only character
			++charLocation.X; // Move right!
		}
	} // if charLocation.Y == 6
	if ( charLocation.Y == 7 )
	{
		if ( line7[charLocation.X +1] != '#' ) // There is no wall on the right!
		{
			gotoXY(charLocation);
			std::cout << " "; // clears only character
			++charLocation.X; // Move right!
		}
	} // if charLocation.Y == 7
	if ( charLocation.Y == 8 )
	{
		if ( line8[charLocation.X +1] != '#' ) // There is no wall on the right!
		{
			gotoXY(charLocation);
			std::cout << " "; // clears only character
			++charLocation.X; // Move right!
		}
	} // if charLocation.Y == 8
	if ( charLocation.Y == 9 )
	{
		if ( line9[charLocation.X +1] != '#' ) // There is no wall on the right!
		{
			gotoXY(charLocation);
			std::cout << " "; // clears only character
			++charLocation.X; // Move right!
		}
	} // if charLocation.Y == 9
	if ( charLocation.Y == 10 )
	{
		if ( line10[charLocation.X +1] != '#' ) // There is no wall on the right!
		{
			gotoXY(charLocation);
			std::cout << " "; // clears only character
			++charLocation.X; // Move right!
		}
	} // if charLocation.Y == 10
	if ( charLocation.Y == 11 )
	{
		if ( line11[charLocation.X +1] != '#' ) // There is no wall on the right!
		{
			gotoXY(charLocation);
			std::cout << " "; // clears only character
			++charLocation.X; // Move right!
		}
	} // if charLocation.Y == 11
	if ( charLocation.Y == 12 )
	{
		if ( line12[charLocation.X +1] != '#' ) // There is no wall on the right!
		{
			gotoXY(charLocation);
			std::cout << " "; // clears only character
			++charLocation.X; // Move right!
		}
	} // if charLocation.Y == 12
	if ( charLocation.Y == 13 )
	{
		if ( line13[charLocation.X +1] != '#' ) // There is no wall on the right!
		{
			gotoXY(charLocation);
			std::cout << " "; // clears only character
			++charLocation.X; // Move right!
		}
	} // if charLocation.Y == 13
	if ( charLocation.Y == 14 )
	{
		if ( line14[charLocation.X +1] != '#' ) // There is no wall on the right!
		{
			gotoXY(charLocation);
			std::cout << " "; // clears only character
			++charLocation.X; // Move right!
		}
	} // if charLocation.Y == 14
	if ( charLocation.Y == 15 )
	{
		if ( line15[charLocation.X +1] != '#' ) // There is no wall on the right!
		{
			gotoXY(charLocation);
			std::cout << " "; // clears only character
			++charLocation.X; // Move right!
		}
	} // if charLocation.Y == 15
	if ( charLocation.Y == 16 )
	{
		if ( line16[charLocation.X +1] != '#' ) // There is no wall on the right!
		{
			gotoXY(charLocation);
			std::cout << " "; // clears only character
			++charLocation.X; // Move right!
		}
	} // if charLocation.Y == 16
	if ( charLocation.Y == 17 )
	{
		if ( line17[charLocation.X +1] != '#' ) // There is no wall on the right!
		{
			gotoXY(charLocation);
			std::cout << " "; // clears only character
			++charLocation.X; // Move right!
		}
	} // if charLocation.Y == 17
	if ( charLocation.Y == 18 )
	{
		if ( line18[charLocation.X +1] != '#' ) // There is no wall on the right!
		{
			gotoXY(charLocation);
			std::cout << " "; // clears only character
			++charLocation.X; // Move right!
		}
	} // if charLocation.Y == 18
	if ( charLocation.Y == 19 )
	{
		if ( line19[charLocation.X +1] != '#' ) // There is no wall on the right!
		{
			gotoXY(charLocation);
			std::cout << " "; // clears only character
			++charLocation.X; // Move right!
		}
	} // if charLocation.Y == 19
	if ( charLocation.Y == 20 )
	{
		if ( line20[charLocation.X +1] != '#' ) // There is no wall on the right!
		{
			gotoXY(charLocation);
			std::cout << " "; // clears only character
			++charLocation.X; // Move right!
		}
	} // if charLocation.Y == 20
	if ( charLocation.Y == 21 )
	{
		if ( line21[charLocation.X +1] != '#' ) // There is no wall on the right!
		{
			gotoXY(charLocation);
			std::cout << " "; // clears only character
			++charLocation.X; // Move right!
		}
	} // if charLocation.Y == 21
	if ( charLocation.Y == 22 )
	{
		if ( line22[charLocation.X +1] != '#' ) // There is no wall on the right!
		{
			gotoXY(charLocation);
			std::cout << " "; // clears only character
			++charLocation.X; // Move right!
		}
	} // if charLocation.Y == 22
}

void gravity()
{
	if ( charLocation.Y == 2 )
	{
		if ( line3[charLocation.X] != '#' && isJumping == 0 && isFalling == 0)
		{
			isFalling = 1;
			fallDelay = 0;
			while ( fallDelay < 0.01 ) // Delay between each fall ^^
			{
				getInput();
				update(g_timer.getElapsedTime());
				render();
				g_timer.waitUntil(frameTime);
			}
			gotoXY(charLocation);
			std::cout << " "; // clears only character
			++charLocation.Y; // Fall!
			isFalling = 0; // Not falling anymore
		}
		//If character got into a wall somehow
		if ( line2[charLocation.X] == '#' )
		{
			--charLocation.Y; // GET OUT OF MY WALL
			gotoXY(charLocation.X, charLocation.Y+1); //FIX THE GAP IN THE WALL
			std::cout << "#";
		}
	} // if charLocation.Y == 2
		if ( charLocation.Y == 3 )
	{
		if ( line4[charLocation.X] != '#' && isJumping == 0 && isFalling == 0)
		{
			isFalling = 1;
			fallDelay = 0;
			while ( fallDelay < 0.01 ) // Delay between each fall ^^
			{
				getInput();
				update(g_timer.getElapsedTime());
				render();
				g_timer.waitUntil(frameTime);
			}
			gotoXY(charLocation);
			std::cout << " "; // clears only character
			++charLocation.Y; // Fall!
			isFalling = 0; // Not falling anymore
		}
		//If character got into a wall somehow
		if ( line3[charLocation.X] == '#' )
		{
			--charLocation.Y; // GET OUT OF MY WALL
			gotoXY(charLocation.X, charLocation.Y+1); //FIX THE GAP IN THE WALL
			std::cout << "#";
		}
	} // if charLocation.Y == 3
	if ( charLocation.Y == 4 )
	{
		if ( line5[charLocation.X] != '#' && isJumping == 0 && isFalling == 0)
		{
			isFalling = 1;
			fallDelay = 0;
			while ( fallDelay < 0.01 ) // Delay between each fall ^^
			{
				getInput();
				update(g_timer.getElapsedTime());
				render();
				g_timer.waitUntil(frameTime);
			}
			gotoXY(charLocation);
			std::cout << " "; // clears only character
			++charLocation.Y; // Fall!
			isFalling = 0; // Not falling anymore
		}
		//If character got into a wall somehow
		if ( line4[charLocation.X] == '#' )
		{
			--charLocation.Y; // GET OUT OF MY WALL
			gotoXY(charLocation.X, charLocation.Y+1); //FIX THE GAP IN THE WALL
			std::cout << "#";
		}
	} // if charLocation.Y == 4
	if ( charLocation.Y == 5 )
	{
		if ( line6[charLocation.X] != '#' && isJumping == 0 && isFalling == 0)
		{
			isFalling = 1;
			fallDelay = 0;
			while ( fallDelay < 0.01 ) // Delay between each fall ^^
			{
				getInput();
				update(g_timer.getElapsedTime());
				render();
				g_timer.waitUntil(frameTime);
			}
			gotoXY(charLocation);
			std::cout << " "; // clears only character
			++charLocation.Y; // Fall!
			isFalling = 0; // Not falling anymore
		}
		//If character got into a wall somehow
		if ( line5[charLocation.X] == '#' )
		{
			--charLocation.Y; // GET OUT OF MY WALL
			gotoXY(charLocation.X, charLocation.Y+1); //FIX THE GAP IN THE WALL
			std::cout << "#";
		}
	} // if charLocation.Y == 5
	if ( charLocation.Y == 6 )
	{
		if ( line7[charLocation.X] != '#' && isJumping == 0 && isFalling == 0)
		{
			isFalling = 1;
			fallDelay = 0;
			while ( fallDelay < 0.01 ) // Delay between each fall ^^
			{
				getInput();
				update(g_timer.getElapsedTime());
				render();
				g_timer.waitUntil(frameTime);
			}
			gotoXY(charLocation);
			std::cout << " "; // clears only character
			++charLocation.Y; // Fall!
			isFalling = 0; // Not falling anymore
		}
		//If character got into a wall somehow
		if ( line6[charLocation.X] == '#' )
		{
			--charLocation.Y; // GET OUT OF MY WALL
			gotoXY(charLocation.X, charLocation.Y+1); //FIX THE GAP IN THE WALL
			std::cout << "#";
		}
	} // if charLocation.Y == 6
	if ( charLocation.Y == 7 )
	{
		if ( line8[charLocation.X] != '#' && isJumping == 0 && isFalling == 0)
		{
			isFalling = 1;
			fallDelay = 0;
			while ( fallDelay < 0.01 ) // Delay between each fall ^^
			{
				getInput();
				update(g_timer.getElapsedTime());
				render();
				g_timer.waitUntil(frameTime);
			}
			gotoXY(charLocation);
			std::cout << " "; // clears only character
			++charLocation.Y; // Fall!
			isFalling = 0; // Not falling anymore
		}
		//If character got into a wall somehow
		if ( line7[charLocation.X] == '#' )
		{
			--charLocation.Y; // GET OUT OF MY WALL
			gotoXY(charLocation.X, charLocation.Y+1); //FIX THE GAP IN THE WALL
			std::cout << "#";
		}
	} // if charLocation.Y == 7
	if ( charLocation.Y == 8 )
	{
		if ( line9[charLocation.X] != '#' && isJumping == 0 && isFalling == 0)
		{
			isFalling = 1;
			fallDelay = 0;
			while ( fallDelay < 0.01 ) // Delay between each fall ^^
			{
				getInput();
				update(g_timer.getElapsedTime());
				render();
				g_timer.waitUntil(frameTime);
			}
			gotoXY(charLocation);
			std::cout << " "; // clears only character
			++charLocation.Y; // Fall!
			isFalling = 0; // Not falling anymore
		}
		//If character got into a wall somehow
		if ( line8[charLocation.X] == '#' )
		{
			--charLocation.Y; // GET OUT OF MY WALL
			gotoXY(charLocation.X, charLocation.Y+1); //FIX THE GAP IN THE WALL
			std::cout << "#";
		}
	} // if charLocation.Y == 8
	if ( charLocation.Y == 9 )
	{
		if ( line10[charLocation.X] != '#' && isJumping == 0 && isFalling == 0)
		{
			isFalling = 1;
			fallDelay = 0;
			while ( fallDelay < 0.01 ) // Delay between each fall ^^
			{
				getInput();
				update(g_timer.getElapsedTime());
				render();
				g_timer.waitUntil(frameTime);
			}
			gotoXY(charLocation);
			std::cout << " "; // clears only character
			++charLocation.Y; // Fall!
			isFalling = 0; // Not falling anymore
		}
		//If character got into a wall somehow
		if ( line9[charLocation.X] == '#' )
		{
			--charLocation.Y; // GET OUT OF MY WALL
			gotoXY(charLocation.X, charLocation.Y+1); //FIX THE GAP IN THE WALL
			std::cout << "#";
		}
	} // if charLocation.Y == 9
	if ( charLocation.Y == 10 )
	{
		if ( line11[charLocation.X] != '#' && isJumping == 0 && isFalling == 0)
		{
			isFalling = 1;
			fallDelay = 0;
			while ( fallDelay < 0.01 ) // Delay between each fall ^^
			{
				getInput();
				update(g_timer.getElapsedTime());
				render();
				g_timer.waitUntil(frameTime);
			}
			gotoXY(charLocation);
			std::cout << " "; // clears only character
			++charLocation.Y; // Fall!
			isFalling = 0; // Not falling anymore
		}
		//If character got into a wall somehow
		if ( line10[charLocation.X] == '#' )
		{
			--charLocation.Y; // GET OUT OF MY WALL
			gotoXY(charLocation.X, charLocation.Y+1); //FIX THE GAP IN THE WALL
			std::cout << "#";
		}
	} // if charLocation.Y == 10
	if ( charLocation.Y == 11 )
	{
		if ( line12[charLocation.X] != '#' && isJumping == 0 && isFalling == 0)
		{
			isFalling = 1;
			fallDelay = 0;
			while ( fallDelay < 0.01 ) // Delay between each fall ^^
			{
				getInput();
				update(g_timer.getElapsedTime());
				render();
				g_timer.waitUntil(frameTime);
			}
			gotoXY(charLocation);
			std::cout << " "; // clears only character
			++charLocation.Y; // Fall!
			isFalling = 0; // Not falling anymore
		}
		//If character got into a wall somehow
		if ( line11[charLocation.X] == '#' )
		{
			--charLocation.Y; // GET OUT OF MY WALL
			gotoXY(charLocation.X, charLocation.Y+1); //FIX THE GAP IN THE WALL
			std::cout << "#";
		}
	} // if charLocation.Y == 11
	if ( charLocation.Y == 12 )
	{
		if ( line13[charLocation.X] != '#' && isJumping == 0 && isFalling == 0)
		{
			isFalling = 1;
			fallDelay = 0;
			while ( fallDelay < 0.01 ) // Delay between each fall ^^
			{
				getInput();
				update(g_timer.getElapsedTime());
				render();
				g_timer.waitUntil(frameTime);
			}
			gotoXY(charLocation);
			std::cout << " "; // clears only character
			++charLocation.Y; // Fall!
			isFalling = 0; // Not falling anymore
		}
		//If character got into a wall somehow
		if ( line12[charLocation.X] == '#' )
		{
			--charLocation.Y; // GET OUT OF MY WALL
			gotoXY(charLocation.X, charLocation.Y+1); //FIX THE GAP IN THE WALL
			std::cout << "#";
		}
	} // if charLocation.Y == 12
	if ( charLocation.Y == 13 )
	{
		if ( line14[charLocation.X] != '#' && isJumping == 0 && isFalling == 0)
		{
			isFalling = 1;
			fallDelay = 0;
			while ( fallDelay < 0.01 ) // Delay between each fall ^^
			{
				getInput();
				update(g_timer.getElapsedTime());
				render();
				g_timer.waitUntil(frameTime);
			}
			gotoXY(charLocation);
			std::cout << " "; // clears only character
			++charLocation.Y; // Fall!
			isFalling = 0; // Not falling anymore
		}
		//If character got into a wall somehow
		if ( line13[charLocation.X] == '#' )
		{
			--charLocation.Y; // GET OUT OF MY WALL
			gotoXY(charLocation.X, charLocation.Y+1); //FIX THE GAP IN THE WALL
			std::cout << "#";
		}
	} // if charLocation.Y == 13
	if ( charLocation.Y == 14 )
	{
		if ( line15[charLocation.X] != '#' && isJumping == 0 && isFalling == 0)
		{
			isFalling = 1;
			fallDelay = 0;
			while ( fallDelay < 0.01 ) // Delay between each fall ^^
			{
				getInput();
				update(g_timer.getElapsedTime());
				render();
				g_timer.waitUntil(frameTime);
			}
			gotoXY(charLocation);
			std::cout << " "; // clears only character
			++charLocation.Y; // Fall!
			isFalling = 0; // Not falling anymore
		}
		//If character got into a wall somehow
		if ( line14[charLocation.X] == '#' )
		{
			--charLocation.Y; // GET OUT OF MY WALL
			gotoXY(charLocation.X, charLocation.Y+1); //FIX THE GAP IN THE WALL
			std::cout << "#";
		}
	} // if charLocation.Y == 14
	if ( charLocation.Y == 15 )
	{
		if ( line16[charLocation.X] != '#' && isJumping == 0 && isFalling == 0)
		{
			isFalling = 1;
			fallDelay = 0;
			while ( fallDelay < 0.01 ) // Delay between each fall ^^
			{
				getInput();
				update(g_timer.getElapsedTime());
				render();
				g_timer.waitUntil(frameTime);
			}
			gotoXY(charLocation);
			std::cout << " "; // clears only character
			++charLocation.Y; // Fall!
			isFalling = 0; // Not falling anymore
		}
		//If character got into a wall somehow
		if ( line15[charLocation.X] == '#' )
		{
			--charLocation.Y; // GET OUT OF MY WALL
			gotoXY(charLocation.X, charLocation.Y+1); //FIX THE GAP IN THE WALL
			std::cout << "#";
		}
	} // if charLocation.Y == 15
	if ( charLocation.Y == 16 )
	{
		if ( line17[charLocation.X] != '#' && isJumping == 0 && isFalling == 0)
		{
			isFalling = 1;
			fallDelay = 0;
			while ( fallDelay < 0.01 ) // Delay between each fall ^^
			{
				getInput();
				update(g_timer.getElapsedTime());
				render();
				g_timer.waitUntil(frameTime);
			}
			gotoXY(charLocation);
			std::cout << " "; // clears only character
			++charLocation.Y; // Fall!
			isFalling = 0; // Not falling anymore
		}
		//If character got into a wall somehow
		if ( line16[charLocation.X] == '#' )
		{
			--charLocation.Y; // GET OUT OF MY WALL
			gotoXY(charLocation.X, charLocation.Y+1); //FIX THE GAP IN THE WALL
			std::cout << "#";
		}
	} // if charLocation.Y == 16
	if ( charLocation.Y == 17 )
	{
		if ( line18[charLocation.X] != '#' && isJumping == 0 && isFalling == 0)
		{
			isFalling = 1;
			fallDelay = 0;
			while ( fallDelay < 0.01 ) // Delay between each fall ^^
			{
				getInput();
				update(g_timer.getElapsedTime());
				render();
				g_timer.waitUntil(frameTime);
			}
			gotoXY(charLocation);
			std::cout << " "; // clears only character
			++charLocation.Y; // Fall!
			isFalling = 0; // Not falling anymore
		}
		//If character got into a wall somehow
		if ( line17[charLocation.X] == '#' )
		{
			--charLocation.Y; // GET OUT OF MY WALL
			gotoXY(charLocation.X, charLocation.Y+1); //FIX THE GAP IN THE WALL
			std::cout << "#";
		}
	} // if charLocation.Y == 17
	if ( charLocation.Y == 18 )
	{
		if ( line19[charLocation.X] != '#' && isJumping == 0 && isFalling == 0)
		{
			isFalling = 1;
			fallDelay = 0;
			while ( fallDelay < 0.01 ) // Delay between each fall ^^
			{
				getInput();
				update(g_timer.getElapsedTime());
				render();
				g_timer.waitUntil(frameTime);
			}
			gotoXY(charLocation);
			std::cout << " "; // clears only character
			++charLocation.Y; // Fall!
			isFalling = 0; // Not falling anymore
		}
		//If character got into a wall somehow
		if ( line18[charLocation.X] == '#' )
		{
			--charLocation.Y; // GET OUT OF MY WALL
			gotoXY(charLocation.X, charLocation.Y+1); //FIX THE GAP IN THE WALL
			std::cout << "#";
		}
	} // if charLocation.Y == 18
	if ( charLocation.Y == 19 )
	{
		if ( line20[charLocation.X] != '#' && isJumping == 0 && isFalling == 0)
		{
			isFalling = 1;
			fallDelay = 0;
			while ( fallDelay < 0.01 ) // Delay between each fall ^^
			{
				getInput();
				update(g_timer.getElapsedTime());
				render();
				g_timer.waitUntil(frameTime);
			}
			gotoXY(charLocation);
			std::cout << " "; // clears only character
			++charLocation.Y; // Fall!
			isFalling = 0; // Not falling anymore
		}
		//If character got into a wall somehow
		if ( line19[charLocation.X] == '#' )
		{
			--charLocation.Y; // GET OUT OF MY WALL
			gotoXY(charLocation.X, charLocation.Y+1); //FIX THE GAP IN THE WALL
			std::cout << "#";
		}
	} // if charLocation.Y == 19
	if ( charLocation.Y == 20 )
	{
		if ( line21[charLocation.X] != '#' && isJumping == 0 && isFalling == 0)
		{
			isFalling = 1;
			fallDelay = 0;
			while ( fallDelay < 0.01 ) // Delay between each fall ^^
			{
				getInput();
				update(g_timer.getElapsedTime());
				render();
				g_timer.waitUntil(frameTime);
			}
			gotoXY(charLocation);
			std::cout << " "; // clears only character
			++charLocation.Y; // Fall!
			isFalling = 0; // Not falling anymore
		}
		//If character got into a wall somehow
		if ( line20[charLocation.X] == '#' )
		{
			--charLocation.Y; // GET OUT OF MY WALL
			gotoXY(charLocation.X, charLocation.Y+1); //FIX THE GAP IN THE WALL
			std::cout << "#";
		}
	} // if charLocation.Y == 20
	if ( charLocation.Y == 21 )
	{
		if ( line22[charLocation.X] != '#' && isJumping == 0 && isFalling == 0)
		{
			isFalling = 1;
			fallDelay = 0;
			while ( fallDelay < 0.01 ) // Delay between each fall ^^
			{
				getInput();
				update(g_timer.getElapsedTime());
				render();
				g_timer.waitUntil(frameTime);
			}
			gotoXY(charLocation);
			std::cout << " "; // clears only character
			++charLocation.Y; // Fall!
			isFalling = 0; // Not falling anymore
		}
		//If character got into a wall somehow
		if ( line21[charLocation.X] == '#' )
		{
			--charLocation.Y; // GET OUT OF MY WALL
			gotoXY(charLocation.X, charLocation.Y+1); //FIX THE GAP IN THE WALL
			std::cout << "#";
		}
	} // if charLocation.Y == 21
	if ( charLocation.Y == 22 )
	{
		if ( line23[charLocation.X] != '#' && isJumping == 0 && isFalling == 0)
		{
			isFalling = 1;
			fallDelay = 0;
			while ( fallDelay < 0.01 ) // Delay between each fall ^^
			{
				getInput();
				update(g_timer.getElapsedTime());
				render();
				g_timer.waitUntil(frameTime);
			}
			gotoXY(charLocation);
			std::cout << " "; // clears only character
			++charLocation.Y; // Fall!
			isFalling = 0; // Not falling anymore
		}
		//If character got into a wall somehow
		if ( line22[charLocation.X] == '#' )
		{
			--charLocation.Y; // GET OUT OF MY WALL
			gotoXY(charLocation.X, charLocation.Y+1); //FIX THE GAP IN THE WALL
			std::cout << "#";
		}
	} // if charLocation.Y == 22

}

void trap()
{
	if(charLocation.Y == 1)
	{
		if(line1[charLocation.X] == 'x')
		{

		}
	}
}

void loadlevelone()
{
	std::string data;
	std::fstream LevelMap;
	LevelMap.open("level1.txt");

	getline(LevelMap, data);	line0 = data;
	getline(LevelMap, data);	line1 = data;
	getline(LevelMap, data);	line2 = data;
	getline(LevelMap, data);	line3 = data;
	getline(LevelMap, data);	line4 = data;
	getline(LevelMap, data);	line5 = data;
	getline(LevelMap, data);	line6 = data;
	getline(LevelMap, data);	line7 = data;
	getline(LevelMap, data);	line8 = data;
	getline(LevelMap, data);	line9 = data;
	getline(LevelMap, data);	line10 = data;
	getline(LevelMap, data);	line11 = data;
	getline(LevelMap, data);	line12 = data;
	getline(LevelMap, data);	line13 = data;
	getline(LevelMap, data);	line14 = data;
	getline(LevelMap, data);	line15 = data;
	getline(LevelMap, data);	line16 = data;
	getline(LevelMap, data);	line17 = data;
	getline(LevelMap, data);	line18 = data;
	getline(LevelMap, data);	line19 = data;
	getline(LevelMap, data);	line20 = data;
	getline(LevelMap, data);	line21 = data;
	getline(LevelMap, data);	line22 = data;
	getline(LevelMap, data);	line23 = data;
	
	LevelMap.close();

	while ( line2.length() < line1.length() )
		line2 += " ";

	while ( line3.length() < line1.length() )
		line3 += " ";

	while ( line4.length() < line1.length() )
		line4 += " ";

	while ( line5.length() < line1.length() )
		line5 += " ";

	while ( line6.length() < line1.length() )
		line6 += " ";

	while ( line7.length() < line1.length() )
		line7 += " ";

	while ( line8.length() < line1.length() )
		line8 += " ";

	while ( line9.length() < line1.length() )
		line9 += " ";

	while ( line10.length() < line1.length() )
		line10 += " ";

	while ( line11.length() < line1.length() )
		line11 += " ";

	while ( line12.length() < line1.length() )
		line12 += " ";

	while ( line13.length() < line1.length() )
		line13 += " ";

	while ( line14.length() < line1.length() )
		line14 += " ";

	while ( line15.length() < line1.length() )
		line15 += " ";

	while ( line16.length() < line1.length() )
		line16 += " ";

	while ( line17.length() < line1.length() )
		line17 += " ";

	while ( line18.length() < line1.length() )
		line18 += " ";

	while ( line19.length() < line1.length() )
		line19 += " ";

	while ( line20.length() < line1.length() )
		line20 += " ";

	while ( line21.length() < line1.length() )
		line21 += " ";

	while ( line22.length() < line1.length() )
		line22 += " ";

	while ( line23.length() < line1.length() )
		line23 += " ";
}

void renderlevelone() // renders level one
{
	gotoXY(0, 0); std::cout << line0;
	gotoXY(0, 1); std::cout << line1;
	gotoXY(0, 2); std::cout << line2;
	gotoXY(0, 3); std::cout << line3;
	gotoXY(0, 4); std::cout << line4;
	gotoXY(0, 5); std::cout << line5;
	gotoXY(0, 6); std::cout << line6;
	gotoXY(0, 7); std::cout << line7;
	gotoXY(0, 8); std::cout << line8;
	gotoXY(0, 9); std::cout << line9;
	gotoXY(0, 10); std::cout << line10;
	gotoXY(0, 11); std::cout << line11;
	gotoXY(0, 12); std::cout << line12;
	gotoXY(0, 13); std::cout << line13;
	gotoXY(0, 14); std::cout << line14;
	gotoXY(0, 15); std::cout << line15;
	gotoXY(0, 16); std::cout << line16;
	gotoXY(0, 17); std::cout << line17;
	gotoXY(0, 18); std::cout << line18;
	gotoXY(0, 19); std::cout << line19;
	gotoXY(0, 20); std::cout << line20;
	gotoXY(0, 21); std::cout << line21;
	gotoXY(0, 22); std::cout << line22;
	gotoXY(0, 23); std::cout << line23;
}

void shutdown()
{
    // Reset to white text on black background
	colour(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
}

void getInput()
{    
    keyPressed[K_UP] = isKeyPressed(VK_UP);
    keyPressed[K_DOWN] = isKeyPressed(VK_DOWN);
    keyPressed[K_LEFT] = isKeyPressed(VK_LEFT);
    keyPressed[K_RIGHT] = isKeyPressed(VK_RIGHT);
    keyPressed[K_ESCAPE] = isKeyPressed(VK_ESCAPE);
	keyPressed[K_SPACE] = isKeyPressed(VK_SPACE);
}

void update(double dt)
{
    // get the delta time
    elapsedTime += dt;
    deltaTime = dt;
	fallDelay += dt;
	jumpDelay += dt;

    // Updating the location of the character based on the key press
    if (keyPressed[K_LEFT] )
		moveLeft();

    if (keyPressed[K_RIGHT] )
		moveRight();

	if ( keyPressed [K_SPACE] && isJumping == 0 && jumpDelay > 0.8) // When trying to jump, make sure you're not already jumping and you haven't jumped in the past 0.8 seconds
		jump();

	// PFFT. SCREW GRAVITY (not) 
	gravity();

    // quits the game if player hits the escape key
    if (keyPressed[K_ESCAPE])
        g_quitGame = true;    
}

void render()
{
    colour(0x0F);

    //render the game
	//render the level map
	if ( hasLevelLoaded == 0 )
	{
		cls();
		renderlevelone();
		hasLevelLoaded = 1;
	}

    // render time taken to calculate this frame
    //gotoXY(70, 0);
    //std::cout << 1.0 / deltaTime << "fps" << std::endl;
  
    //gotoXY(0, 0);
    //std::cout << elapsedTime << "secs" << std::endl;

    // render character
    gotoXY(charLocation);
    colour(0x0C);
    std::cout << (char)1;

    colour(0x0F);
}