/**********************************************************************************
 * Program Filename: tool.h
 * Author: Drake Seifert
 * Date: 5/9/15
 * Description: Rock, paper, scissors!
 * Input: tool type, strength of tool
 * Output: computer choices, winner, past results
 * ********************************************************************************/

#ifndef TOOL_H
#define TOOL_H

class tool {
	public:
		friend class game;
		tool();
		tool(int);
		~tool();
		tool(const tool &);
		void operator = (const tool &);

		float get_h_strength();
		char get_h_type();
		float get_c_strength();
		char get_c_type();
		
		void set_h_strength();
		void set_h_type();
		void set_c_strength();
		void set_c_type();

		void fight(tool);

	protected:
		float h_strength;
		char h_type;
		float c_strength;
		char c_type;
};

#endif
