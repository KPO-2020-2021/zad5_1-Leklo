#ifndef DRONE_HH
#define DRONE_HH

#include "CUBOID.hh"
#include "PRISM.hh"
#include "lacze_do_gnuplota.hh"
#include <unistd.h> // biblioteka dla usleep
#define TIME 20000

class DRONE
{
    std::vector<Wektor3D> pathing;
    PzG::LaczeDoGNUPlota &Lacze;
    CUBOID orginal;
    CUBOID kopia;
    PRISM org_wir[4];
    PRISM kopia_wir[4];
    Macierz3x3 obr;
    Wektor3D path;
    double angle;
    int id; 
public:

  
  DRONE(int id,PzG::LaczeDoGNUPlota &Lacze,Wektor3D pozycja);
  void up(double path);
  void move(double path);
  void rotate(double angle); // kont podajemy w stopniach
  void rotater(); // kont podajemy w stopniach
  void zapisz();
  void control();
  void setpath(double path);
};

#endif
