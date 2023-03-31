#pragma once
#include "cWezel.h"
class cBaza {
	cWezel* wsk_pierwszy;
	cBaza();
	~cBaza();
	void dodaj(cProdukt &);
	void usun(int);
	void pokaz();
};