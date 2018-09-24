#include "./vehicle.h"
#include "./motorcycle.h"

Motorcycle::Motorcycle():Vehicle(){
   seats = 0;
}

Motorcycle::Motorcycle(int x):Vehicle(x){
}

int Motorcycle::get_toll_amnt(){
   int a = 20;
   if(date.get_day_of_week() == 0){
      a = 10;
   }
   return a*seats;
}


