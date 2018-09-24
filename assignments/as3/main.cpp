/**********************************************************************************
 * Program Filename: main.cpp
 * Author: Drake Seifert
 * Date: 5/9/15
 * Description: Rock, paper, scissors!
 * Input: tool type, strength of tool
 * Output: computer choices, winner, past results
 * ********************************************************************************/

#include "./tool.h"
#include "./rock.h"
#include "./paper.h"
#include "./sci.h"
#include "./game.h"
#include <iostream>
#include <ctime>
#include <stdlib.h>
using namespace std;

void play_game_1(tool);
void play_game_2(tool);
void winner_1(tool);
void human_win(tool);
void computer_win(tool);
void print_results_1(tool);
void print_results_2(tool);

/************************************************************************************
 * Function: set_game
 * Description: asks user if they would like to use strengths
 * Parameters: tool rps
 * Pre-conditions: none
 * Post-conditions: user either plays with or without strengths
 * **********************************************************************************/

void set_game(tool rps) {
	char x;
	cout << "Welcome to rock, paper, scissors!!!!!!!" << endl;
	cout << "Do you want to play with strengths? (y - yes, n - no): ";
	cin >> x;
	while (x != 'y' && x != 'n') {
		cout << "Please enter y or n: ";
		cin >> x;
	}
	cout << endl;
	if      (x == 'n')
		play_game_1(rps);
	else if (x == 'y')
		play_game_2(rps);
}

/************************************************************************************
 * Function: play_game_1
 * Description: plays game without strengths
 * Parameters: tool rps
 * Pre-conditions: user chose game without strengths
 * Post-conditions: loops game until user exits
 * **********************************************************************************/

void play_game_1(tool rps) {
	while(1) {
		rps.set_h_type();
		rps.set_c_type();
		winner_1(rps);
		print_results_1(rps);
	}
}

/************************************************************************************
 * Function: play_game_2
 * Description: plays game with strengths
 * Parameters: tool rps
 * Pre-conditions: user chose game with strengths
 * Post-conditions: loops game until user exits
 * **********************************************************************************/

void play_game_2(tool rps) { //game with strengths
	while(1) {
		rps.set_h_type();
		rps.set_h_strength();
		rps.set_c_type();
		rps.set_c_strength();
		rps.fight(rps);
		print_results_2(rps);
	}
}

/************************************************************************************
 * Function: winner_1
 * Description: determines who won by comparing types
 * Parameters: tool rps
 * Pre-conditions: user chose game without strengths
 * Post-conditions: displays winner
 * **********************************************************************************/

void winner_1(tool rps) {
	char a = rps.get_h_type();
	char b = rps.get_c_type();
	if (a == b)
		cout << "Tie game!" << endl << endl;
	else if ((a=='r' && b=='s') || (a=='p' && b=='r') || (a=='s' && b=='p'))
		cout << "You win!!!" << endl << endl;
	else
		cout << "Computer wins ¯\\_(ツ)_/¯" << endl << endl;
}

/************************************************************************************
 * Function: print_results_1
 * Description: prints results of how many times you have won/lost/tied
 * Parameters: tool rps
 * Pre-conditions: you have played at least one game with no strengths
 * Post-conditions: prints results
 * **********************************************************************************/

void print_results_1(tool rps) {
	game results;
	cout << "Human wins: " << results.human_wins_1(rps) << endl;
	cout << "Computer wins: " << results.computer_wins_1(rps) << endl;
	cout << "Ties: " << results.tie_game_1(rps) << endl << endl;
}

/************************************************************************************
 * Function: print_results_2
 * Description: prints results of how many times you have won/lost/tied
 * Parameters: tool rps
 * Pre-conditions: you have played at least one game with strengths
 * Post-conditions: prints results
 * **********************************************************************************/

void print_results_2(tool rps) {
	game results;
	cout << "Human wins: " << results.human_wins_2(rps) << endl;
	cout << "Computer wins: " << results.computer_wins_2(rps) << endl;
	cout << "Ties: " << results.tie_game_2(rps) << endl << endl;
}

int main() {
	srand(time(NULL));
	tool rps;
	set_game(rps);
	return 0;
}
