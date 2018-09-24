/**********************************************************************************
 * Program Filename: play_cf.cpp
 * Author: Drake Seifert
 * Date: 4/12/15
 * Description: Connect Four with any size board and any number of connects
 * Input: Board rows, board cols, number of pieces to connect, col input
 * Output: Display of board and where player's pieces lie
 * ********************************************************************************/

#include "./connect_four.h"

int main(int argc, char *argv[]) {
	class game connect;
	is_valid_arguments_1(argc);
	is_valid_arguments_2(argv);
	is_valid_arguments_3(argv);
	set_game_info(connect, argv);
	functions(connect);
	return 0;
}
