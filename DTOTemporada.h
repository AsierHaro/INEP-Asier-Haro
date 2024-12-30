#pragma once
#include <iostream>
#include <string>
class DTOTemporada {
public:
	DTOTemporada() {
		numtemporada = 0;
		string qualificacio = " ";
	}
	DTOTemporada(int numtemporadaT, string qualificacioT) {
		numtemporada = numtemporadaT;
		qualificacio = qualificacioT;
	}
	int obtenumtemporada() {
		return numtemporada;
	}
	string obtequalificacio() {
		return qualificacio;
	}
private:
	int numtemporada;
	string qualificacio;


};
