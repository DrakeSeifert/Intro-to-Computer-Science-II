#ifndef BIKE_H
#define BIKE_H

#include "./vehicle.h"

class Bike: public Vehicle {
   public:
      Bike();
      Bike(int);
      int get_toll_amnt();
      
};

#endif
