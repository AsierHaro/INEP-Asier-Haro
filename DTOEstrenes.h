#pragma once
#include "ConnexioBD.h"

class DTOEstrenes
{
public:
	DTOEstrenes() {}
	DTOEstrenes(string dataE, string tipusE, string titolE, string edatE, int duracioE, int temporadaE){
		data = dataE;
		tipus = tipusE;
		titol = titolE;
		edat = edatE;
		duracio = duracioE;
		temporada = temporadaE;
	}

	friend ostream& operator<<(ostream& os, const DTOEstrenes& est) {
		os << est.data ;
		if (est.tipus == "pelicula") {
			os << " [Pel·lícula]: " << est.titol << "; " << est.edat << "; " << est.duracio << " min.";
		}
		else {
			os << " [Sèrie]: " << est.titol << "; " << est.edat << "; " << "Temporada " << est.temporada << ".";
		}
		os << endl;
		return os;
	}

	string obteData() { return data; }
	string obteTipus() { return tipus; }
	string obteTitol() { return titol; }
	string obteEdat() { return edat; }
	int obteDuracio() { return duracio; }
	int obteTemporada() { return temporada; }
private:
private:
	string data = " ";
	string tipus = " ";
	string titol = " ";
	string edat = " ";
	int duracio = 0;
	int temporada = 0;
};