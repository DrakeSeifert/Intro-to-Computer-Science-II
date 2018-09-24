/**********************************************************************************
 * Program Filename: sci.cpp
 * Author: Drake Seifert
 * Date: 5/9/15
 * Description: Rock, paper, scissors!
 * Input: tool type, strength of tool
 * Output: computer choices, winner, past results
 * ********************************************************************************/

#include "./sci.h"
#include <iostream>
using namespace std;

sci::sci() : tool() {
	h_strength = 1;
	h_type = 's';
}

sci::sci(int a) : tool(a) {
	h_strength = a;
	h_type = 's';
}

sci::~sci() {
	h_strength = 1;
}
