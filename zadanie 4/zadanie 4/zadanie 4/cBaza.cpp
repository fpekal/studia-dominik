#include "cBaza.h"
cBaza::cBaza() {
	wsk_pierwszy = nullptr;
}
void cBaza::dodaj(cProdukt& gProdukt) {
	if (wsk_pierwszy == nullptr) {
		wsk_pierwszy = new cWezel(gProdukt);
		wsk_pierwszy->wsk_nastepny = nullptr;
		return;
	}
	cWezel* wsk_pomocniczy = wsk_pierwszy;
	wsk_pierwszy = new cWezel(gProdukt);
	wsk_pierwszy->wsk_nastepny = wsk_pomocniczy;
}
void cBaza::pokaz() {
	for (cWezel* i = wsk_pierwszy;i->wsk_nastepny!=nullptr; i = i->wsk_nastepny) {
		i->produkt.pokaz();
	}
}
