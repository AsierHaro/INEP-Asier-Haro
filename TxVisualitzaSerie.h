#include "CercadoraCapitolsTemporada.h"
#include "PassarelaVisualitzaSerie.h"


class TxVisualitzaSerie {
private:

	string numUsuari;
	string titol;
	int numtemporada;
	vector<DTOCapitol> resultat;
public:
	TxVisualitzaSerie() {}

	void executar(string numUsuariS, string titolS, int numtemporadaS) {
		numUsuari = numUsuariS;
		titol = titolS;
		numtemporada = numtemporadaS;
		CercadoraCapitolsTemporada cerca;
		resultat = cerca.cercaCapitolsPerTemporada(titol, numtemporada, numUsuari);
	}
	vector<DTOCapitol> obteresultat() {
		return resultat;
	}
	string visualitzar(int num) {
		PassarelaVisualitzaSerie p = PassarelaVisualitzaSerie(titol, numUsuari, numtemporada, num);
		return p.visualitzar();
	}
};
