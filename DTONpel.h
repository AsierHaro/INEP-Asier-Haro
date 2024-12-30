#pragma once
#include "ConnexioBD.h"
class DTONpel
{
public:
	DTONpel(string dataN, string titolN, string edatN, int duracioN) {
		data = dataN;
		titol = titolN;
		edat = edatN;
		duracio = duracioN;
	}

	friend ostream& operator<<(ostream& os, const DTONpel& Np) {
		os << Np.data << ": " << Np.titol << "; " << Np.edat << " ; " << Np.duracio << " min." << endl;
		return os;
	}

	string obteData() { return data; }
	string obteTitol() { return titol; }
	string obteEdat() { return edat; }
	int obteDuracio() { return duracio; }
private:
	string data = " ";
	string titol = " ";
	string edat = " ";
	int duracio = 0;
};