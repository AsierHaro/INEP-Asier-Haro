#pragma once
class DTOPeliV
{
public:
	DTOPeliV() {}

	DTOPeliV(string dataV, string titolV, string descripcioV, string edatV, int numVisualitzacionsV) {
		data = dataV;
		titol = titolV;
		descripcio = descripcioV;
		edat = edatV;
		numVisualitzacions = numVisualitzacionsV;
	}

	friend ostream& operator<<(ostream& os, const DTOPeliV& MV) {
		os << MV.data<< ": "<< MV.titol << "; " << MV.descripcio << "; " << MV.edat << "; nombre de visualitzacions: " << MV.numVisualitzacions << endl;
		return os;
	}

	string obteData() { return data; }
	string obteTitol() { return titol; }
	string obteEdat() { return edat; }
	string obteDescripcio() { return descripcio; }
	int obteVisualitzacions() { return numVisualitzacions; }
private:
	string data = " ";
	string titol = " ";
	string descripcio = " ";
	string edat = " ";
	int numVisualitzacions = 0;
};