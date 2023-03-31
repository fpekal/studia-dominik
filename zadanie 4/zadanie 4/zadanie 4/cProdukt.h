#pragma once
#include <iostream>
class cProdukt {
private:
	int mLp;
	float mCount, mPrice, mVat;
	std::string mName, mUnit;
public:
	cProdukt(int , float , float , float , std::string , std::string );
	virtual ~cProdukt();
	int getLp();
	void setLp(int);
	void wypelnij(int,float,float,float,std::string,std::string);
	virtual void pokaz();
};