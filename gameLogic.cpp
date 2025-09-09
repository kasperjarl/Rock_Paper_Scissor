#include <iostream>
#include "invalidInput.h"
#include "gameLogic.h"

/*

- How do I figure out who wins?
	--> Do I want to use ints (0 = rock etc), char (r = rock) or string (rock = rock)?

- How do I keep the game runing until the end?


*/


// something is wrong in here. Doesn't clear properly
char userInput(const std::string& p1)
{

	while (true)
	{
		std::cout << p1 << " enter 'r' for rock, 'p' for paper or 's' for scissor: ";
		char pChoice{};
		std::cin >> pChoice;

		if (clearFailedExtraction())
		{
			std::cout << "Ooops, that input is invalid. Please try again.\n" <<
				"Enter 'r' for rock, 'p' for paper or 's' for scissor.\n";
			continue;
		}

		if (pChoice != 'r' || pChoice != 'p' || pChoice != 's')
		{
			std::cout << "Ooops, that input is invalid. Please try again.\n" <<
				"Enter 'r' for rock, 'p' for paper or 's' for scissor.\n";
			continue;
		}
		ignoreLine();
		return pChoice;
	}

	
}


void whoWins(char p1, char p2)
{

	// rock
	if (p1 == 'r' && p2 == 'r')
	{
		std::cout << "It's a draw!\n";
	}
	else if (p1 == 'r' && p2 == 'p')
	{
		std::cout << "Player 2 wins!\n";
	}
	else if (p1 == 'r' && p2 == 's')
	{
		std::cout << "Player 1 wins!\n";
	}

	// paper
	else if (p1 == 'p' && p2 == 'r')
	{
		std::cout << "Player 1 wins!\n";
	}
	else if (p1 == 'p' && p2 == 'p')
	{
		std::cout << "It's a draw!\n";
	}
	else if (p1 == 'p' && p2 == 's')
	{
		std::cout << "Player 2 wins!\n";
	}

	// scissor

	else if (p1 == 's' && p2 == 'r')
	{
		std::cout << "Player 2 wins!\n";
	}
	else if (p1 == 's' && p2 == 'p')
	{
		std::cout << "Player 1 wins!\n";
	}
	else
	{
		std::cout << "It's a draw!\n";
	}
}
