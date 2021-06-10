
#include "DRONE.hh"

DRONE::DRONE(int id, PzG::LaczeDoGNUPlota &Lacze, Wektor3D pozycja) : Lacze(Lacze)
{
    angle=0;
    this->id = id;
    orginal.sname("../datasets/korpus" + std::to_string(id) + ".dat");

    for (int i = 0; i < 4; i++)
        org_wir[i].sname("../datasets/wirnik" + std::to_string(i) + std::to_string(id) + ".dat");

    Lacze.DodajNazwePliku(orginal.gname().c_str(), PzG::RR_Ciagly, 2);
    for (int i = 0; i < 4; i++)
        Lacze.DodajNazwePliku(org_wir[i].gname().c_str(), PzG::RR_Ciagly, 2);
    kopia = orginal;

    kopia.move(pozycja);
    for (int i = 0; i < 4; i++)
        kopia_wir[i] = org_wir[i];

    for (int i = 0; i < 4; i++)
        kopia_wir[i].move(orginal[i * 2] + pozycja);

    this->path = this->path + pozycja;
}

void DRONE::up(double path)
{
    Wektor3D path_o;
    path_o[2] = path;

    this->path = this->path + path_o;
    kopia.translacja(obr);
    kopia.move(this->path);
}

void DRONE::move(double path)
{
    Wektor3D path_o;
    path_o[0] = path * cos(angle * M_PI / 180);
    path_o[1] = path * sin(angle * M_PI / 180);
    this->path = this->path + path_o;
    kopia.translacja(obr);
    kopia.move(this->path);
}

void DRONE::rotate(double angle)
{
    this->angle += angle;
    Macierz3x3 nowa;
    obr = nowa * mac_obr_z(this->angle);
    kopia.translacja(obr);
    kopia.move(this->path);
}
void DRONE::rotater()
{
    static int angle = 0;
    angle += 3;
    if (angle == 360)
        angle = 0;

    Macierz3x3 nowa;
    nowa = nowa * mac_obr_z(angle);
    for (int i = 0; i < 4; i++)
    {
        kopia_wir[i].translacja(nowa);
    }

    for (int i = 0; i < 4; i++)
    {
        kopia_wir[i].move(kopia[i * 2]);
    }
}

void DRONE::zapisz()
{
    kopia.zapisz();
    for (int i = 0; i < 4; i++)
        kopia_wir[i].zapisz();
}

void DRONE::control()
{
    double path;
    double angle;
    char opcja;

    zapisz();
    cout << "Options :";
    cin >> opcja;
    switch (opcja)
    {
    case 'p':
        cout << "Input desired path length :";
        cin >> path;
        setpath(path);
        Lacze.DodajNazwePliku("../datasets/droga.dat", PzG::RR_Ciagly, 2);
        for (int i = 0; i < 100; i++)
        {
            kopia = orginal;
            for (int j = 0; j < 4; j++)
                kopia_wir[j] = org_wir[j];
            up(1);
            rotater();
            zapisz();
            Lacze.Rysuj();
            usleep(TIME);
        }

        for (int i = 0; i < path; i++)
        {
            kopia = orginal;
            for (int j = 0; j < 4; j++)
                kopia_wir[j] = org_wir[j];
            move(1);
            rotater();
            zapisz();
            Lacze.Rysuj();
            usleep(TIME);
        }

        for (int i = 0; i < 100; i++)
        {
            kopia = orginal;
            for (int j = 0; j < 4; j++)
                kopia_wir[j] = org_wir[j];
            up(-1);
            rotater();
            zapisz();
            Lacze.Rysuj();
            usleep(TIME);
        }
    Lacze.UsunOstatniaNazwe();
        break;
    case 'o':
        cout << "Input desired angle of rotation :";
        cin >> angle;
        if (angle > 0)
        {
            for (int i = 0; i < angle; i++)
            {
                kopia = orginal;
                for (int i = 0; i < 4; i++)
                    kopia_wir[i] = org_wir[i];
                rotate(1);
                rotater();
                zapisz();
                Lacze.Rysuj();
                usleep(TIME);
            }
        }
        else
        {
            for (int i = 0; i > angle; i--)
            {
                kopia = orginal;
                rotate(-1);
                rotater();
                zapisz();
                Lacze.Rysuj();
                usleep(TIME);
            }
        }

        break;
    default:
        break;
    }
}

void DRONE::setpath(double path)
{
    Wektor3D nastepny = kopia.gcenter();
    nastepny[2] = 0;
    pathing.push_back(nastepny);
    nastepny[2] = 100;
    pathing.push_back(nastepny);
    nastepny[0] += path * cos(angle * M_PI / 180);
    nastepny[1] += path * sin(angle * M_PI / 180);
    pathing.push_back(nastepny);
    nastepny[2] = 0;
    pathing.push_back(nastepny);

    std::fstream plik;

    plik.open("../datasets/droga.dat", std::ios::out);
    for (int i = 0; i < (int)pathing.size(); i++)
    {

        plik << pathing[i] << std::endl;
    }
    plik.close();
}