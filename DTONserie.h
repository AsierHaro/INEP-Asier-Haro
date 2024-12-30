#pragma once
#include <iostream>
#include <string>
class DTONserie
{
public:
	DTONserie() {}
	DTONserie(string dataN, string titolN, string edatN, int duracioN, int capN, int temporadaN) {
		data = dataN;
		titol = titolN;
		edat = edatN;
		duracio = duracioN;
		cap = capN;
		temporada = temporadaN;
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