#pragma once
#include "ConnexioBD.h"
class PassarelaContingut 
{
	private:
		string titol;
		string descripcio;
		string qualificacio;
		string tipus;
	public:
		PassarelaContingut() {
			titol = " ";
			descripcio = " ";
			qualificacio = " ";
			tipus = " ";

		}


		PassarelaContingut(string titolC,string descripcioC,string qualificacioC,string tipusC) {
			titol = titolC;
			descripcio = descripcioC;
			qualificacio = qualificacioC;
			tipus = tipusC;
		}

		string obtetitol() {
			return titol;
		}

		string obtedescripcio() {
			return descripcio;
		}

		string obtequalificacio() {
			return qualificacio;
		}
		string obtetipus() {
			return tipus;
		}
};