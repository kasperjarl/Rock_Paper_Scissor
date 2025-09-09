#include <iostream>
#include "invalidInput.h"
#include "gameLogic.h"

namespace constants
{
	// how many points to win
	const int max_points{ 3 };
	const int draw{ 0 };
	const int p1win{ 1 };
	const int p2win{ 2 };
}

//rock paper scissors main loop
void rps(const std::string& player1, const std::string& player2)
{
	int p1Points{ 0 };
	int p2Points{ 0 };

	while (p1Points < 3 && p2Points < 3)
	{
		if (whoWins(userInput(player1), userInput(player2), player1, player2) == constants::p1win)
		{
			++p1Points;
		}
		else if (whoWins(userInput(player1), userInput(player2), player1, player2) == constants::p2win)
		{
			++p2Points;
		}
	}

	if (p1Points == 3)
	{
		std::cout << player1 << " wins!\n";
	}
	else
	{
		std::cout << player2 << " wins!\n";
	}
}


char userInput(const std::string& p1)
{
	char pChoice{};
	while (true)
	{
		std::cout << p1 << " enter 'r' for rock, 'p' for paper or 's' for scissor: ";
		
		std::cin >> pChoice;

		if (clearFailedExtraction())
		{
			std::cout << "Ooops, that input is invalid. Please try again.\n" <<
				"Enter 'r' for rock, 'p' for paper or 's' for scissor.\n";
			continue;
		}

		// || pChoice == 'p' || pChoice == 's'
		if ((pChoice != 'r') && (pChoice != 'p') && (pChoice != 's'))
		{
			std::cout << "Ooops, that input is invalid. Please try again.\n" <<
				"Enter 'r' for rock, 'p' for paper or 's' for scissor.\n";
			continue;
		}
		ignoreLine();
		return pChoice;
	}

	
}


int whoWins(char p1, char p2, const std::string& player1, const std::string& player2)
{

	// rock
	if (p1 == 'r' && p2 == 'r')
	{
		std::cout << "It's a draw!\n";
		return constants::draw;
	}
	else if (p1 == 'r' && p2 == 'p')
	{
		std::cout << player2 << " wins!\n";
		return constants::p2win;
	}
	else if (p1 == 'r' && p2 == 's')
	{
		std::cout << player1 << " wins!\n";
		return constants::p1win;
	}

	// paper
	else if (p1 == 'p' && p2 == 'r')
	{
		std::cout << player1 << " wins!\n";
		return constants::p1win;
	}
	else if (p1 == 'p' && p2 == 'p')
	{
		std::cout << "It's a draw!\n";
		return constants::draw;
	}
	else if (p1 == 'p' && p2 == 's')
	{
		std::cout << player2 << " wins!\n";
		return constants::p2win;
	}

	// scissor

	else if (p1 == 's' && p2 == 'r')
	{
		std::cout << player2 << " wins!\n";
		return constants::p2win;
	}
	else if (p1 == 's' && p2 == 'p')
	{
		std::cout << player1 << " wins!\n";
		return constants::p1win;
	}
	else
	{
		std::cout << "It's a draw!\n";
		return constants::draw;
	}
}
