#pragma once
#include "CercadoraVisualitzaPel.h"
#include "PassarelaVisualitzaPel.h"
#include "DTOPel.h"
#include "Petitflix.h"


class TxVisualitzaPel {
private:
    CercadoraVisualitzaPel cercadora;
	string titolPel;
public:
    TxVisualitzaPel() {}
	
	TxVisualitzaPel(string titolPelicula) {
		titolPel = titolPelicula;
	}
	/*void executar() {
		Petitflix& petitflix = Petitflix::getInstance();
		petitflix.visualitzacio();
	}
	*/
 
};

