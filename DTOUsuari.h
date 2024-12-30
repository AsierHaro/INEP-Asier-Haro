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
		edat = usu.obteEdat();
	}

	friend ostream& operator<<(ostream& os, const DTOUsuari& dto) {
		os << "Nom complet: " << dto.nom << endl;
		os << "Sobrenom: " << dto.sobrenom << endl;
		os << "Correu electronic: " << dto.correu << endl;
		os << "Data naixament (DD/MM/AAAA): " << dto.data << endl;
		os << "Modalitat subscripcio: " << dto.modalitatSubscripcio << endl;
		return os;
	}

	string obteSobrenom() { return sobrenom; }
	string obteNom() { return nom; }
	string obteCorreu() { return correu; }
	string obteData() { return data; }
	string obteSubscripcio() { return modalitatSubscripcio; }
	int obteEdat() { return edat; }
private:
	string sobrenom = "";
	string nom = "";
	string correu = "";
	string modalitatSubscripcio = "";
	string data = " ";
	int edat = 0;
};
