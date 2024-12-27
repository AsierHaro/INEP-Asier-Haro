#pragma once
#include "PassarelaVisualitzaPel.h"
#include "CercadoraVisualitzaPel.h"

class DTOPel {
public:
   
    DTOPel() {}

    DTOPel(PassarelaVisualitzaPel pel) {
        sobrenom = pel.obteSobrenom();
        titolPel = pel.obteTitolPel();
        data = pel.obteData();
        numVisualitzacions = pel.obtenNumVisualitzacions();
    }

    friend std::ostream& operator<<(ostream& os, const DTOPel& dto) {
        os << "Sobrenom: " << dto.sobrenom << endl;
        os << "Títol pel·lícula: " << dto.titolPel << endl;
        os << "Data visualització: " << dto.data << endl;
        os << "Número de visualitzacions: " << dto.numVisualitzacions << endl;
        return os;
    }

    string obteSobrenom() const { return sobrenom; }
    string obteTitolPel() const { return titolPel; }
    string obteData() const { return data; }
    int obteNumVisualitzacions() const { return numVisualitzacions; }

private:
 
    string sobrenom = "";
    string titolPel = "";
    string data = "";
    int numVisualitzacions = 0;
};