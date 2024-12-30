#pragma once
#include "PassarelaVisualitzaPel.h"

class DTOPel {
public:

    DTOPel() {}

    DTOPel(PassarelaVisualitzaPel pel) {
        sobrenom = pel.obteSobrenom();
        titolPel = pel.obteTitolPel();
        qualificacio = pel.obteQualificacio();
        descripcio = pel.obteDescripcio();
        duracio = pel.obteDuracio();
        data = pel.obteData();
        numVisualitzacions = pel.obtenNumVisualitzacions();
    }

    friend std::ostream& operator<<(ostream& os, DTOPel& dto) {
        os << "Nom pel·lícula: " << dto.titolPel << endl;
        os << "Qualificacio edat: " << dto.qualificacio << endl;
        os << "Descripcio: " << dto.descripcio << endl;
        os << "Data estrena: " << dto.data << endl;
        os << "Duracio: " << dto.duracio << endl;

        return os;
    }

    string obteSobrenom() const { return sobrenom; }
    string obteQualificacio() const { return qualificacio; }
    int obteDuracio() const { return duracio; }
    string obteTitolPel() const { return titolPel; }
    string obteData() const { return data; }
    string obteDescripcio() const {
        return descripcio;
    }
    int obteNumVisualitzacions() const { return numVisualitzacions; }

private:

    string sobrenom = "";
    string qualificacio = "";
    int duracio = 0;
    string titolPel = "";
    string descripcio = "";
    string data = "";
    int numVisualitzacions = 0;
};
