#include "./bike.h"

Bike::Bike():Vehicle(){
   seats = 0;
}

Bike::Bike(int x):Vehicle(x){
}

int Bike::get_toll_amnt(){
   return 0;
}


