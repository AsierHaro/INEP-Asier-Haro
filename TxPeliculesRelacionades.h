#pragma once
#include "CercadoraPeliculesRelacionades.h"
#include "DTOPeliR.h"

class TxPeliculesRelacionades
{
private:
	vector<DTOPeliR> resultat;
	vector<PassarelaVisualitzaPel> v;
public:
	TxPeliculesRelacionades() {
	}

	void executar(string titol) {
		CercadoraPeliculesRelacionades cerca;
		v = cerca.cerca(titol);
		for (unsigned int i = 0; i < v.size(); i++) {
			resultat.push_back(v[i]);
		}
	}
	vector<DTOPeliR> obteresultat() {
		return resultat;
	}
};
