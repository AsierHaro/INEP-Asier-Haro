#pragma once
#include "CercadoraVisualitzaPel.h"
#include "PassarelaVisualitzaPel.h"
#include <vector>

class TxVisualitzaPel {
private:
    CercadoraVisualitzaPel cercadora;

public:
    TxVisualitzaPel() {}

    vector<PassarelaVisualitzaPel> obteVisualitzacions(string sobrenom) {
        return cercadora.cercaVisualitzacions(sobrenom);
    }

    void insereixVisualitzacio(const PassarelaVisualitzaPel& visualitzacio) {
        visualitzacio.insereix();
    }

    void esborraVisualitzacio(const std::string& sobrenom) {
        PassarelaVisualitzaPel visualitzacio;
        visualitzacio.esborra();
    }

    void modificaVisualitzacio(PassarelaVisualitzaPel& visualitzacio, const std::string& nouTitol, const std::string& novaData, int novesVisualitzacions) {
        visualitzacio = PassarelaVisualitzaPel(nouTitol, visualitzacio.obteSobrenom(), novaData, novesVisualitzacions);
        visualitzacio.modifica();
    }
};

