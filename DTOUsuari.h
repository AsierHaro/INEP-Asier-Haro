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
		data = usu.obteData();
		modalitatSubscripcio = usu.obteSubscripcio();
	}
	string obteSobrenom() { return sobrenom; }
	string obteNom() { return nom; }
	string obteCorreu() { return correu; }
	string obteData() { return data; }
	string obteSubscripcio() {return modalitatSubscripcio;}
private:
	string sobrenom = "";
	string nom = "";
	string correu = "";
	string modalitatSubscripcio = "";
	string data = " ";
};

