#pragma once

class DTOPeliR {
public:

    DTOPeliR() {}

    DTOPeliR(string NomP, int duracioP, string DataP, string descripcioP, string qualificacioP) {
        titolPel = NomP;
        qualificacio = qualificacioP;
        descripcio = descripcioP;
        duracio = duracioP;
        data = DataP;
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
