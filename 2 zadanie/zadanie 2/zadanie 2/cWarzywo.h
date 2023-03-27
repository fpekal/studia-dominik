#pragma once
#include "cProdukt.h"
class cWarzywo : public cProdukt{
private:
	static char mColor[20];
public:
	cWarzywo(int, float, float, float, std::string, std::string,char*) : cProdukt();
	~cWarzywo();
	void pokazWarzywo();
};