#pragma once
#include "CercadoraPropersEstrens.h"
#include "DTOEstrenes.h"

class TxConsultarProperesEstrenes
{
private:
	vector<DTOEstrenes> resultat;
public:
	TxConsultarProperesEstrenes() {
	}

	void executar() {
		CercadoraPropersEstrens cerca;
		resultat = cerca.cercaEstrens();

	}
	vector<DTOEstrenes> obteresultat() {
		return resultat;
	}
};