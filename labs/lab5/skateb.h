#ifndef SKATEB_H
#define SKATEB_H

#include "./vehicle.h"

class Skateb: public Vehicle{
   public:
      Skateb();
      Skateb(int);
      int get_toll_amnt();
};

#endif
