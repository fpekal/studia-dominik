#ifndef CSITO1_H
#define CSITO1_H
#include <iostream>

class cSito1
{
private:
    int mN = 10000000; // dane sa prywatne
	bool mTablica[10000000]; // Statycznie: 100000 - dla int, 1000000 - dla bool
public:
	cSito1();
	void Odsiej();
	void Wyswietl();
	void Sprawdz(int);
};

#endif // CSITO1_H
