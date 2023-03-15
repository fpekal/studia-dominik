#pragma once
class cSito1
{
private:
	int mN = 10000000;
	bool mTablica[10000000];
	int mNSqrt;
public:
	cSito1(int);
	void Odsiej();
	void Wyswietl();
	void Sprawdz(int);
};
