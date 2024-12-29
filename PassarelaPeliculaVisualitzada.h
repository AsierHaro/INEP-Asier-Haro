#pragma once
#include "ConnexioBD.h"
class PassarelaPeliculaVisualitzada
{
private:
	string data;
	string titolPel;
	string descripcio;
	string edat;
	int numVisualitzacions;


public:
	PassarelaPeliculaVisualitzada() {
		data = "";
		titolPel = "";
		descripcio = "";
		edat = " ";
		numVisualitzacions = 0;
	}

	PassarelaPeliculaVisualitzada(string dataV,string titolPelV,string descripcioV,string edatV,int numVisualitzacionsV) {
		data = dataV;
		titolPel = titolPelV;
		descripcio = descripcioV;
		edat = edatV;
		numVisualitzacions = numVisualitzacionsV;
	}

	string obtedata() {
		return data;
	}
	string obtetitol() {
		return titolPel;
	}

	string obtedescripcio() {
		return descripcio;
	}
	string obteedat() {
		return edat;
	}
	int obtenumVisualitzacions() {
		return numVisualitzacions;
	}
};