#pragma once
#include "ConnexioBD.h"
class PassarelaNPelicula
{
private:
	string data;
	string titol;
	string edat;
	int duracio;
public:
	PassarelaNPelicula() {
		data = " ";
		titol = " ";
		edat = " ";
		duracio = 0;

	}

	PassarelaNPelicula(string dataN, string titolN, string edatN, int duracioN) {
		data = dataN;
		titol = titolN;
		edat = edatN;
		duracio = duracioN;
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
};
