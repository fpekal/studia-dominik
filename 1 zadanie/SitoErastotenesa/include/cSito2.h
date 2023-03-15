#ifndef CSITO2_H
#define CSITO2_H
#include <iostream>

typedef unsigned long long int ullint;

class cSito2
{
private:
    ullint mN; // dane sa prywatne
	bool* mTablica; //
	void inicjalizacja();
public:
	cSito2();
	cSito2(ullint);
	~cSito2();
	void Odsiej();
	void Wyswietl();
	void Sprawdz(ullint);
};

#endif // CSITO2_H
