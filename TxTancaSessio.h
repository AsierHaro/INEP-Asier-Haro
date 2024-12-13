#pragma once
#include "Petitflix.h"
class TxTancaSessio
{
	public:
		TxTancaSessio() {
		}
		void executar() {
			Petitflix& petitflix = Petitflix::getInstance();
			petitflix.tancaSesio();
		}


};

