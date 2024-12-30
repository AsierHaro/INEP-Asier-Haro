#pragma once
#include <iostream>
#include <string>
class DTOPelMesV
{
public:
	DTOPelMesV() {}
	DTOPelMesV(string dataV, string titolV, string edatV, int duracioV, int visualitzacionsV) {
		data = dataV;
		titol = titolV;
		edat = edatV;
		duracio = duracioV;
		visualitsacions = visualitzacionsV;
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