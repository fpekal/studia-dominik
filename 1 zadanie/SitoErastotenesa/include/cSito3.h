#ifndef CSITO3_H
#define CSITO3_H
#include <vector>
#include <iostream>

typedef unsigned long long int ull;

class cSito3
{
private:
    ull mN; // dane sa prywatne
    std::vector<bool> mTablica; //
    void inicjalizacja();
public:
    cSito3();
    cSito3(ull);
    ~cSito3();
    void Odsiej();
    void Wyswietl();
    void Sprawdz(ull);
    void MaxSize();
};

#endif // CSITO3_H
