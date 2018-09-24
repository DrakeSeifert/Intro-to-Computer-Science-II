/**********************************************************************************
 * Program Filename: paper.h
 * Author: Drake Seifert
 * Date: 5/9/15
 * Description: Rock, paper, scissors!
 * Input: tool type, strength of tool
 * Output: computer choices, winner, past results
 * ********************************************************************************/

#ifndef PAPER_H
#define PAPER_H
#include "./tool.h"

class paper : public tool {
	public:
		paper();
		paper(int);
		~paper();
};

#endif
