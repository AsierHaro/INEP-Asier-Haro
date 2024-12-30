#pragma once
#include "DTOTemporada.h"

class CercadoraTemporadas
{
public:
    DTOTemporada cercaTemporada(string nom) {
        ConnexioBD bd;
        std::string sql =
            "SELECT t.numero, c.qualificacio, t.titol_serie "
            "FROM temporada t "
            "INNER JOIN contingut c ON c.titol = t.titol_serie "
            "WHERE t.titol_serie = '" + nom + "' "
            "ORDER BY t.numero DESC "
            "LIMIT 1";
        sql::ResultSet* res = bd.execQuery(sql);
        DTOTemporada resultat;
        if (!res->next()) {
            delete res;
            throw std::runtime_error("La sèrie " + nom + " no existe en la base de datos.");
        }
        else {
            resultat = DTOTemporada(res->getInt("numero"), res->getString("qualificacio"));
        }
        delete res;


        return resultat;
    }
};
