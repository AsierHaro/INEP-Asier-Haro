#pragma once
#include "PassarelaUsuari.h"
class TxRegistraUsuari
{
	private:
		string sobrenom;
		string nom;
		string correu_electronic;
		string contrasenya;
		string modalitatSubscripcio;
		string data;
	public:
		TxRegistraUsuari() {
			sobrenom = " ";
			nom = " ";
			correu_electronic = " ";
			contrasenya = " ";
			modalitatSubscripcio = " ";	
			data = " ";
		}

		TxRegistraUsuari(string sobrenomU, string nomU, string correuElectronicU, string contrasenyaU, string dataNaixamentU, int mS){
			sobrenom = sobrenomU;
			nom = nomU;
			correu_electronic = correuElectronicU;
			contrasenya = contrasenyaU;
			data = dataNaixamentU;
			modalitatSubscripcio = to_string(mS);
		}

		void executar() {
			PassarelaUsuari usuari(sobrenom, nom, correu_electronic, contrasenya, modalitatSubscripcio, data);
			usuari.insereix();
		}


};

