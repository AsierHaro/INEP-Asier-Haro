#pragma once
#include "TxConsultarUsuari.h"
#include "PassarelaUsuari.h"
class CtrlModificarContrasenya
{
private:
	PassarelaUsuari* usuari;
public:
	CtrlModificarContrasenya() {
	}

	bool vol_modificar = true;

	void modificaUsuari(string contrA, string contrN){
		TxConsultarUsuari tx;
		tx.executar();
		usuari = tx.obteUsuari();

		if (usuari->obteContrasenya() == contrA && contrA != contrN) {
			usuari->posaContrasenya(contrN);
			usuari->modifica();
			vol_modificar = false;
		}
		else {
			if (usuari->obteContrasenya() != contrA) {
				vol_modificar = false;
				throw std::runtime_error("La contrasenya no coincideix");
			}
			else {
				throw std::runtime_error("La nova contrasenya es igual a l'anterior");
			}
		}
	}
};

