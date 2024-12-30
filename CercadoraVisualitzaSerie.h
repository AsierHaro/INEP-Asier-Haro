#pragma once
#include "ConnexioBD.h"

class CercadoraVisualitzaSerie
{
public:
    int cercaElemen(string sobrenom) {
        ConnexioBD bd;
        std::string sql =
            "SELECT SUM(v.num_visualitzacions) AS total_visualitzacions "
            "FROM visualitzacio_capitol v "
            "WHERE v.sobrenom_usuari = '" + sobrenom + "'";

        sql::ResultSet* res = bd.execQuery(sql);
        int resultat = 0;
        if (res->next()) {
            resultat = res->getInt("total_visualitzacions");
        }
        delete res;


        return resultat;
    }
};

