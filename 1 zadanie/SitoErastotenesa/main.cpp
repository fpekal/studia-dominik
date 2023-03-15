#include <iostream>
#include "cSito1.h"
#include "cSito2.h"
#include "cSito3.h"
#include <cmath>

using namespace std;



void Pauza(){
    system("PAUSE");

    /* Jesli uzywacie Macos lub linuxa program mozna zatrzymac np. tak:
    char tmp;
    cout << "\nKONIEC PROGRAMU - Wpisz dowolna literke i nacisnij enter\n";
    cin >> tmp; */
}




int main()
{
 /*
    //Statycznie w klasie i statycznie w uzyciu klasy
    Pauza();
	cSito1 sitoStatyczne;   // Stos
	Pauza();
	sitoStatyczne.Odsiej();
	//sitoStatyczne.Wyswietl();
	sitoStatyczne.Sprawdz(100);
	Pauza();
*/
/*
	 // Statycznie w klasie i dynamiczne w uzyciu klasy
	Pauza();
	cSito1* sitoStatyczne = new cSito1; // Sterta
    cSito1* sitoStatyczne2 = new cSito1;
    cSito1* sitoStatyczne3 = new cSito1;
    cSito1* sitoStatyczne4 = new cSito1;
	Pauza();
	sitoStatyczne->Odsiej();
	//sitoStatyczne.Wyswietl();
	sitoStatyczne->Sprawdz(100);
	Pauza();
*//*
	Pauza();  // Dynamicznie w klasie, statyczne uzycie klasy
	cSito2 sitoDynamiczne(pow(10, 11)); Pauza();
	//cSito2 sitoDynamiczne2; Pauza();
	//cSito2 sitoDynamiczne3; Pauza();
	sitoDynamiczne.Odsiej();
	sitoDynamiczne.Sprawdz(100);
	Pauza();
*/
	/*
	Pauza();  // Dynamicznie w klasie, dynamiczne uzycie klasy
	cSito2* sitoDynamiczne = new cSito2; Pauza();
	cSito2* sitoDynamiczne2 = new cSito2(100000000); Pauza();
	cSito2* sitoDynamiczne3 = new cSito2; Pauza();
	sitoDynamiczne->Odsiej();
	sitoDynamiczne->Sprawdz(100);
	Pauza();
	delete sitoDynamiczne; Pauza();
	delete sitoDynamiczne2; Pauza();
	delete sitoDynamiczne3; Pauza();
    */

    /*
	Pauza();  // Wektor w klasie, dynamiczne uzycie klasy
	cSito3* sitoDynamiczne = new cSito3; Pauza();
	cSito3* sitoDynamiczne2 = new cSito3(100000000); Pauza();
	cSito3* sitoDynamiczne3 = new cSito3; Pauza();
	sitoDynamiczne->Odsiej();
	sitoDynamiczne->Sprawdz(100);
	Pauza();
	delete sitoDynamiczne; Pauza();
	delete sitoDynamiczne2; Pauza();
	delete sitoDynamiczne3; Pauza();
    */
/*
    // Zajetosc pamieci porownanie - Win10 mingw32-g++.exe 16GB ram ma komputer
    Pauza();
	cSito2* sitoDynamiczne = new cSito2(1700000000); Pauza();  // Maksymalnie 1700000000 - 1621 MB pamieci RAM
	delete sitoDynamiczne; Pauza();
	cSito3* sitoDynamiczneWektor = new cSito3(2147483616); Pauza(); // Maksymalnie 2147483616 -  256,5 MB pamieci RAM
    sitoDynamiczneWektor->MaxSize();
	sitoDynamiczneWektor->Odsiej();
	sitoDynamiczneWektor->Sprawdz(100);
	delete sitoDynamiczneWektor; Pauza();
*/
    // Wasze wyniki:
	// Na kompilatorze 64 bitowym - 16 GB ram, Windows maksymalna liczba:  100e12 - zapis w notacji 1e10 jest stala typu double
	// i daje bledne wyniki przy rzutowaniu na int!!! Nalezy zapisac jako pow(10, 10) jesli chcemy 1 i 10 zer zapisac!!
}
