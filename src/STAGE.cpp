#include "STAGE.hh"


 STAGE::STAGE()
 {

        Lacze.ZmienTrybRys(PzG::TR_3D);

       Lacze.UstawZakresY(-300, 300);
       Lacze.UstawZakresX(-300, 300);
       Lacze.UstawZakresZ(-300, 300);

       double tab_wym[3]={600,600,0};
       Wektor3D wym_dna(tab_wym);
       dno=new PLANE(wym_dna,20);
       Lacze.DodajNazwePliku(dno->gname().c_str(), PzG::RR_Ciagly, 2);
       dno->zapisz();
       for(int i=0;i<N; i++)
       {
           double pozycja[3]={(double)(rand()%440-220),(double)(rand()%440-220),25};
       tab[i]=new DRONE(i,Lacze,Wektor3D(pozycja));
       tab[i]->zapisz();
       }

       Lacze.Rysuj();
 }
 void  STAGE::rysuj()
 {
     
   Lacze.Rysuj();
 }
 bool  STAGE::interfejs()
 {
    cout<<"Input 0 or 1 to choose between drone one and two or input 2 to quit"<<endl;
    int nr;
    cin>>nr;
    if(nr<N)
    {
        tab[nr]->control();
    }
    else
    {
        return false;
    }
  return true;
 }

 STAGE::~STAGE()
 {
delete dno;
for(int i=0; i<N; i++)
delete tab[i];
 }