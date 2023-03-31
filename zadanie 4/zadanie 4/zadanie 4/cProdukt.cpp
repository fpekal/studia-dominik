#include "cProdukt.h"
cProdukt::cProdukt(int glp, float gCount, float gPrice, float gVat, std::string gName, std::string gUnit) {
	wypelnij(glp, gCount, gPrice, gVat, gName, gUnit);
}
cProdukt::~cProdukt() {
	std::cout << "\ndestrukcja produktu";
}
int cProdukt::getLp() {
	return mLp;
}
void cProdukt::setLp(int gLp) {
	mLp = gLp;
}
void cProdukt::wypelnij(int glp, float gCount, float gPrice, float gVat, std::string gName, std::string gUnit) {
	mLp = glp;
	mCount = gCount;
	mPrice = gPrice;
	mVat = gVat;
	mName = gName;
	mUnit = gUnit;
}
void cProdukt::pokaz() {
	std::cout << "\n\n";
	std::cout	<< mLp << " " << mCount << " " << mPrice 
				<< " " << mVat << " " << mName
				<< " " << mUnit << " ";

}