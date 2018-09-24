/**********************************************************************************
 * Program Filename: game.cpp
 * Author: Drake Seifert
 * Date: 5/9/15
 * Description: Rock, paper, scissors!
 * Input: tool type, strength of tool
 * Output: computer choices, winner, past results
 * ********************************************************************************/

#include <iostream>
#include "./game.h"
using namespace std;

int game::h_wins = 0;
int game::c_wins = 0;
int game::ties = 0;

game::game() {
	human = NULL;
	computer = NULL;
}

game::~game() {
	delete [] human;
	delete [] computer;
}

game::game(const game &a) {
	human = new tool [3];
	for (int i = 0; i < 3; i++) {
		human[i] = a.human[i];
	}
	computer = new tool [3];
	for (int i = 0; i < 3; i++) {
		computer[i] = a.computer[i];
	}
}

void game::operator = (const game &a) {
	if (human != NULL)
		delete [] human;
	if (computer != NULL)
		delete [] computer;
	human = new tool [3];
	for (int i = 0; i < 3; i++) {
		human[i] = a.human[i];
	}
	computer = new tool [3];
	for (int i = 0; i < 3; i++) {
		computer[i] = a.computer[i];
	}
}

int game::human_wins_1(tool rps) {
	char a = rps.h_type;
	char b = rps.c_type;
	if ((a=='r' && b=='s') || (a=='p' && b=='r') || (a=='s' && b=='p'))
		h_wins++;
	return h_wins;
}

int game::computer_wins_1(tool rps) {
	char b = rps.h_type;
	char a = rps.c_type;
	if ((a=='r' && b=='s') || (a=='p' && b=='r') || (a=='s' && b=='p'))
		c_wins++;
	return c_wins;
}

int game::tie_game_1(tool rps) {
	if (rps.h_type == rps.c_type)
		ties++;
	return ties;
}

int game::human_wins_2(tool rps) {
	if (rps.h_strength > rps.c_strength)
		h_wins++;
	return h_wins;
}

int game::computer_wins_2(tool rps) {
	if (rps.c_strength > rps.h_strength)
		c_wins++;
	return c_wins;

}

int game::tie_game_2(tool rps) {
	if (rps.h_strength == rps.c_strength)
		ties++;
	return ties;
}
