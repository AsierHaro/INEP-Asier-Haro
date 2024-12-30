#pragma once
#include "PassarelaVisualitzaPel.h"
#include "ConnexioBD.h"

class CercadoraPelicula
{
public:
    PassarelaVisualitzaPel cercaVisualitzacions(string titol) {
        ConnexioBD bd;
        std::string sql =
            "SELECT c.titol, DATE_FORMAT(p.data_estrena, '%d/%m/%Y') AS data_formateada, "
            "p.duracio, c.descripcio, c.qualificacio, "
            "p.data_estrena <= NOW() AS estrenada "
            "FROM contingut c "
            "INNER JOIN pelicula p ON c.titol = p.titol "
            "WHERE c.titol = '" + titol + "'";

        sql::ResultSet* res = bd.execQuery(sql);
        PassarelaVisualitzaPel resultat;
        if (!res->next()) {
            delete res;
            throw std::runtime_error("La pelicula '" + titol + "' no existeix en la base de dades.");
        }
        else {
            if (!res->getBoolean("estrenada")) {
                delete res;
                throw std::runtime_error("La pelicula '" + titol + "' no s'ha estrenad.");
            }
            resultat = PassarelaVisualitzaPel(res->getString("titol"), res->getInt("duracio"), " ", res->getString("data_formateada"), res->getString("descripcio"), 0, res->getString("qualificacio"));
        }
        delete res;


        return resultat;
    }
};
