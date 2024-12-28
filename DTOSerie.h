#pragma once
#include "PassarelaVisualitzaSerie.h"
#include "CercadoraVisualitzaSerie.h"
#include <vector>

class DTOCapitol {
public:
    DTOCapitol() {}

    DTOCapitol(int numero, const string& titol, const string& dataEstrena, const string& dataVisualitzacio)
        : numero(numero), titol(titol), dataEstrena(dataEstrena), dataVisualitzacio(dataVisualitzacio) {}

    int obteNumero() const { return numero; }
    string obteTitol() const { return titol; }
    string obteDataEstrena() const { return dataEstrena; }
    string obteDataVisualitzacio() const { return dataVisualitzacio; }

    friend ostream& operator<<(ostream& os, const DTOCapitol& capitol) {
        os << capitol.numero << ". " ;
        os << capitol.titol << "; " ;
        os << capitol.dataEstrena << "; " << endl;
        if (!capitol.dataVisualitzacio.empty()) {
            os << "visualitzat el " << capitol.dataVisualitzacio << endl;
        }
        else {
            os << "no visualitzat" << endl;
        }
        return os;
    }

private:
    int numero = 0;
    string titol = "";
    string dataEstrena = "";
    string dataVisualitzacio = "";
};


class DTOTemporada {
public:
    DTOTemporada() {}

    DTOTemporada(int numero, const vector<DTOCapitol>& capitols)
        : numero(numero), capitols(capitols) {}

    int obteNumero() const { return numero; }
    const vector<DTOCapitol>& obteCapitols() const { return capitols; }

    friend ostream& operator<<(ostream& os, const DTOTemporada& temporada) {
        os << "Temporada número: " << temporada.numero << endl;
        return os;
    }

private:
    int numero = 0;
    vector<DTOCapitol> capitols;
};

class DTOSerie {
public:
    DTOSerie() {}

    DTOSerie(PassarelaVisualitzaSerie serie) {
        sobrenom = serie.obteSobrenom();
        titolSerie = serie.obteTitolSerie();
        numTemporada = serie.obteTemporada();
    }

    string obteSobrenom() const { return sobrenom; }
    string obteTitolSerie() const { return titolSerie; }
    int obteTemporada() const { return numTemporada; }
    const std::vector<DTOTemporada>& obteTemporades() const { return temporades; }

private:

    string sobrenom = "";
    string titolSerie = "";
    int numTemporada = 0;
    std::vector<DTOTemporada> temporades;
    int numCapitol;
    string data;
    int numVisualitzacions;
};
