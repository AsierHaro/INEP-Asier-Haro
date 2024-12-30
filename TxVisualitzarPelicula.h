#pragma once
#include "PassarelaVisualitzaPel.h"
#include "DTOPel.h"


class TxVisualitzarPelicula {
private:
	DTOPel pelicula;
public:
	TxVisualitzarPelicula() {}

	string executar(string sobrenom, string titolPelicula) {
		PassarelaVisualitzaPel v;
		return v.visualitza(sobrenom, titolPelicula);
	}

	DTOPel obtenPelicula() {
		return pelicula;
	}

};
