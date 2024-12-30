#pragma once
#include "PassarelaVisualitzaPel.h"
#include "ConnexioBD.h"

class CercadoraPeliculesRelacionades
{
public:
    vector<PassarelaVisualitzaPel> cerca(string titol) {
        ConnexioBD bd;
        std::string query =
            "SELECT DISTINCT "
            "    CASE "
            "        WHEN r.titol_x = '" + titol + "' THEN r.titol_y "
            "        WHEN r.titol_y = '" + titol + "' THEN r.titol_x "
            "    END AS titol, "
            "    DATE_FORMAT(p.data_estrena, '%d/%m/%Y') AS data_formateada, "
            "    p.duracio, "
            "    c.descripcio, "
            "    c.qualificacio "
            "FROM relacionat r "
            "INNER JOIN pelicula p ON (p.titol = CASE "
            "        WHEN r.titol_x = '" + titol + "' THEN r.titol_y "
            "        WHEN r.titol_y = '" + titol + "' THEN r.titol_x "
            "    END) "
            "INNER JOIN contingut c ON c.titol = p.titol "
            "WHERE (r.titol_x = '" + titol + "' OR r.titol_y = '" + titol + "')";
        sql::ResultSet* res = bd.execQuery(query);
        vector<PassarelaVisualitzaPel> resultats;
        while (res->next()) {
            PassarelaVisualitzaPel p = PassarelaVisualitzaPel(res->getString("titol"), res->getInt("duracio"), " ", res->getString("data_formateada"), res->getString("descripcio"), 0, res->getString("qualificacio"));
            resultats.push_back(p);
        }
        delete res;
        return resultats;
    }
};

