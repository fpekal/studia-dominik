#include "cWarzywo.h"


cWarzywo::cWarzywo(int glp, float gCount, float gPrice, float gVat, std::string gName, std::string gUnit, char *gColor) :cProdukt(glp, gCount, gPrice, gVat, gName, gUnit) {
	for (int i = 0; i < 20; i++) { //20 to liczba znakow kolorow
		mColor[i] = gColor[i];
	}
}
void cWarzywo::pokazWarzywo() {
	pokaz();
	for (int i = 0; i < 20; i++) {//20 to liczba znakow kolorow
		std::cout << mColor[i];
	}
}