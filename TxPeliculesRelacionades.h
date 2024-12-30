#pragma once
#include "CercadoraPeliculesRelacionades.h"
#include "DTOPeliR.h"

class TxPeliculesRelacionades
{
private:
	vector<DTOPeliR> resultat;
public:
	TxPeliculesRelacionades() {
	}

	void executar(string titol) {
		CercadoraPeliculesRelacionades cerca;
		resultat = cerca.cerca(titol);
		
	}
	vector<DTOPeliR> obteresultat() {
		return resultat;
	}
};
