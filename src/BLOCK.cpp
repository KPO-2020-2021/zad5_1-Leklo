#include "BLOCK.hh"

Wektor3D &BLOCK::operator[](int index)
{
    return vertex[index];
}
Wektor3D BLOCK::operator[](int index) const
{
    return vertex[index];
}

void BLOCK::sname(std::string name)
{
    this->name = name;
}

void BLOCK::scenter(Wektor3D center)
{
    this->center = center;
}

Wektor3D BLOCK::gcenter() const
{
    return center;
}

std::string BLOCK::gname() const
{
    return name;
}

void BLOCK::move(Wektor3D mv)
{
    for (int i = 0; i < (int)vertex.size(); i++)
    {
        vertex[i] = vertex[i] + mv;
    }
    center = center + mv;
}

void BLOCK::translacja(Macierz3x3 obr)
{
    for (int i = 0; i < (int)vertex.size(); i++)
    {
        vertex[i] = (obr * vertex[i]);
    }
    center=obr*center;
}

void BLOCK::zapisz()
{
    std::fstream plik;
    double tab[] = {0, 0, (*dim)[2] / 2};
    Wektor3D move_c(tab);

    plik.open(name, std::ios::out);

    for (int i = 0; i < (int)vertex.size(); i += 2)
    {
        plik << center + move_c << std::endl;
        for (int j = 0; j < 2; j++)
        {
            plik << vertex[j + i] << std::endl;
        }
        plik << center - move_c << std::endl
             << std::endl;
    }

    plik << center + move_c << std::endl;
    for (int j = 0; j < 2; j++)
    {
        plik << vertex[j] << std::endl;
    }
    plik << center - move_c << std::endl
         << std::endl;
    plik.close();
}