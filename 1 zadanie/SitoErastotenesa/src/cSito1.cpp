#include "cSito1.h"
using namespace std;

cSito1::cSito1()    // Inicjalizujemy wartoœci poczatkowe zmiennych
{
	for (int i = 0; i < mN; i++)
	{
		mTablica[i] = true; // 1 - liczba pierwsza, 0 nie liczba pierwsza
	}
}

void cSito1::Odsiej()
{
	for (int i = 2; i * i < mN; i++)
	{
		if (mTablica[i] == 1)
		{
			for (int j = 2; i * j < mN; j++)
			{
				mTablica[i * j] = false;
			}
		}
	}
}

void cSito1::Wyswietl()
{
	for (int i = 0; i < mN; i++)
	{
		if (mTablica[i] == true)
		{
			cout << i << ", ";
		}
	}
	cout << "\n\n";
}

void cSito1::Sprawdz(int aX)
{
    if (mTablica[aX] == true)
    {
        cout << "Liczba ktora podales jest liczba pierwsza " << endl;
    }
    else{
        cout << "Liczba ktora podales NIE jest liczba pierwsza " << endl;
    }
}
