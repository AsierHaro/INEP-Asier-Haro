#pragma once
#include "PassarelaPelMesV.h"
class DTOPelMesV
{
public:
	DTOPelMesV() {}
	DTOPelMesV(PassarelaPelMesV& MV) {
		data = MV.obtedata();
		titol = MV.obtetitol();
		edat = MV.obteedat();
		duracio = MV.obteduracio();
		visualitsacions = MV.obtevisualitzacions();
	}

	friend ostream& operator<<(ostream& os, const DTOPelMesV& MV) {
		os << MV.titol << "; " << MV.edat << "; " << MV.duracio << " min.; Visualitzacions: " << MV.visualitsacions;
		if (MV.data != "") {
			os << " [VISTA: " << MV.data << "]";
		}
		os << endl;
		return os;
	}

	string obteData() { return data; }
	string obteTitol() { return titol; }
	string obteEdat() { return edat; }
	int obteDuracio() { return duracio; }
	int obteVisualitzacions() { return visualitsacions; }
private:
	string data = " ";
	string titol = " ";
	string edat = " ";
	int duracio = 0;
	int visualitsacions = 0;
};