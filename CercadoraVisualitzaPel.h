#pragma once
#include "PassarelaVisualitzaPel.h"
#include "ConnexioBD.h"

class CercadoraVisualitzaPel
{
public:
    vector<PassarelaVisualitzaPel> cercaVisualitzacions(string sobrenom) {
        ConnexioBD bd;
        std::string sql =
            "SELECT p.titolPel, DATE_FORMAT(v.data, '%d/%m/%Y') AS data_formateada, "
            "v.numVisualitzacions "
            "FROM visualitzacio_pelicula v "
            "JOIN pel p ON v.titolPel = p.titolPel "
            "WHERE v.sobrenom = '" + sobrenom + "'";

        sql::ResultSet* res = bd.execQuery(sql);

        vector<PassarelaVisualitzaPel> resultats;

        if (res != nullptr) {
            while (res->next()) {
                string titolPel = res->getString("titolPel");
                string dataFormateada = res->getString("data_formateada");
                int numVisualitzacions = res->getInt("numVisualitzacions");

                resultats.emplace_back(titolPel, sobrenom, dataFormateada, numVisualitzacions);
            }
            delete res;
        }

        return resultats;
    }
};




