#pragma once
#include "PassarelaUsuari.h"
#include "PassarelaVisualitzaPel.h"
class Petitflix
{
	private:
		PassarelaUsuari usuari;
		PassarelaVisualitzaPel pel;
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
			usuari = PassarelaUsuari();
		}
		PassarelaUsuari* obteUsuari() {
			return &usuari;
		}
		/*void visualitzacio() {
			pel = PassarelaVisualitzaPel();
		}
		PassarelaVisualitzaPel* obtenNumVisualitzacions(){
			return &pel;
		}*/

};

