#pragma once
#include "PassarelaSerieVisualitzada.h"
class DTOSerieV
{
public:
	DTOSerieV() {}
	DTOSerieV(PassarelaSerieVisualitzada& SV) {
		data = SV.obtedata();
		titol = SV.obtetitol();
		edat = SV.obteedat();
		temporada = SV.obtetemporda();
		capitol = SV.obtecapitol();
		numVisualitzacions = SV.obtenumVisualitzacions();
	}

	friend ostream& operator<<(ostream& os, const DTOSerieV& MV) {
		os << " - " << MV.data << ": " << MV.titol << "; " << MV.edat << "; Temporada " << MV.temporada << ", capítulo "<< MV.capitol<<"; nombre de visualitzacions: " << MV.numVisualitzacions << endl;
		return os;
	}

	string obteData() { return data; }
	string obteTitol() { return titol; }
	string obteEdat() { return edat; }
	int obteTemporada() { return temporada; }
	int obteCapitol() { return capitol; }
	int obteVisualitzacions() { return numVisualitzacions; }
private:
	string data = " ";
	string titol = " ";
	string edat = " ";
	int temporada = 0;
	int capitol;
	int numVisualitzacions = 0;
};