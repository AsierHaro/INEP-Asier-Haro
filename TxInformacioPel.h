#pragma once
#include "CercadoraPelicula.h"
#include "DTOPel.h"


class TxInformacioPel {
private:
	DTOPel pelicula;
public:
	TxInformacioPel() {}

	void executar(string titolPelicula) {
		CercadoraPelicula cercadora;
		pelicula = DTOPel(cercadora.cercaVisualitzacions(titolPelicula));
	}

	DTOPel obtenPelicula() {
		return pelicula;
	}

};
