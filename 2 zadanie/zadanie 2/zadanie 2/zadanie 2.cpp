#include <iostream>
#include "cProdukt.h" 
#include "cWarzywo.h"
int main()
{
    static char tab[20] = "no hej";
    cWarzywo warzywko(0, 20, 32, 23, "pomidor", "kg", tab);
    warzywko.pokaz();
}
