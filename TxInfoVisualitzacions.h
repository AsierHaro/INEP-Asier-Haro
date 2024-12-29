#pragma once
#include "Petitflix.h"
#include "PassarelaUsuari.h"
#include "CercadoraVisualitzaPel.h"
#include "CercadoraVisualitzaSerie.h"
class TxInfoVisualitzacions
{
	private:
		int nP;
		int nS;
	public:
		TxInfoVisualitzacions() {
			nP = 0;
			nS = 0;
		}

		void executar() {
			Petitflix& petitflix = Petitflix::getInstance();
			PassarelaUsuari *usuari = petitflix.obteUsuari();
			string sobrenom = usuari->obteSobrenom();
			CercadoraVisualitzaPel Pel;
			nP = Pel.cercaVisualitzacions(sobrenom);
			CercadoraVisualitzaSerie Serie;
			nS = Serie.cercaElemen(sobrenom);
		}

		int obtePel() { return nP; }
		int obteSerie() { return nS; }

};

