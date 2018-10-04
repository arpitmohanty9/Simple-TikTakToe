#pragma once
#include <string>
#ifndef TICTACTOE_H_

#define TICTACTOE_H_



class tictactoe {
	
	public:
		tictactoe();

		void init_game();


	private:
		int roundcount = 0;
		void print_board();
		void get_player_input(char player);
		char switch_players(char player);
		bool check_win_condition(char player);
		bool check_win_line(std::string square1, std::string square2, std::string square3, char player);

};



#endif /* TICTACTOE_H_ */
