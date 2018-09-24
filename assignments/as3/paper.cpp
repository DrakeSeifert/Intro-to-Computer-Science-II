/**********************************************************************************
 * Program Filename: paper.cpp
 * Author: Drake Seifert
 * Date: 5/9/15
 * Description: Rock, paper, scissors!
 * Input: tool type, strength of tool
 * Output: computer choices, winner, past results
 * ********************************************************************************/

#include "./paper.h"
#include <iostream>
using namespace std;

paper::paper() : tool() {
	h_strength = 1;
	h_type = 'p';
}

paper::paper(int a) : tool(a) {
	h_strength = a;
	h_type = 'p';
}

paper::~paper() {
	h_strength = 1;
}
