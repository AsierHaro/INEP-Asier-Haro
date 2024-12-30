#pragma once
#include "CercadoraSeriesVisualitzades.h"
#include "DTOSerieV.h"

class TxSeriesVisualitzades
{
private:
	vector<DTOSerieV> resultat;
public:
	TxSeriesVisualitzades() {
	}

	void executar(string sobrenom) {
		CercadoraSeriesVisualitzades cerca;
		resultat = cerca.cercaVisualitzacions(sobrenom);
	}
	vector<DTOSerieV> obteresultat() {
		return resultat;
	}
};