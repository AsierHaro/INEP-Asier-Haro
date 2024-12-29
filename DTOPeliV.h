#pragma once
#include "PassarelaPeliculaVisualitzada.h"
class DTOPeliV
{
public:
	DTOPeliV() {}
	DTOPeliV(PassarelaPeliculaVisualitzada& MV) {
		data = MV.obtedata();
		titol = MV.obtetitol();
		descripcio = MV.obtedescripcio();
		edat = MV.obteedat();
		numVisualitzacions = MV.obtenumVisualitzacions();
	}

	friend ostream& operator<<(ostream& os, const DTOPeliV& MV) {
		os << MV.data<< ": "<< MV.titol << "; " << MV.descripcio << "; " << MV.edat << "; nombre de visualitzacions: " << MV.numVisualitzacions << endl;
		return os;
	}

	string obteData() { return data; }
	string obteTitol() { return titol; }
	string obteEdat() { return edat; }
	string obteDescripcio() { return descripcio; }
	int obteVisualitzacions() { return numVisualitzacions; }
private:
	string data = " ";
	string titol = " ";
	string descripcio = " ";
	string edat = " ";
	int numVisualitzacions = 0;
};