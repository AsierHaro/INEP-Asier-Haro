#pragma once
#include "ConnexioBD.h"
class PassarelaEstrenes
{
private:
	string data;
	string tipus;
	string titol;
	string edat;
	int duracio;
	int temporada;
public:
	PassarelaEstrenes() {
		data = " ";
		tipus = " ";
		titol = " ";
		edat = " ";
		duracio = 0;
		temporada = 0;

	}

	PassarelaEstrenes(string dataE,string tipusE,string titolE,string edatE,int duracioE,int temporadaE) {
		data = dataE;
		tipus = tipusE;
		titol = titolE;
		edat = edatE;
		duracio = duracioE;
		temporada = temporadaE;
	}
	string obtedata() {
		return data;
	}
	friend ostream& operator<<(ostream& os, const PassarelaEstrenes& est) {
		os << est.data << " [" << est.tipus << "]: " << est.titol << "; " << est.edat << "; ";
		if (est.tipus == "Pel·lícula") {
			os << est.duracio << " min.";
		}
		else {
			os << "Temporada "<<est.temporada << ".";
		}
		os << endl;
		return os;
	}
};