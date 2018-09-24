#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H
#include "./vehicle.h"

class Motorcycle: public Vehicle{
   public:
      Motorcycle();
      Motorcycle(int);
      int get_toll_amnt();
};

#endif
