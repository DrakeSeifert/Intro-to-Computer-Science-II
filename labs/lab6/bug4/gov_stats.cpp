#include "nation.h"
#include "state.h"
#include <iostream>
using namespace std;

int main() {
   nation n;
   char name[100];
   state s[50];

   for(int i=0; i<5; i++) {
	   cout << "Enter the state name: ";
       cin.getline(name,100);
       s[i].set_name(name);
   }

   for(int i = 0; i < 5; i++) {
	s[i].display_name();
   }

   //n.display_states_info(s);

   return 0;
}
