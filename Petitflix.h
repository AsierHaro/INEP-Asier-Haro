#pragma once
#include "PassarelaUsuari.h"
class Petitflix
{
	private:
		PassarelaUsuari usuari;
		Petitflix(){
		}
	public:

		static Petitflix& getInstance() {
			static Petitflix instance;
			return instance;
		}

		void iniciaSesio(PassarelaUsuari u) {
			usuari = u;
		}
		void tancaSesio() {
			usuari.posaSobrenom("");
			usuari.posaNom("");
			usuari.posaCorreuElectronic("");
			usuari.posaModalitatSubscripcio("");
			usuari.posaContrasenya("");
		}
		PassarelaUsuari obteUsuari() {
			return usuari;
		}

};

