#pragma once
#include "Petitflix.h"
#include "PassarelaUsuari.h"
#include "DTOUsuari.h"
class TxConsultarUsuari
{
	private:
		DTOUsuari resultat;
		PassarelaUsuari* usuari;
	public:

		TxConsultarUsuari(){
		}

		void executar(){
			Petitflix& petitflix = Petitflix::getInstance();
			usuari = petitflix.obteUsuari();
			resultat = DTOUsuari(*usuari);
		}

		DTOUsuari obteResultat() {
			return resultat;
		}

		PassarelaUsuari* obteUsuari() {
			return usuari;
		}



};

