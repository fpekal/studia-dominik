#include "cWarzywo.h"

cWarzywo::cWarzywo(int glp, float gCount, float gPrice, float gVat, std::string gName, std::string gUnit, const char *gColor) : cProdukt(glp, gCount, gPrice, gVat, gName, gUnit) {
	int gColorLength = std::strlen(gColor) + 1;
	for (int i = 0; i < gColorLength; i++) { //20 to liczba znakow kolorow
		mColor[i] = gColor[i];
	}
}
cWarzywo::~cWarzywo(){

	std::cout << "\ndestrukcja warzywa";
}
void cWarzywo::pokaz() {
	cProdukt::pokaz();
	int mColorLength = std::strlen(mColor) + 1;
	for (int i = 0; i < mColorLength; i++) {//20 to liczba znakow kolorow
		std::cout << mColor[i];
	}
}