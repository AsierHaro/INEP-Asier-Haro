#pragma once
#include "ConnexioBD.h"
class PassarelaSerieVisualitzada
{
private:
	string data;
	string titol;
	string edat;
	int temporada;
	int capitol;
	int numVisualitzacions;


public:
	PassarelaSerieVisualitzada() {
		data = "";
		titol = "";
		edat = " ";
		temporada = 0;
		capitol = 0;
		numVisualitzacions = 0;
	}

	PassarelaSerieVisualitzada(string dataS, string titolS, string edatS, int temporadaS,int capitolS,int numVisualitzacionsS) {
		data = dataS;
		titol = titolS;
		edat = edatS;
		temporada = temporadaS;
		capitol = capitolS;
		numVisualitzacions = numVisualitzacionsS;
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
	int  obtetemporda() {
		return temporada;
	}
	int obtecapitol() {
		return capitol;
	}
	int obtenumVisualitzacions() {
		return numVisualitzacions;
	}
};