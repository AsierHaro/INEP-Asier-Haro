#pragma once
#include "PassarelaNSerie.h"
class DTONserie
{
public:
	DTONserie() {}
	DTONserie(PassarelaNSerie Ns) {
		data = Ns.obtedata();
		titol = Ns.obtetitol();
		edat = Ns.obteedat();
		duracio = Ns.obteduracio();
		cap = Ns.obtecap();
		temporada = Ns.obtetemporada();
	}

	friend ostream& operator<<(ostream& os, const DTONserie& Np) {
		os << Np.data << ": " << Np.titol << "; " << Np.edat << " ; Temporada " << Np.temporada << "; Capítol " << Np.cap << "; " << Np.duracio << " min." << endl;
		return os;
	}

	string obteData() { return data; }
	string obteTitol() { return titol; }
	string obteEdat() { return edat; }
	int obteDuracio() { return duracio; }
	int obteTemporda() { return temporada; }
	int obteCap() { return cap; }
private:
	string data = " ";
	string titol = " ";
	string edat = " ";
	int duracio = 0;
	int cap = 0;
	int temporada = 0;
};