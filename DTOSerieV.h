#pragma once

class DTOSerieV
{
public:
	DTOSerieV() {

	}
	DTOSerieV(string dataS, string titolS, string edatS, int temporadaS, int capitolS, int numVisualitzacionsS) {
		data = dataS;
		titol = titolS;
		edat = edatS;
		temporada = temporadaS;
		capitol = capitolS;
		numVisualitzacions = numVisualitzacionsS;
	}

	friend ostream& operator<<(ostream& os, const DTOSerieV& MV) {
		os << " - " << MV.data << ": " << MV.titol << "; " << MV.edat << "; Temporada " << MV.temporada << ", capítulo " << MV.capitol << "; nombre de visualitzacions: " << MV.numVisualitzacions << endl;
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
