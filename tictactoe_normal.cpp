#include "pch.h"
#include"tictactoe.h"
#include <string>
#include <iostream>


using namespace std;

int main() {

	tictactoe game;

	std::cout << "let the game begin" << std::endl;

	game.init_game();

	return EXIT_SUCCESS;
}