#pragma once
#include "PassarelaSerieVisualitzada.h"
#include "ConnexioBD.h"

class CercadoraSeriesVisualitzades
{
public:
    vector<PassarelaSerieVisualitzada> cercaVisualitzacions(string sobrenom) {
        ConnexioBD bd;
        std::string sql =
            "SELECT v.titol_serie, DATE_FORMAT(v.data, '%d/%m/%Y %H:%i') AS data_formateada, "
            "v.num_visualitzacions, c.qualificacio, v.num_temporada, v.num_capitol "
            "FROM visualitzacio_capitol v "
            "INNER JOIN contingut c ON v.titol_serie = c.titol "
            "WHERE v.sobrenom_usuari = '" + sobrenom + "' ";
            "ORDER BY v.data DESC";
        sql::ResultSet* res = bd.execQuery(sql);
        vector<PassarelaSerieVisualitzada> resultats;
        while (res->next()) {
            PassarelaSerieVisualitzada p = PassarelaSerieVisualitzada(res->getString("data_formateada"), res->getString("titol_serie"), res->getString("qualificacio"),res->getInt("num_temporada"), res->getInt("num_capitol"), res->getInt("num_visualitzacions"));
            resultats.push_back(p);
        }
        delete res;
        return resultats;
    }
};