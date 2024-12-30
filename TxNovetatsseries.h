#pragma once
#include "CercadorNSeries.h"

class TxNovetatsseries
{
private:
	vector<DTONserie> resultat;
public:
	TxNovetatsseries() {
	}

	void executar() {
		CercadorNSeries cerca;
		resultat = cerca.cercaNovetats();

	}
	vector<DTONserie> obteresultat() {
		return resultat;
	}
};