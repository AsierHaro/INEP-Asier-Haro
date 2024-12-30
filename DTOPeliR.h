#pragma once
#include "PassarelaVisualitzaPel.h"

class DTOPeliR {
public:

    DTOPeliR() {}

    DTOPeliR(PassarelaVisualitzaPel pel) {
        titolPel = pel.obteTitolPel();
        qualificacio = pel.obteQualificacio();
        descripcio = pel.obteDescripcio();
        duracio = pel.obteDuracio();
        data = pel.obteData();
    }

    friend std::ostream& operator<<(ostream& os, DTOPeliR& dto) {
        os << "- " << dto.titolPel << "; " << dto.descripcio << "; " << dto.qualificacio << "; " << dto.duracio << " min; " << dto.data << endl;

        return os;
    }

    string obteQualificacio() const { return qualificacio; }
    int obteDuracio() const { return duracio; }
    string obteTitolPel() const { return titolPel; }
    string obteData() const { return data; }
    string obteDescripcio() const { return descripcio; }


private:

    string qualificacio = "";
    int duracio = 0;
    string titolPel = "";
    string descripcio = "";
    string data = "";
};
