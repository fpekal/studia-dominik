#include "cSito2.h"

using namespace std;

cSito2::cSito2()    // Inicjalizujemy wartosci poczatkowe zmiennych
{
    cout << "\n Jestem konstruktorem bezparametrowym klasy cSito2\n";
    mN = 10000000;
    inicjalizacja();
}
cSito2::cSito2(ullint aN){
    cout << "\n Jestem konstruktorem z parametrem klasy cSito2\n";
    mN = aN;
    inicjalizacja();
}

void cSito2::inicjalizacja(){
    mTablica = new bool[mN];
    for (ullint i = 0; i < mN; i++)
    {
        mTablica[i] = true; // 1 - liczba pierwsza, 0 nie liczba pierwsza
    }
}

cSito2::~cSito2(){      // destruktor
    delete [] mTablica;
    cout << "\n Jestem desktruktorem klasy cSito2\n";
}

void cSito2::Odsiej()
{
	for (ullint i = 2; i * i < mN; i++)
	{
		if (mTablica[i] == 1)
		{
			for (ullint j = 2; i * j < mN; j++)
			{
				mTablica[i * j] = false;
			}
		}
	}
}

void cSito2::Wyswietl()
{
	for (ullint i = 0; i < mN; i++)
	{
		if (mTablica[i] == true)
		{
			cout << i << ", ";
		}
	}
	cout << "\n\n";
}

void cSito2::Sprawdz(ullint aX)
{
    if (mTablica[aX] == true)
    {
        cout << "Liczba ktora podales jest liczba pierwsza " << endl;
    }
    else{
        cout << "Liczba ktora podales NIE jest liczba pierwsza " << endl;
    }
}
