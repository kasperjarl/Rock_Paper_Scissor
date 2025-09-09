#include <iostream>
#include "gameLogic.h"
int main()
{

	// thinking something like..
	/*
	
	- Player class (we have two players)
		--> one should be able to be played by the computer (using random for choice)
	- Game logic (what wins over what)
	- Keeping score? Keep playing option?
	
	*/
	std::cout << "Hello World!\n";

	whoWins(userInput("Kasper"), userInput("Karina"));

	
	return 0;
}