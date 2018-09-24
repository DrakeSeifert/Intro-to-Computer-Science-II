/**********************************************************************************
 * Program Filename: as1.cpp
 * Author: Drake Seifert
 * Date: 4/12/15
 * Description: Connect Four with any size board and any number of connects
 * Input: Board rows, board cols, number of pieces to connect, col input
 * Output: Display of board and where player's pieces lie
 * ********************************************************************************/

#include "./connect_four.h"
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

/***********************************************************************************
 * Function: is_valid_arguments_1
 * Description: checks for valid number of arguments
 * Parameters: argc
 * Pre-Conditions: command line input
 * Post-Conditions: error checks
 * *********************************************************************************/

bool is_valid_arguments_1(int argc) {
	if (argc != 7) {
		cout << "Error: Invalid number of arguments :(" << endl;
		exit(EXIT_FAILURE);
	}
	return true;
}

/***********************************************************************************
 * Function: is_valid_arguments_2
 * Description: checks if r, c, and p arguments are valid
 * Parameters: *info[]
 * Pre-Conditions: command line input
 * Post-Conditions: error checks
 * *********************************************************************************/

bool is_valid_arguments_2(char *info[]) {
	if (strcmp(info[1], "-r") && strcmp(info[1], "-c") && strcmp(info[1], "-p")) {
		cout << "Error! Invalid argument entered :(" << endl;
		exit(EXIT_FAILURE);
	}
	else if (strcmp(info[3], "-r") && strcmp(info[3], "-c") && strcmp(info[3], "-p")) {
		cout << "Error! Invalid argument entered :(" << endl;
		exit(EXIT_FAILURE);
	}
	else if (strcmp(info[5], "-r") && strcmp(info[5], "-c") && strcmp(info[5], "-p")) {
		cout << "Error! Invalid argument entered :(" << endl;
		exit(EXIT_FAILURE);
	}
	if (!strcmp(info[1], info[3]) || !strcmp(info[1], info[5]) || !strcmp(info[3], info[5])) {
		cout << "Error! Invalid argument entered :(" << endl;
		exit(EXIT_FAILURE);
	}
	return true;
}

/***********************************************************************************
 * Function: is_valid_arguments_3
 * Description: checks if integer arguments are valid
 * Parameters: *info[]
 * Pre-Conditions: command line input
 * Post-Conditions: error checks
 * *********************************************************************************/

bool is_valid_arguments_3(char *info[]) {
	for (int i = 2; i <= 6 ; i += 2) {
		if (*info[i] < '1' || *info[i] > '9') {
			if      (!strcmp(info[i - 1], "-r")) {
				cout << "Error! Please enter a valid number of rows: ";
				cin >> *info[i];
				is_valid_arguments_3(info);
			}
			else if (!strcmp(info[i - 1], "-c")) {
				cout << "Error! Please enter a valid number of cols: ";
				cin >> *info[i];
				is_valid_arguments_3(info);
			}
			else if (!strcmp(info[i - 1], "-p")) {
				cout << "Error! Please enter a valid number of pieces: ";
				cin >> *info[i];
				is_valid_arguments_3(info);
			}
		}
	}
	return true;
}

/***********************************************************************************
 * Function: set_game_info
 * Description: sets values to rows, cols, and pieces
 * Parameters: game, *info[]
 * Pre-Conditions: command line input
 * Post-Conditions: assigns values
 * *********************************************************************************/

void set_game_info(game &connect, char *info[]) {
	for (int i = 1; i <= 6; i += 2) {
		int x;
		if (!strcmp(info[i], "-r")) {
			x = atoi(info[i + 1]);
			connect.r = x;
		}
		if (!strcmp(info[i], "-c")) {
			x = atoi(info[i + 1]);
			connect.c = x;
		}
		if (!strcmp(info[i], "-p")) {
			x = atoi(info[i + 1]);
			connect.p = x;
		}
	}
		while (connect.p > connect.r || connect.p > connect.c || cin.fail()) {
			cout << "Pieces cannot be larger than columns or rows! Please re-enter: ";
			cin.clear();
			cin.ignore();
			cin >> connect.p;
		}
}

/***********************************************************************************
 * Function: player_color
 * Description: asks player what color they want
 * Parameters: game
 * Pre-Conditions: none
 * Post-Conditions: gives p1 and p2 a color
 * *********************************************************************************/

void player_color(game &connect) {
	char color;
	cout << "Player one, do you want red or yellow (r or y)? ";
	cin >> color;
	if      (color == 'r') {
		connect.p1 = 'r';
		connect.p2 = 'y';
	}
	else if (color == 'y') {
		connect.p1 = 'y';
		connect.p2 = 'r';
	}
	else {
		cout << "Invalid Input D: I guess I'll have to decide for you. Player one gets red!" << endl;
		connect.p1 = 'r';
		connect.p2 = 'y';
	}
}

/***********************************************************************************
 * Function: create_table
 * Description: creates table
 * Parameters: game
 * Pre-Conditions: none
 * Post-Conditions: creates table
 * *********************************************************************************/

char** create_table(game &connect) {
	char **table;
	table = new char*[connect.c];
	for (int i = 0; i < connect.c; i++)
		table[i] = new char[connect.r];
	connect.board = table;
}

/***********************************************************************************
 * Function: create_arr1
 * Description: creates array
 * Parameters: game
 * Pre-Conditions: none
 * Post-Conditions: creates array
 * *********************************************************************************/

char* create_arr1(game &connect) {
	char *arr1;
	arr1 = new char[connect.p];
	connect.checkp1 = arr1;
	for (int i = 0; i < connect.p; i++)
		connect.checkp1[i] = NULL;
}

/***********************************************************************************
 * Function: create_arr2
 * Description: creates array
 * Parameters: game
 * Pre-Conditions: none
 * Post-Conditions: creates array
 * *********************************************************************************/

char* create_arr2(game &connect) {
	char *arr2;
	arr2 = new char[connect.p];
	connect.checkp2 = arr2;
	for (int i = 0; i < connect.p; i++)
		connect.checkp2[i] = NULL;
}

/***********************************************************************************
 * Function: arr_set
 * Description: sets all elements of 2d array to a space
 * Parameters: game
 * Pre-Conditions: none
 * Post-Conditions: board is empty
 * *********************************************************************************/

void arr_set(game &connect) {
	for (int h = 0; h < connect.r; h++) {
		for (int i = 0; i < connect.c; i++) {
			connect.board[i][h] = ' ';
		}
	}
}

/***********************************************************************************
 * Function: print_board
 * Description: prints board
 * Parameters: game
 * Pre-Conditions: none
 * Post-Conditions: prints board
 * *********************************************************************************/

void print_board(game connect) {
	system("clear");
	for (int h = 0; h < connect.r; h++) {
		for (int i = 0; i < connect.c; i++)
			cout << "|" << connect.board[i][h];
		cout << "|" << endl << "-";
		for (int j = 0; j < connect.c; j++)
			cout << "--";
		cout << endl;
	}
}

/***********************************************************************************
 * Function: play_game_p1
 * Description: asks user what col they want
 * Parameters: game
 * Pre-Conditions: none
 * Post-Conditions: sets p1's piece to selected col
 * *********************************************************************************/

void play_game_p1(game connect) {
	int num, row = connect.r - 1;
	cout << "Player 1, which column would you like to put your piece? ";
	cin >> num;
	while(num < 1 || num > connect.c || connect.board[num - 1][0] != ' ' || cin.fail()) {
		cout << "Please enter a valid column: ";
		cin.clear();
		cin.ignore();
		cin >> num;
	}
	int col = num - 1;
	for (int i = 0; i < connect.r; i++) {
		if (connect.board[col][row - i] == ' ') {
			connect.board[col][row - i] = connect.p1;
			break;
		}
	}
	print_board(connect);
}

/***********************************************************************************
 * Function: see play_game_p1
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 * *********************************************************************************/

void play_game_p2(game connect) {
	int num, row = connect.r - 1;
	cout << "Player 2, which column would you like to put your piece? ";
	cin >> num;
	while(num < 1 || num > connect.c || connect.board[num - 1][0] != ' ' || cin.fail()) {
		cout << "Please enter a valid column: ";
		cin.clear();
		cin.ignore();
		cin >> num;
	}
	int col = num - 1;
	for (int i = 0; i < connect.r; i++) {
		if (connect.board[col][row - i] == ' ') {
			connect.board[col][row - i] = connect.p2;
			break;
		}
	}
	print_board(connect);
}

/***********************************************************************************
 * Function: check_tie
 * Description: checks if game is a tie
 * Parameters: game
 * Pre-Conditions: game is played
 * Post-Conditions: returns true if a tie and false if not
 * *********************************************************************************/

bool check_tie(game connect) {
	int num = 0;
	for (int i = 0; i < connect.c; i++) {
		if (connect.board[i][0] != ' ')
			num++;
	}
	if (num == connect.c)
		return true;
	return false;
}

/***********************************************************************************
 * Function: play_game
 * Description: loops until someone wins or there is a tie
 * Parameters: game
 * Pre-Conditions: none
 * Post-Conditions: displays who wins
 * *********************************************************************************/

void play_game(game connect) {
	char x, y;
	while (1) {
		play_game_p1(connect);
		x = check_winner_p1(connect);
		if (x == connect.p1) {
			cout << "Player 1 wins!" << endl;
			return;
		}
		else if (check_tie(connect)) {
			cout << "It's a tie!" << endl;
			return;
		}
		play_game_p2(connect);
		y = check_winner_p2(connect);
		if (y == connect.p2) {
			cout << "Player 2 wins!" << endl;
			return;
		}
		else if (check_tie(connect)) {
			cout << "It's a tie!" << endl;
			return;
		}
	}
}

/***********************************************************************************
 * Function: check_arr_p1
 * Description: checks if player got p pieces in a row
 * Parameters: game
 * Pre-Conditions: game has started
 * Post-Conditions: returns true if player gets p pieces in a row
 * *********************************************************************************/

bool check_arr_p1(game connect) {
	for (int i = 0; i < connect.p; i++) {
		if (connect.checkp1[i] != connect.p1) {
			for (int j = 0; j < connect.p; j++) {
				connect.checkp1[j] = NULL;
			}
			return false;
		}
	}
	return true;
}

/***********************************************************************************
 * Function: see check_arr_p1
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 * *********************************************************************************/

bool check_arr_p2(game connect) {
	for (int i = 0; i < connect.p; i++) {
		if (connect.checkp2[i] != connect.p2) {
			for (int j = 0; j < connect.p; j++) {
				connect.checkp2[j] = NULL;
			}
			return false;
		}
	}
	return true;
}

/***********************************************************************************
 * Function: find_vert_p1
 * Description: checks for vertical win
 * Parameters: game
 * Pre-Conditions: game has started
 * Post-Conditions: returns winner if vertical win
 * *********************************************************************************/

char find_vert_p1(game connect) {
	for (int x = 0; x < connect.c; x++) {
		for (int y = 0; y < connect.r - (connect.p - 1); y++) {
			for (int i = 0; i < connect.p; i++) {
				if (connect.board[x][y + i] == connect.p1 || connect.board[x][y + i] == connect.p2) {
					connect.checkp1[i] = connect.board[x][y + i];
					if (i == connect.p - 1) {
						if (check_arr_p1(connect)) {
							return connect.p1;
						}
					}
				}
			}
			for (int j = 0; j < connect.p; j++) {
				connect.checkp1[j] = NULL;
			}
		}
	}
	return 'a';
}

/***********************************************************************************
 * Function: see find_vert_p1
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 * *********************************************************************************/

char find_vert_p2(game connect) {
	for (int x = 0; x < connect.c; x++) {
		for (int y = 0; y < connect.r - (connect.p - 1); y++) {
			for (int i = 0; i < connect.p; i++) {
				if (connect.board[x][y + i] == connect.p1 || connect.board[x][y + i] == connect.p2) {
					connect.checkp2[i] = connect.board[x][y + i];
					if (i == connect.p - 1) {
						if (check_arr_p2(connect)) {
							return connect.p2;
						}
					}
				}
			}
			for (int j = 0; j < connect.p; j++) {
				connect.checkp2[j] = NULL;
			}
		}
	}
	return 'a';
}

/***********************************************************************************
 * Function: find_hor_p1
 * Description: checks for horizontal win
 * Parameters: game
 * Pre-Conditions: game has started
 * Post-Conditions: returns winner if horizontal win
 * *********************************************************************************/

char find_hor_p1(game connect) {
	for (int x = 0; x < connect.c - (connect.p - 1); x++) {
		for (int y = 0; y < connect.r; y++) {
			for (int i = 0; i < connect.p; i++) {
				if (connect.board[x + i][y] == connect.p1 || connect.board[x + i][y] == connect.p2) {
					connect.checkp1[i] = connect.board[x + i][y];
					if (i == connect.p - 1) {
						if (check_arr_p1(connect)) {
							return connect.p1;
						}
					}
				}
			}
			for (int j = 0; j < connect.p; j++) {
				connect.checkp1[j] = NULL;
			}
		}
	}
	return 'a';
}

/***********************************************************************************
 * Function: see find_hor_p1
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 * *********************************************************************************/

char find_hor_p2(game connect) {
	for (int x = 0; x < connect.c - (connect.p - 1); x++) {
		for (int y = 0; y < connect.r; y++) {
			for (int i = 0; i < connect.p; i++) {
				if (connect.board[x + i][y] == connect.p1 || connect.board[x + i][y] == connect.p2) {
					connect.checkp2[i] = connect.board[x + i][y];
					if (i == connect.p - 1) {
						if (check_arr_p2(connect)) {
							cout << "p2 hor" << endl;
							return connect.p2;
						}
					}
				}
			}
			for (int j = 0; j < connect.p; j++) {
				connect.checkp2[j] = NULL;
			}
		}
	}
	return 'a';
}

/***********************************************************************************
 * Function: find_pos_diag_p1
 * Description: finds positive diagonal shape
 * Parameters: game
 * Pre-Conditions: game has started
 * Post-Conditions: returns winner if positive diag win
 * *********************************************************************************/

char find_pos_diag_p1(game connect) {
	for (int x = 0; x < connect.c - (connect.p - 1); x++) {
		for (int y = (connect.p - 1); y < connect.r; y++) {
			for (int i = 0; i < connect.p; i++) {
				if (connect.board[x + i][y - i] == connect.p1 || connect.board[x + i][y + i] == connect.p2) {
					connect.checkp1[i] = connect.board[x + i][y - i];
					if (i == connect.p - 1) {
						if (check_arr_p1(connect))
							return connect.p1;
					}
				}
			}
			for (int j = 0; j < connect.p; j++) {
				connect.checkp1[j] = NULL;
			}
		}
	}
	return 'a';
}

/***********************************************************************************
 * Function: find_pos_diag_p1
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 * *********************************************************************************/

char find_pos_diag_p2(game connect) {
	for (int x = 0; x < connect.c - (connect.p - 1); x++) {
		for (int y = (connect.p - 1); y < connect.r; y++) {
			for (int i = 0; i < connect.p; i++) {
				if (connect.board[x + i][y - i] == connect.p1 || connect.board[x + i][y - i] == connect.p2) {
					connect.checkp2[i] = connect.board[x + i][y - i];
					if (i == connect.p - 1) {
						if (check_arr_p2(connect))
							return connect.p2;
					}
				}
			}
			for (int j = 0; j < connect.p; j++) {
				connect.checkp2[j] = NULL;
			}
		}
	}
	return 'a';
}

/***********************************************************************************
 * Function: find_neg_diag_p1
 * Description: finds negative diagonal shape
 * Parameters: game
 * Pre-Conditions: game has started
 * Post-Conditions: returns winner if neg diag win
 * *********************************************************************************/

char find_neg_diag_p1(game connect) {
	for (int x = 0; x < connect.c - (connect.p - 1); x++) {
		for (int y = 0; y < connect.r - (connect.p - 1); y++) {
			for (int i = 0; i < connect.p; i++) {
				if (connect.board[x + i][y + i] == connect.p1 || connect.board[x + i][y + i] == connect.p2) {
					connect.checkp1[i] = connect.board[x + i][y + i];
					if (i == connect.p - 1) {
						if (check_arr_p1(connect))
							return connect.p1;
					}
				}
			}
			for (int j = 0; j < connect.p; j++) {
				connect.checkp1[j] = NULL;
			}
		}
	}
}

/***********************************************************************************
 * Function: see find_neg_diag_p1
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 * *********************************************************************************/

char find_neg_diag_p2(game connect) {
	for (int x = 0; x < connect.c - (connect.p - 1); x++) {
		for (int y = 0; y < connect.r - (connect.p - 1); y++) {
			for (int i = 0; i < connect.p; i++) {
				if (connect.board[x + i][y + i] == connect.p1 || connect.board[x + i][y + i] == connect.p2) {
					connect.checkp2[i] = connect.board[x + i][y + i];
					if (i == connect.p - 1) {
						if (check_arr_p2(connect))
							return connect.p2;
					}
				}
			}
			for (int j = 0; j < connect.p; j++) {
				connect.checkp2[j] = NULL;
			}
		}
	}
}

/***********************************************************************************
 * Function: check_winner_p1
 * Description: checks if one of the shapes returned the winner
 * Parameters: game
 * Pre-Conditions: game has started
 * Post-Conditions: returns winner if there is one
 * *********************************************************************************/

char check_winner_p1(game connect) {
	char e = connect.p1;

	if (find_vert_p1(connect) == e || find_hor_p1(connect) == e || find_pos_diag_p1(connect) == e || find_neg_diag_p1(connect) == e)
		return e;

	else
		return 'a';
}

/***********************************************************************************
 * Function: see check_winner_p1
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 * *********************************************************************************/

char check_winner_p2(game connect) {
	char e = connect.p2;
	if (find_vert_p2(connect) == e || find_hor_p2(connect) == e || find_pos_diag_p2(connect) == e || find_neg_diag_p2(connect) == e)
		return connect.p2;
	else
		return 'a';
}

/***********************************************************************************
 * Function: delete_table
 * Description: deletes table
 * Parameters: game
 * Pre-Conditions: game has finished
 * Post-Conditions: deletes all arrays
 * *********************************************************************************/

void delete_table(game connect) {
	for (int i = 0; i < connect.c; i++)
		delete [] connect.board[i];
	delete [] connect.board;

	delete [] connect.checkp1;
	delete [] connect.checkp2;
}

/***********************************************************************************
 * Function: play_again
 * Description: asks user if they want to play again
 * Parameters: none
 * Pre-Conditions: game has finished
 * Post-Conditions: returns true or false
 * *********************************************************************************/

bool play_again() {
	bool ans;
	cout << "Would you like to play again? (0 - no, 1 - yes): ";
	cin >> ans;
	return ans;
}

/***********************************************************************************
 * Function: functions
 * Description: holds game playing functions in a loop
 * Parameters: game
 * Pre-Conditions: none
 * Post-Conditions: restarts game or exits
 * *********************************************************************************/

void functions(game connect) {
	int x = 1;
	while(x) {
	create_table(connect);
	create_arr1(connect);
	create_arr2(connect);
	player_color(connect);
	arr_set(connect);
	print_board(connect);
	play_game(connect);
	delete_table(connect);
	x = play_again();
	}
	cout << "Goodbye!" << endl;

}
