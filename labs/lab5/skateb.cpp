#include "./skateb.h"

Skateb::Skateb():Vehicle(){
   seats = 0;
}

Skateb::Skateb(int x):Vehicle(x){
}

int Skateb::get_toll_amnt(){
   return 0;
}

