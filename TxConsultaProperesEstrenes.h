#pragma once
#include "PassarelaEstrenes.h"
#include "CercadoraPropersEstrens.h"


class TxConsultarProperesEstrenes
{
	private:

	public:
		TxConsultarProperesEstrenes(){	
		}

		vector<PassarelaEstrenes> executar() {
			CercadoraPropersEstrens cerca;
			return cerca.cercaEstrens();
		}

};