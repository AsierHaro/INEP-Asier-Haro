#pragma once
#include "CercadoraTemporadas.h"

class TxInfoTemporades {
private:
	DTOTemporada t;
public:
	TxInfoTemporades() {
	}
	void executar(string nom) {
		CercadoraTemporadas cerca;
		t = cerca.cercaTemporada(nom);
	}

	DTOTemporada obteTemporada() {
		return t;
	}

};
