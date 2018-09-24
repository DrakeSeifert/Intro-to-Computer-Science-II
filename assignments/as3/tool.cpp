/**********************************************************************************
 * Program Filename: tool.cpp
 * Author: Drake Seifert
 * Date: 5/9/15
 * Description: Rock, paper, scissors!
 * Input: tool type, strength of tool
 * Output: computer choices, winner, past results
 * ********************************************************************************/

#include "./tool.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

tool::tool() {
	h_strength = c_strength = 1;
	h_type = c_type = 'a';
}

tool::tool(int a) {
	h_strength = a;
}

tool::~tool() {
	h_strength = c_strength = 1;
	h_type = c_type = 'a';
}

tool::tool(const tool &a) {
	h_strength = a.h_strength;
	h_type = a.h_type;
	c_strength = a.c_strength;
	c_type = a.c_type;
}

void tool::operator = (const tool &a) {
	h_strength = a.h_strength;
	h_type = a.h_type;
	c_strength = a.c_strength;
	c_type = a.c_type;
}

float tool::get_h_strength() {
	return h_strength;
}

char tool::get_h_type() {
	return h_type;
}

float tool::get_c_strength() {
	return c_strength;
}

char tool::get_c_type() {
	return c_type;
}

void tool::set_h_strength() {
	cout << "what would you like the strength to be?: ";
	cin >> h_strength;
}

void tool::set_h_type() {
	cout << "Choose your tool (r-rock, p-paper, s-scissors, e-exit): ";
	cin >> h_type;
	if (h_type == 'e')
		exit(EXIT_FAILURE);
}

void tool::set_c_strength() { //random strength between 1 and 100
	c_strength = rand() % 101 + 1;
	cout << "Computer chose strength : " << c_strength << endl;
}

void tool::set_c_type() { //random tool selection
	char letters[] = "rps";
	c_type = letters[rand() % 3];
	cout << "Computer chose " << c_type << endl;
}

void tool::fight(tool rps) {
	char a = rps.h_type;
	char b = rps.c_type;
	if ((a=='r' && b=='s') || (a=='p' && b=='r') || (a=='s' && b=='p')) {
		h_strength *= 2;
		c_strength *= 0.5;
	}
	else if ((b=='r' && a=='s') || (b=='p' && a=='r') || (b=='s' && a=='p')) {
		h_strength *= 0.5;
		c_strength *= 2;
	}	
	if (h_strength > c_strength)
		cout << "You win!!" << endl << endl;
	else if (c_strength > h_strength)
		cout << "Computer wins ¯\\_(ツ)_/¯" << endl << endl;
	else
		cout << "Tie game!" << endl << endl;
}
