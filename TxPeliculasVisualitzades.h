#pragma once
#include "CercadoraPeliculesVisualitzades.h"
#include "DTOPeliV.h"

class TxPeliculasVisualitzades
{
private:
	vector<DTOPeliV> resultat;
public:
	TxPeliculasVisualitzades() {
	}

	void executar(string sobrenom) {
		CercadoraPeliculesVisualitzades cerca;
		resultat = cerca.cercaVisualitzacions(sobrenom);
	}
	vector<DTOPeliV> obteresultat() {
		return resultat;
	}
};