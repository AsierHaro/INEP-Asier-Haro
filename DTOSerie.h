#pragma once
#include "PassarelaVisualitzaSerie.h"
#include "CercadoraVisualitzaSerie.h"
#include "DTOTemporada.h"
#include <vector>


class DTOSerie {
public:
    DTOSerie() {}

    /*DTOSerie(PassarelaVisualitzaSerie serie) {
        sobrenom = serie.obteSobrenom();
        titolSerie = serie.obteTitolSerie();
        numTemporada = serie.obteTemporada();
    }

    string obteSobrenom() const { return sobrenom; }
    string obteTitolSerie() const { return titolSerie; }
    int obteTemporada() const { return numTemporada; }
    const std::vector<DTOTemporada>& obteTemporades() const { return temporades; }
    */
private:

    string sobrenom = "";
    string titolSerie = "";
    int numTemporada = 0;
    //std::vector<DTOTemporada> temporades;
    int numCapitol;
    string data;
    int numVisualitzacions;
};
