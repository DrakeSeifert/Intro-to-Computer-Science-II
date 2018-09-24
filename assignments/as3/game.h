/**********************************************************************************
 * Program Filename: game.h
 * Author: Drake Seifert
 * Date: 5/9/15
 * Description: Rock, paper, scissors!
 * Input: tool type, strength of tool
 * Output: computer choices, winner, past results
 * ********************************************************************************/

#ifndef GAME_H
#define GAME_H
#include "./tool.h"

class game {
	public:
		friend class tool;
		game();
		~game();                        //destructor
		game(const game &);             //copy constructor
		void operator = (const game &); //operator overload

		int human_wins_1(tool rps);
		int computer_wins_1(tool rps);
		int tie_game_1(tool rps);

		int human_wins_2(tool rps);
		int computer_wins_2(tool rps);
		int tie_game_2(tool rps);
		

	private:
		tool *human;
		tool *computer;
		static int h_wins;
		static int c_wins;
		static int ties;
};

#endif
