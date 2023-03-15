#include "cSito1.h"
#include <iostream>
#include <math.h>

cSito1::cSito1(int gmN) {
	mN = gmN;
	for (int i = 0; i <= mN; i++) {
		mTablica[i] = true;
	}
	mNSqrt = int(sqrt(mN));
}
void cSito1:: Odsiej() {
	mTablica[0] = false;
	mTablica[1] = false;
	for (int i = 2; i <= mNSqrt; i++)
		if (mTablica[i])
			for (int j = 2; j * i <= mN; j++)
				mTablica[i * j] = false;
}
void cSito1:: Wyswietl() {
	for (int i = 2; i <= mN; i++)
		if (mTablica[i])
			std::cout << i << " ";
}
void cSito1:: Sprawdz(int i) {
	if (mTablica[i]) {
		std::cout << "liczba jest pierwsza.";
		return;
	}
	std::cout << "liczba nie jest pierwsza.";
}
