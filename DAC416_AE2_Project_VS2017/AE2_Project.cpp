#include <windows.h>		// for sleep()
#include <iostream>
#include <conio.h>
#include <assert.h>
#include <vector>
#include <string>
#include "cMaze.h"
#include "cTimer.h"
#include "cVector2.h"
#include "cCostummaze.h"
#include "cMouse.h"


const int ESC_KEY = 27;

int main()
{
	// create a maze variable and create a new maze
	cCostummaze	maze;
	maze.createRandomSize();

	// print the maze
	maze.print();

	// Display timing updates
	std::cout << std::endl << std::endl << "Limit =  " << maze.getTimeLimit_ms() << " ms" << std::endl;
	std::cout << std::endl << "Press a key to start the mouse ...";
	_getch();

	// create a timer to keep track of elapsed time
	cTimer	timer;

	// create the "mouse"
	cMouse	mouse;
    
	// ensure the maze was created successfully with a start point
	cVector2 pos;
	maze.getStart(pos);	
	

	char		kPathChar = (char)'-';
	char		kRePathChar = (char)'X';
	char		kFloorChar = maze.getFloorChar();
	char		kExit = maze.getExitChar();
    
	 	do
	 	{
	 		// start keeping time
	 		timer.start();
    
	 		// make the mouse move - REPLACE WITH YOUR CODE

			cVector2 lastPos = pos;
			
			if (kFloorChar == maze.getStrings()[pos.y][pos.x+1])
			{
					pos.x++;
					maze.setPositionValue(pos, kPathChar);					
			}else	
			
			if (kFloorChar == maze.getStrings()[pos.y-1][pos.x])
			{
					pos.y--;
					maze.setPositionValue(pos, kPathChar);					
			}else	
			
			if (kFloorChar == maze.getStrings()[pos.y][pos.x-1])
			{					
					pos.x--;
					maze.setPositionValue(pos, kPathChar);					
			}else		
			
			if (kFloorChar == maze.getStrings()[pos.y+1][pos.x])
			{				
					pos.y++;
					maze.setPositionValue(pos, kPathChar);
			}			
			
			if (lastPos == pos)
			{
				if (kPathChar == maze.getStrings()[pos.y][pos.x + 1])
				{
					maze.setPositionValue(pos, kRePathChar);
					pos.x++;					
				}else
			
				if (kPathChar == maze.getStrings()[pos.y - 1][pos.x])
				{
					maze.setPositionValue(pos, kRePathChar);
					pos.y--;				
				}
				else
			
				if (kPathChar == maze.getStrings()[pos.y][pos.x - 1])
				{
					maze.setPositionValue(pos, kRePathChar);
					pos.x--;
					
				}
				else
			
				if (kPathChar == maze.getStrings()[pos.y + 1][pos.x])
				{
					maze.setPositionValue(pos, kRePathChar);
					pos.y++;					
				}
			}
			
			if (kExit == maze.getStrings()[pos.y][pos.x+1])
				mouse.checkCheese(true);
			else if (kExit == maze.getStrings()[pos.y-1][pos.x])
				mouse.checkCheese(true);
			else if (kExit == maze.getStrings()[pos.y][pos.x-1])
				mouse.checkCheese(true);
			else if (kExit == maze.getStrings()[pos.y+1][pos.x])
				mouse.checkCheese(true);
			else
				mouse.checkCheese(false);

	 		// stop keeping time
	 		timer.stop();			
    
            // print the maze
            maze.print();
    
            // Display timing updates
	 		std::cout << std::endl << std::endl << "Limit =  " << maze.getTimeLimit_ms() << " ms" << std::endl;
	 		std::cout << "Elapsed =  " << timer.getElapsed_ms() << " ms";
    
	 		// short delay between moves to make them visible
	 		Sleep(200);
    
	  		// Quit if Escape is pressed.
			if (_kbhit())
			{
				if (ESC_KEY == _getch())
					return 0;
			}

		} while (!mouse.FoundCheese());

		double elapsed = timer.getElapsed_ms();
		std::cout << std::endl << "Total Elapsed =  " << elapsed;
		std::cout << std::endl << std::endl << "Press a key to exit" << elapsed;
		std::cin.ignore();
		_getch();
}


