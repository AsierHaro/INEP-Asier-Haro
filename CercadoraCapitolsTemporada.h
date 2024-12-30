#pragma once
#include "DTOCapitol.h"

class CercadoraCapitolsTemporada {
public:
    vector<DTOCapitol> cercaCapitolsPerTemporada(const string& sobrenomSerie, int numeroTemporada, string nom) {
        ConnexioBD bd;
        std::string sql =
            "SELECT c.numero, c.titol_serie, DATE_FORMAT(c.data_estrena, '%d/%m/%Y') AS dataEstrena, "
            "IFNULL(DATE_FORMAT(vc.data, '%d/%m/%Y'), '') AS dataVisualitzacio "
            "FROM capitol c "
            "LEFT JOIN visualitzacio_capitol vc ON vc.titol_serie = c.titol_serie "
            "AND vc.sobrenom_usuari = '" + nom + "' "
            "AND vc.num_temporada = c.numero_temporada "
            "AND vc.num_capitol = c.numero "
            "WHERE c.titol_serie = '" + sobrenomSerie + "' "
            "AND c.numero_temporada = " + to_string(numeroTemporada) + " "
            "ORDER BY c.numero DESC";

        sql::ResultSet* res = bd.execQuery(sql);

        vector<DTOCapitol> capitols;

        if (res != nullptr) {
            while (res->next()) {
                int numero = res->getInt("numero");
                string titol = res->getString("titol_serie");
                string dataEstrena = res->getString("dataEstrena");
                string dataVisualitzacio = res->getString("dataVisualitzacio");

                DTOCapitol capitol(numero, titol, dataEstrena, dataVisualitzacio);
                capitols.push_back(capitol);
            }
            delete res;
        }

        return capitols;
    }
};
