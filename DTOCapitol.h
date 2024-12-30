#pragma once
#include <iostream>
#include <string>
class DTOCapitol {
public:
    DTOCapitol() {}

    DTOCapitol(int numero, const string& titol, const string& dataEstrena, const string& dataVisualitzacio)
        : numero(numero), titol(titol), dataEstrena(dataEstrena), dataVisualitzacio(dataVisualitzacio) {
    }

    int obteNumero() const { return numero; }
    string obteTitol() const { return titol; }
    string obteDataEstrena() const { return dataEstrena; }
    string obteDataVisualitzacio() const { return dataVisualitzacio; }

    friend ostream& operator<<(ostream& os, const DTOCapitol& capitol) {
        os << capitol.numero << ". ";
        os << capitol.titol << "; ";
        os << capitol.dataEstrena << "; ";
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
