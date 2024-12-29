#pragma once
#include "CercadoraPelMesV.h"
#include "DTOPelMesV.h"

class TxConsultaPeliculesMesVistes
{
private:
	vector<DTOPelMesV> resultat;
	vector<PassarelaPelMesV> v;
public:
	TxConsultaPeliculesMesVistes() {
	}

	void executar(bool x) {
		CercadoraPelMesV cerca;
		v = cerca.cercaMesVistes(x);
		for (unsigned int i = 0; i < v.size(); i++) {
			resultat.push_back(v[i]);
		}
	}
	vector<DTOPelMesV> obteresultat() {
		return resultat;
	}
};