#pragma once
#include "CercadorNSeries.h"
#include "DTONserie.h"

class TxNovetatsseries
{
private:
	vector<DTONserie> resultat;
	vector<PassarelaNSerie> v;
public:
	TxNovetatsseries() {
	}

	void executar() {
		CercadorNSeries cerca;
		v = cerca.cercaNovetats();
		for (unsigned int i = 0; i < v.size(); i++) {
			resultat.push_back(v[i]);
		}
	}
	vector<DTONserie> obteresultat() {
		return resultat;
	}
};