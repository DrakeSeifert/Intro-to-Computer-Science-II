/**********************************************************************************
 * Program Filename: connect_four.h
 * Author: Drake Seifert
 * Date: 4/12/15
 * Description: Holds struct or as1
 * Input: None
 * Output: None
 * ********************************************************************************/

#ifndef CONNECT_FOUR_H
#define CONNECT_FOUR_H

struct game {
	char **board;
	char *checkp1;
	char *checkp2;
	int r, c, p;
	char p1;
	char p2;
};

bool is_valid_arguments_1(int argc); //in main
bool is_valid_arguments_2(char *info[]);
bool is_valid_arguments_3(char *info[]);
void set_game_info(game &connect, char *info[]);
void functions(game connect);

char** create_table(game &connect);
void player_color(game &connect);
void arr_set(game &connect);
void print_board(game connect);
char check_winner_p1(game connect);
char check_winner_p2(game connect);

#endif
