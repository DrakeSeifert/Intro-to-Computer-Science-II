/**********************************************************************************
 * Program Filename: rock.cpp
 * Author: Drake Seifert
 * Date: 5/9/15
 * Description: Rock, paper, scissors!
 * Input: tool type, strength of tool
 * Output: computer choices, winner, past results
 * ********************************************************************************/

#include "./rock.h"
#include <iostream>
using namespace std;

rock::rock() : tool() {
	h_strength = 1;
	h_type = 'r';
}

rock::rock(int a) : tool(a) {
	h_strength = a;
	h_type = 'r';
}

rock::~rock() {
	h_strength = 1;
}
