#pragma once
#include "PassarelaVisualitzaPel.h"
#include "CercadoraVisualitzaPel.h"

class DTOPel {
public:
   
    DTOPel() {}

    DTOPel(PassarelaVisualitzaPel pel) {
        sobrenom = pel.obteSobrenom();
        titolPel = pel.obteTitolPel();
        descripcio = pel.obteDescripcio();
        data = pel.obteData();
        numVisualitzacions = pel.obtenNumVisualitzacions();
    }

    friend std::ostream& operator<<(ostream& os, const DTOPel& dto) {
        //os << "Sobrenom: " << dto.sobrenom << endl;
        os << "Nom pel·lícula: " << dto.titolPel << endl;
        os << "Descripcio: " << dto.descripcio << endl;
        os << "Data visualització: " << dto.data << endl;
        os << "Número de visualitzacions: " << dto.numVisualitzacions << endl;
        return os;
    }

    string obteSobrenom() const { return sobrenom; }
    string obteTitolPel() const { return titolPel; }
    string obteData() const { return data; }
    string obteDescripcio() const {
        return descripcio;
    }
    int obteNumVisualitzacions() const { return numVisualitzacions; }

private:
 
    string sobrenom = "";
    string titolPel = "";
    string descripcio = "";
    string data = "";
    int numVisualitzacions = 0;
};