#ifndef MACIERZ3X3_HH
#define MACIERZ3X3_HH


#include <iostream>
#include "Macierz.hh"


typedef Macierz<3>  Macierz3x3;


Macierz3x3 mac_obr_x(double angle);
Macierz3x3 mac_obr_y(double angle);
Macierz3x3 mac_obr_z(double angle);

#endif
