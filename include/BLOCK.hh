#ifndef BLOCK_HH
#define BLOCK_HH

#include "Wektor3D.hh"
#include "Macierz3x3.hh"
#include <fstream>
#include <vector>

class BLOCK
{
 protected:
 Wektor3D *dim;
 std::vector<Wektor3D> vertex;
 Wektor3D center;
 std::string name;
 public:

  Wektor3D &operator[](int index);
  Wektor3D operator[](int index)const;

 void scenter(Wektor3D center);
 void sname(std::string name);
 Wektor3D gcenter() const;
 std::string gname() const;

 void move(Wektor3D mv);
 void translacja(Macierz3x3 obr);

 void zapisz();
 ~BLOCK(){delete dim;}
};





#endif
