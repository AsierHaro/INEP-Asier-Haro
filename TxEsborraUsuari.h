#pragma once
#include "Petitflix.h"
#include "PassarelaUsuari.h"
class TxEsborraUsuari
{
	private:
		string contraU;
	public:
		TxEsborraUsuari() {
			contraU = "";
		}
		TxEsborraUsuari(string contrasenyaU) {
			contraU = contrasenyaU;
		}

		void executar(){
			Petitflix& petitflix = Petitflix::getInstance();
			PassarelaUsuari* usu = petitflix.obteUsuari();
			if (usu->obteContrasenya() == contraU) {
				usu->esborra();
			}
			else {
				throw std::runtime_error("La contrasenya no es correcta, l'usuari no s'esborrat");
			}
		}

};

