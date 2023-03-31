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


//Czy konstruktor / destruktor mo¿e byæ wirtualny ?
//destruktor tak, konstruktor nie

//Który konstruktor / destruktor jest wywo³ywany przy tworzeniu / kasowaniu obiektu klasy pochodnej ?
//oba w konstruktorze klasy pochodnej wywo³uje konstruktor bazowy, 
//natomiast destruktory jest wirtualny i wykonuj¹ siê oba.

//Czy wskaŸnik na klasê bazow¹ mo¿e pokazywaæ na obiekt klasy pochodnej ? tak 
//Jeœli tak, które funkcje s¹ wywo³ywane przy odwo³aniu przez 
//taki wskaŸnik - te z klasy bazowej, czy z klasy pochodnej?
// 
//jak faunkcja jest wirtualna i redefiniowana w klasie pochodnej 
//to wykonuje siê funkcja zdefiniowana w klasie pochodnej niezale¿nie od typu wskaŸnika.
//Je¿eli ta funkcja nie zosta³a drugi raz zdefiniowana to wykona siê ta z klasy bazowej.
//

