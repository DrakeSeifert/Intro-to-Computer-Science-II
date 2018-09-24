#include "./vehicle.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

Vehicle::Vehicle(){
   seats = 0;
}

Vehicle::Vehicle(int x){
   seats = x;
}

int Vehicle::get_seats(){
   return seats;
}

void Vehicle::set_seats(int c){
   seats = c;
}

int Vehicle::get_toll_amnt(){
   return 20*seats;
}

void Vehicle::set_date(int d, int m, int y){

   date.set_day(d);
   date.set_month(m);
   date.set_year(y);
   cout << date.get_day_of_week() << endl;
}

