#pragma once
#include "PassarelaVisualitzaPel.h"
#include "CercadoraVisualitzaPel.h"
class DTOPel {
public:
	DTOPel() {}
	DTOPel(PassarelaVisualitzaPel pel) {
		Nom = pel.obteNom();
		Descripcio = pel.obteDescripcio();
		Edat = pel.obteEdat();
		Data = pel.obteData();
		Duracio = pel.obteDuracio();
		Visualitzacio = pelobte.Visualitzacio();
		Relacionades = pel.obteRelacioanades();

	}
	friend ostream& operator<<(ostream& os, const DTOPel& dto) {
		os << "Nom pel.lícula: " << dto.Nom << endl;
		os << "Descripcio: " << dto.Descripcio << endl;
		os << "Qualificacio Edat: " << dto.Edat << endl;
		os << "Data estrena: " << dto.Data << endl;
		os << "Duracio: " << dto.Duracio << endl;
		return os;
	}
	string obteNom() { return Nom; }
	string obteDescripcio() { return Descripcio; }
	string obteEdat() { return Edat; }
	string obteData() { return Data; }
	string obteDuracio() { return Duracio; }
	string obteVisualitzacio() { return Visualitzacio; }
	string obteRelacionades() { return Relacionades; }
private:
	string Nom = "";
	string Descripcio = "";
	string Edat = "";
	string Data = "";
	string Duracio = " ";
	string Visualitzacio = " ";
	string Relacionades = " ";
};
