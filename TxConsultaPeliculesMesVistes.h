#pragma once
#include "CercadoraPelMesV.h"

class TxConsultaPeliculesMesVistes
{
private:
	vector<DTOPelMesV> resultat;
public:
	TxConsultaPeliculesMesVistes() {
	}

	void executar(bool x) {
		CercadoraPelMesV cerca;
		resultat = cerca.cercaMesVistes(x);

	}
	vector<DTOPelMesV> obteresultat() {
		return resultat;
	}
};