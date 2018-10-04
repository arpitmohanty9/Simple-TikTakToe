#include "pch.h"
#include "tictactoe.h"
#include <string>
#include <iostream>

std::string board[][5] = {
						{ "[ ]", "[ ]", "[ ]", "0 "},
						{ "[ ]", "[ ]", "[ ]", "1 " },
						{ "[ ]", "[ ]", "[ ]", "2 " },
						{ " 0 ", " 1 ", " 2 ", "  "}
};


tictactoe::tictactoe()
{	
}

void tictactoe::init_game()
{
	char player = 'X';
	bool gameOver = false;
	print_board();
	//single game iteration
	do {
		get_player_input(player);
		print_board();

		if (check_win_condition(player)) {
			std::cout << std::endl << "Congratulations player " << player << "!!!!!!!!!!!! You have Won!!!!!!!!!!!!!" << std::endl;
			gameOver = true;
			std::cout << std::endl << "FInal game state is" << std::endl;

		}
		if (roundcount >= 9)
		{	
			std::cout << "Its a Tie!!" << std::endl;
			gameOver = true;
		}
		player = switch_players(player);
	} while (!gameOver);

	print_board();


}



void tictactoe::print_board()
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			std::cout << board[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void tictactoe::get_player_input(char player)
{
	char player_input;
	std::cout <<"Player "<< player <<" enter the square number where you want to put your symbol(1-9)" << std::endl;
	std::cin >> player_input;
	// as c++ takes ascii of the character(numeric), I reduce it to equivalent number
	int player_input_value = player_input - '0';
	if(player_input_value > 0 && player_input_value <= 9)
	{
		int x_value = (player_input_value - 1) / 3;
		int y_value = (player_input_value - 1) % 3;
		if (board[x_value][y_value] == "[ ]")
		{
			board[x_value][y_value] = std::string("[") + player + "]";
			roundcount++;
			std::cout << "game round count :" << roundcount << std::endl;;
		}
		else 
		{
			std::cout << "the square is entered square is already occupied; please chose another square" << std::endl;

			get_player_input(player);

		}
	}
	else 
	{
		std::cout << "the input is invalid ; please try giving another input" << std::endl;
		get_player_input(player);
	}


}

char tictactoe::switch_players(char player)
{

	if (player == 'X') {
		return '0';
	}
	else {
		return 'X';
	}

}

bool tictactoe::check_win_condition(char player)
{
	bool is_win = false;
	
	if (roundcount >= 5)
	{
		for (int row = 0; !is_win && row < 4; row++) {
			int col = 0;
			is_win = check_win_line(board[row][col], board[row][col+1], board[row][col+2], player);
		
		}
		for (int col = 0; !is_win && col < 4; col++) {
			int row = 0;
			is_win = check_win_line(board[row][col], board[row+1][col], board[row+2][col], player);
		}

	
		is_win = check_win_line(board[0][0], board[1][1], board[2][2], player);

		is_win = check_win_line(board[0][2], board[1][1], board[0][2], player);
	}

	return is_win;
}

bool tictactoe::check_win_line(std::string square1, std::string square2, std::string square3, char player)
{
	return	square1 == std::string("[") + player + "]" &&
			square2 == std::string("[") + player + "]" &&
			square3 == std::string("[") + player + "]";
}

