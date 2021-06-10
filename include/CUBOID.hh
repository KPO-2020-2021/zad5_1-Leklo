#ifndef CUBOID_HH
#define CUBOID_HH

#include "BLOCK.hh"

class CUBOID : public BLOCK
{

public:

CUBOID(Wektor3D center=Wektor3D(), double x=50,double y=50, double z=50,std::string name="../datasets/CUBOID.dat");

 ~CUBOID(){delete dim;}
};







#endif 