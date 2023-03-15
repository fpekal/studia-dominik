#include "cSito3.h"

using namespace std;

cSito3::cSito3()    // Inicjalizujemy wartosci poczatkowe zmiennych
{
    cout << "\n Jestem konstruktorem bezparametrowym klasy cSito3\n";
    mN = 10000000;
    inicjalizacja();
}
cSito3::cSito3(ull aN){
    cout << "\n Jestem konstruktorem z parametrem klasy cSito3\n";
    mN = aN;
    inicjalizacja();
}

void cSito3::inicjalizacja(){
    cout << mN <<endl;
    mTablica.resize(mN, true);
}

cSito3::~cSito3(){      // destruktor
    cout << "\n Jestem desktruktorem klasy cSito3\n";
}

void cSito3::Odsiej()
{
	for (ull i = 2; i * i < mN; i++)
	{
		if (mTablica[i] == 1)
		{
			for (ull j = 2; i * j < mN; j++)
			{
				mTablica.at(i * j) = false;
			}
		}
	}
}

void cSito3::Wyswietl()
{
	for (ull i = 0; i < mN; i++)
	{
		if (mTablica.at(i) == true)
		{
			cout << i << ", ";
		}
	}
	cout << "\n\n";
}

void cSito3::Sprawdz(ull aX)
{
    if (mTablica.at(aX) == true)
    {
        cout << "Liczba ktora podales jest liczba pierwsza " << endl;
    }
    else{
        cout << "Liczba ktora podales NIE jest liczba pierwsza " << endl;
    }
}

void cSito3::MaxSize(){
    cout << "\n Max size: " << mTablica.max_size() << "\n";

}
