#pragma once
#include "ConnexioBD.h"
class PassarelaNSerie
{
private:
	string data;
	string titol;
	string edat;
	int temporada;
	int cap;
	int duracio;
public:
	PassarelaNSerie() {
		data = " ";
		titol = " ";
		edat = " ";
		temporada = 0;
		cap = 0;
		duracio = 0;

	}

	PassarelaNSerie(string dataN, string titolN, string edatN, int duracioN, int capN, int temporadaN) {
		data = dataN;
		titol = titolN;
		edat = edatN;
		duracio = duracioN;
		cap = capN;
		temporada = temporadaN;
	}
	string obtedata() {
		return data;
	}
	string obtetitol() {
		return titol;
	}
	string obteedat() {
		return edat;
	}
	int obteduracio() {
		return duracio;
	}
	int obtetemporada() {
		return temporada;
	}
	int obtecap() {
		return cap;
	}
};