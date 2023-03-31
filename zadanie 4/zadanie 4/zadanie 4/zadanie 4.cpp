#include <iostream>
#include "cProdukt.h" 
#include "cWarzywo.h"
int main()
{
    //sterta
    cProdukt *p1 = new cProdukt(1, 20, 32, 23, "pomidor", "kg");
    p1->pokaz();
    delete p1;

    //stos
    cProdukt p2(2, 10, 12,12,"trawa", "m");
    p2.pokaz();

    //warzywo stos,    testowanie ktore metody sie wykonuja
    cProdukt* wsk_p3 = nullptr;
    cWarzywo* wsk_w3 = nullptr;
    cWarzywo p3 (3, 20, 32, 23, "ogorek", "kg", "Seledynowy");
    
    wsk_p3 = &p3;
    wsk_w3 = &p3;

    p3.pokaz();
    wsk_p3->pokaz();
    wsk_w3->pokaz();
}


//Czy konstruktor / destruktor mo�e by� wirtualny ?
//destruktor tak, konstruktor nie

//Kt�ry konstruktor / destruktor jest wywo�ywany przy tworzeniu / kasowaniu obiektu klasy pochodnej ?
//oba w konstruktorze klasy pochodnej wywo�uje konstruktor bazowy, 
//natomiast destruktory jest wirtualny i wykonuj� si� oba.

//Czy wska�nik na klas� bazow� mo�e pokazywa� na obiekt klasy pochodnej ? tak 
//Je�li tak, kt�re funkcje s� wywo�ywane przy odwo�aniu przez 
//taki wska�nik - te z klasy bazowej, czy z klasy pochodnej?
// 
//jak faunkcja jest wirtualna i redefiniowana w klasie pochodnej 
//to wykonuje si� funkcja zdefiniowana w klasie pochodnej niezale�nie od typu wska�nika.
//Je�eli ta funkcja nie zosta�a drugi raz zdefiniowana to wykona si� ta z klasy bazowej.
//

