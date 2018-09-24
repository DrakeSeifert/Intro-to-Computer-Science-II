/**********************************************************************************
 * Program Filename: sci.h
 * Author: Drake Seifert
 * Date: 5/9/15
 * Description: Rock, paper, scissors!
 * Input: tool type, strength of tool
 * Output: computer choices, winner, past results
 * ********************************************************************************/

#ifndef SCI_H
#define SCI_H
#include "./tool.h"

class sci : public tool {
	public:
		sci();
		sci(int);
		~sci();
};

#endif
