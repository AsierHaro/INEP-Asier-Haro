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

    friend std::ostream& operator<<(std::ostream& os, const DTOPel& dto) {
        os << "Sobrenom: " << dto.sobrenom << std::endl;
        os << "Títol pel·lícula: " << dto.titolPel << std::endl;
        os << "Data visualització: " << dto.data << std::endl;
        os << "Número de visualitzacions: " << dto.numVisualitzacions << std::endl;
        return os;
    }

    std::string obteSobrenom() const { return sobrenom; }
    std::string obteTitolPel() const { return titolPel; }
    std::string obteData() const { return data; }
    int obteNumVisualitzacions() const { return numVisualitzacions; }

private:
 
    std::string sobrenom = "";
    std::string titolPel = "";
    std::string data = "";
    int numVisualitzacions = 0;
};