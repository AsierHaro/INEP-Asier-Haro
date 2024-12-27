#pragma once
#include "PassarelaCapitol.h"

class PassarelaTemporada
{
	private:
		int numero;
		vector<PassarelaCapitol> capitols;
	public:
		PassarelaTemporada() {
			numero = 0;
		}
		PassarelaTemporada(int numeroT,vector<PassarelaCapitol> capitolsT) {
			numero = numeroT;
			capitols = capitolsT;
		}
};