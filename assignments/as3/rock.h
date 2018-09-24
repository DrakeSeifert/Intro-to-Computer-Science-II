/**********************************************************************************
 * Program Filename: rock.h
 * Author: Drake Seifert
 * Date: 5/9/15
 * Description: Rock, paper, scissors!
 * Input: tool type, strength of tool
 * Output: computer choices, winner, past results
 * ********************************************************************************/

#ifndef ROCK_H
#define ROCK_H
#include "./tool.h"

class rock : public tool {
	public:
		rock();
		rock(int);
		~rock();
};

#endif
