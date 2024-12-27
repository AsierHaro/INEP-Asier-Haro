#pragma once
#include "ConnexioBD.h"
class PassarelaCapitol
{
private:
	string titol;
	string data_estrena;
	string qualificacio;
public:
	PassarelaCapitol() {
		titol = " ";
		data_estrena = " ";
		qualificacio = " ";
	}
	PassarelaCapitol(string titolC,string data_estrenaC,string qualificacioC) {
		titol = titolC;
		data_estrena = data_estrenaC;
		qualificacio = qualificacioC;
	}
};