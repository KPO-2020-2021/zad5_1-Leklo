#ifndef STAGE_HH
#define STAGE_HH
#include <iostream>
#include <iomanip>
#include <fstream>
#include "PRISM.hh"
#include "lacze_do_gnuplota.hh"
#include "DRONE.hh"
#include "PLANE.hh"

#define N 2

class STAGE
{
 PzG::LaczeDoGNUPlota Lacze;
 DRONE *tab[N];
 PLANE *dno;
 public:
 STAGE();
 void rysuj();
 bool interfejs();
~STAGE();
};



#endif
