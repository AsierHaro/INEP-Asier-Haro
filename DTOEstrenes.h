#pragma once
#include "PassarelaEstrenes.h"


class DTOEstrenes
{
public:
	DTOEstrenes() {}
	DTOEstrenes(PassarelaEstrenes est) {
		data = est.obtedata();
		tipus = est.obtetipus();
		titol = est.obtetitol();
		edat = est.obteedat();
		duracio = est.obteduracio();
		temporada = est.obtetemporada();
	}

	friend ostream& operator<<(ostream& os, const DTOEstrenes& est) {
		os << est.data << " [" << est.tipus << "]: " << est.titol << "; " << est.edat << "; ";
		if (est.tipus == "pelicula") {
			os << est.duracio << " min.";
		}
		else {
			os << "Temporada " << est.temporada << ".";
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