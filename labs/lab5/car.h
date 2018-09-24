#ifndef CAR_H
#define CAR_H

#include "./vehicle.h"

class Car: public Vehicle {
   public:
      Car();
      Car(int);
      int get_toll_amnt();
};

#endif



