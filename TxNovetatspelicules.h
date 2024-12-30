#pragma once
#include "CercadorNPelicules.h"

class TxNovetatspelicules
{
private:
	vector<DTONpel> resultat;
public:
	TxNovetatspelicules() {
	}

	void executar() {
		CercadorNPelicules cerca;
		resultat = cerca.cercaNovetats();

	}
	vector<DTONpel> obteresultat() {
		return resultat;
	}
};