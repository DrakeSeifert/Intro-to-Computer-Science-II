#ifndef VEHICLE_H
#define VEHICLE_H

#include "./date.h"
class Vehicle {
   public:
      Vehicle();
      Vehicle(int);
      int get_seats();
      void set_date(int, int, int);
      void set_seats(int);
      virtual int get_toll_amnt();
   protected:
      int seats;
      Date date;
};

#endif
