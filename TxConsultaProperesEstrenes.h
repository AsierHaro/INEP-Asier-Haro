#pragma once
#include "PassarelaEstrenes.h"
#include "CercadoraPropersEstrens.h"
#include "DTOEstrenes.h"

class TxConsultarProperesEstrenes
{
private:
	vector<DTOEstrenes> resultat;
	vector<PassarelaEstrenes> v;
public:
	TxConsultarProperesEstrenes() {
	}

	void executar() {
		CercadoraPropersEstrens cerca;
		v = cerca.cercaEstrens();
		for (unsigned int i = 0; i < v.size(); i++) {
			resultat.push_back(v[i]);
		}
	}
	vector<DTOEstrenes> obteresultat() {
		return resultat;
	}
};