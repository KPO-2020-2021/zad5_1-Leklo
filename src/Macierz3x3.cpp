#include "Macierz3x3.hh"

/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Macierz3x3, ktore zawieraja wiecej kodu
 *  niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */

Macierz3x3 mac_obr_x(double angle)
{
    double rad = angle * M_PI / 180;
    Macierz3x3 Rot;
    Rot(0, 0) = 1;
    Rot(0, 1) = 0;
    Rot(0, 2) = 0;

    Rot(1, 0) = 0;
    Rot(1, 1) = cos(rad);
    Rot(1, 2) = -sin(rad);

    Rot(2, 0) = 0;
    Rot(2, 1) = sin(rad);
    Rot(2, 2) = cos(rad);
    return Rot;
}
Macierz3x3 mac_obr_y(double angle)
{
    double rad = angle * M_PI / 180;
    Macierz3x3 Rot;
    Rot(0, 0) = cos(rad);;
    Rot(0, 1) = 0;
    Rot(0, 2) = sin(rad);

    Rot(1, 0) = 0;
    Rot(1, 1) = 1;
    Rot(1, 2) = 0;

    Rot(2, 0) = -sin(rad);
    Rot(2, 1) = 0;
    Rot(2, 2) = cos(rad);
    return Rot;
}
Macierz3x3 mac_obr_z(double angle)
{
    double rad = angle * M_PI / 180;
    Macierz3x3 Rot;
    Rot(0, 0) = cos(rad);;
    Rot(0, 1) = -sin(rad);
    Rot(0, 2) = 0;

    Rot(1, 0) = sin(rad);
    Rot(1, 1) = cos(rad);
    Rot(1, 2) = 0;

    Rot(2, 0) = 0;
    Rot(2, 1) = 0;
    Rot(2, 2) = 1;
    return Rot;
}