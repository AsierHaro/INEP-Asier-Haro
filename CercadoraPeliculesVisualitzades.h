#pragma once
#include "PassarelaPeliculaVisualitzada.h"
#include "ConnexioBD.h"

class CercadoraPeliculesVisualitzades
{
public:
    vector<PassarelaPeliculaVisualitzada> cercaVisualitzacions(string sobrenom) {
        ConnexioBD bd;
        std::string sql =
            "SELECT v.titol_pelicula, DATE_FORMAT(v.data, '%d/%m/%Y %H:%i') AS data_formateada, "
            "v.num_visualitzacions, c.qualificacio , c.descripcio "
            "FROM visualitzacio_pelicula v "
            "INNER JOIN contingut c ON v.titol_pelicula = c.titol "
            "WHERE v.sobrenom_usuari = '" + sobrenom + "' ";
            "ORDER BY v.data DESC";
        sql::ResultSet* res = bd.execQuery(sql);
        vector<PassarelaPeliculaVisualitzada> resultats;
        while (res->next()) {
            PassarelaPeliculaVisualitzada p = PassarelaPeliculaVisualitzada(res->getString("data_formateada"), res->getString("titol_pelicula"), res->getString("descripcio"), res->getString("qualificacio"), res->getInt("num_visualitzacions"));
            resultats.push_back(p);
        }
        delete res;
        return resultats;
    }
};
