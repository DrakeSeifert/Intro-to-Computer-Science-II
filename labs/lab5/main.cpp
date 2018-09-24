#include <iostream>
#include "./vehicle.h"
#include "./bike.h"
#include "./car.h"
#include "./motorcycle.h"
#include "./skateb.h"

using std::cout;
using std::endl;

int main() {
   int d, m, y;
   cout << "Day: ";
   cin >> d;
   cout << "Month: ";
   cin >> m;
   cout << "Year: ";
   cin >> y;

   Date *v_array[3] = {new Car(3), new Car(5), new Bike(1)}; //Vehicle??
   v_array[0]->set_day(d);
   v_array[1]->set_day(d);
   v_array[2]->set_day(d);
   v_array[0]->set_month(m);
   v_array[1]->set_month(m);
   v_array[2]->set_month(m);
   v_array[0]->set_year(y);
   v_array[1]->set_year(y);
   v_array[2]->set_year(y);
   
   Motorcycle mo;
   Car c;
   Bike b;

   cout << "Motorcycle: " << mo->get_seats() << ", " << mo.get_toll_amnt() << endl;
   cout << "Car: " << c->get_seats() << ", " << c.get_toll_amnt() << endl;
   cout << "Bike: " << b->get_seats() << ", " << b.get_toll_amnt() << endl;
   return 0;
}

