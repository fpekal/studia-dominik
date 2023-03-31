#pragma once
#include "cProdukt.h"
class cWezel {
public:
	cWezel* wsk_nastepny;
	cProdukt produkt;
	cWezel(cProdukt &);
	~cWezel();
};