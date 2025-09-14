#pragma once
#include <iostream>

const std::string getName();
char userInput(const std::string& p1);
void rps(const std::string& player1, const std::string& player2);
int whoWins(char p1, char p2, const std::string& player1, const std::string& player2);