#pragma once
#pragma once
#include "CercadorNPelicules.h"
#include "DTONpel.h"

class TxNovetatspelicules
{
private:
	vector<DTONpel> resultat;
	vector<PassarelaNPelicula> v;
public:
	TxNovetatspelicules() {
	}

	void executar() {
		CercadorNPelicules cerca;
		v = cerca.cercaNovetats();
		for (unsigned int i = 0; i < v.size(); i++) {
			resultat.push_back(v[i]);
		}
	}
	vector<DTONpel> obteresultat() {
		return resultat;
	}
};