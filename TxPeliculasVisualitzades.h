#pragma once
#include "CercadoraPeliculesVisualitzades.h"
#include "DTOPeliV.h"

class TxPeliculasVisualitzades
{
private:
	vector<DTOPeliV> resultat;
	vector<PassarelaPeliculaVisualitzada> v;
public:
	TxPeliculasVisualitzades() {
	}

	void executar(string sobrenom) {
		CercadoraPeliculesVisualitzades cerca;
		v = cerca.cercaVisualitzacions(sobrenom);
		for (unsigned int i = 0; i < v.size(); i++) {
			resultat.push_back(v[i]);
		}
	}
	vector<DTOPeliV> obteresultat() {
		return resultat;
	}
};