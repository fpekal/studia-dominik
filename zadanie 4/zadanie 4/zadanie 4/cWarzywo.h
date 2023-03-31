#pragma once
#include "cProdukt.h"
class cWarzywo : public cProdukt{
private:
	char mColor[20];
public:
	cWarzywo(int , float, float, float, std::string, std::string, const char *);
	~cWarzywo();
	void pokaz();
};