#pragma once
#include "CercadoraSeriesVisualitzades.h"
#include "DTOSerieV.h"

class TxSeriesVisualitzades
{
private:
	vector<DTOSerieV> resultat;
	vector<PassarelaSerieVisualitzada> v;
public:
	TxSeriesVisualitzades() {
	}

	void executar(string sobrenom) {
		CercadoraSeriesVisualitzades cerca;
		v = cerca.cercaVisualitzacions(sobrenom);
		for (unsigned int i = 0; i < v.size(); i++) {
			resultat.push_back(v[i]);
		}
	}
	vector<DTOSerieV> obteresultat() {
		return resultat;
	}
};