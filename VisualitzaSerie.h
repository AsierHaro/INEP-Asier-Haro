#pragma once
#include "PassarelaVisualitzaSerie.h"
#include "ConnexioBD.h"

class CercadoraVisualitzaSerie {
public:
    vector<PassarelaVisualitzaSerie> cercaVisualitzacions(const string& sobrenom) {
        ConnexioBD bd;
        std::string sql =
            "SELECT s.titolSerie, s.numTemporades, DATE_FORMAT(v.data, '%d/%m/%Y') AS data_formateada, "
            "v.numeroTemporada, v.numeroCapitol "
            "FROM visualitzacio_capitol v "
            "JOIN serie s ON v.sobrenomSerie = s.sobrenom "
            "WHERE v.sobrenomSerie = '" + sobrenom + "'";

        sql::ResultSet* res = bd.execQuery(sql);

        vector<PassarelaVisualitzaSerie> resultats;

        if (res != nullptr) {
            while (res->next()) {
                string titolSerie = res->getString("titolSerie");
                int numTemporades = res->getInt("numTemporades");

                PassarelaVisualitzaSerie serie(titolSerie, sobrenom, numTemporades);
                resultats.push_back(serie);
            }
            delete res;
        }

        return resultats;
    }


};
