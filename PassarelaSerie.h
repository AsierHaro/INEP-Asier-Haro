#pragma once

#include "PassarelaContingut.h"
#include "PassarelaTemporada.h"
class PassarelaSerie 
{
	private:
		PassarelaContingut Contingut;
		string data_estrena;
		vector<PassarelaTemporada> Temporades;
	public:
		PassarelaSerie() {
			data_estrena = " ";
		}
		PassarelaSerie(PassarelaContingut ContingutS,string data_estrenaS,vector<PassarelaTemporada> TemporadesS) {
			Contingut = ContingutS;
			data_estrena = data_estrenaS;
			Temporades = TemporadesS;
		}
};