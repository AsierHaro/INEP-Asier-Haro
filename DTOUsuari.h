#pragma once
#include "PassarelaUsuari.h"
#include "CercadoraUsuari.h"
class DTOUsuari
{
public:
	DTOUsuari() {}
	DTOUsuari(PassarelaUsuari usu) {
		sobrenom = usu.obteSobrenom();
		nom = usu.obteNom();
		correu = usu.obteCorreuElectronic();
	}
	string obteSobrenom() { return sobrenom; }
	string obteNom() { return nom; }
	string obteCorreu() { return correu; }
private:
	string sobrenom = "";
	string nom = "";
	string correu = "";
};

