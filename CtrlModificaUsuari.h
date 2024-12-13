#pragma once
#include "PassarelaUsuari.h"
#include "TxConsultarUsuari.h"
class CtrlModificaUsuari
{
	private:
		PassarelaUsuari* usuari;
	public:
		CtrlModificaUsuari(){
		}

		DTOUsuari consultaUsuari() {
			TxConsultarUsuari tx;
			tx.executar();
			DTOUsuari usu = tx.obteResultat();
			usuari = tx.obteUsuari();
			return usu;
		}
		
		void modificaUsuari(string nomU, string contraU, string correuU, string neixU, string modalitatU) {
			usuari->posaNom(nomU);
			usuari->posaContrasenya(contraU);
			usuari->posaCorreuElectronic(correuU);
			usuari->posaData(neixU);
			usuari->posaModalitatSubscripcio(modalitatU);
			usuari->modifica();
		}

};

