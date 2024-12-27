#pragma once

#include "PassarelaContingut.h"
class PassarelaPel·lícula {
	private:
		PassarelaContingut Contingut;
		string data_estrena;
		int duracio;
		PassarelaPel·lícula() {
			data_estrena = " ";
			duracio = 0;

		}
		PassarelaPel·lícula(PassarelaContingut ContingutP,string data_estrenaP,int duracioP) {
			Contingut = ContingutP;
			data_estrena = data_estrenaP;
			duracio = duracioP;
		}
		PassarelaContingut obteContingut() {
			return Contingut;
		}
		string obtedata_estrena() {
			return data_estrena;
		}
		int obteduracio() {
			return duracio;
		}
};