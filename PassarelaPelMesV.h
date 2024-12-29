#pragma once
#include "ConnexioBD.h"
class PassarelaPelMesV
{
private:
	string data;
	string titol;
	string edat;
	int duracio;
	int visualitzacions;
public:
	PassarelaPelMesV() {
		data = " ";
		titol = " ";
		edat = " ";
		duracio = 0;
		visualitzacions = 0;
	}

	PassarelaPelMesV(string dataV, string titolV, string edatV, int duracioV, int visualitzacionsV) {
		data = dataV;
		titol = titolV;
		edat = edatV;
		duracio = duracioV;
		visualitzacions = visualitzacionsV;
	}
	string obtedata() {
		return data;
	}
	int obtevisualitzacions() {
		return visualitzacions;
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