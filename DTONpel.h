#pragma once
#include "PassarelaNPelicula.h"
class DTONpel
{
public:
	DTONpel() {}
	DTONpel(PassarelaNPelicula& Np) {
		data = Np.obtedata();
		titol = Np.obtetitol();
		edat = Np.obteedat();
		duracio = Np.obteduracio();
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