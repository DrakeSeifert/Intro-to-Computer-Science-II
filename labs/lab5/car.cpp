#include "./vehicle.h"
#include "./car.h"

Car::Car():Vehicle(){
   seats = 0;
}

Car::Car(int x):Vehicle(x){
}

int Car::get_toll_amnt(){
   int a = 20;
   if(date.get_day_of_week() == 5){
      a = 10;
   }
   return seats*a;
}

