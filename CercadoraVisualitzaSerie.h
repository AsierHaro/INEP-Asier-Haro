#pragma once
#include "PassarelaVisualitzaSerie.h"
#include "ConnexioBD.h"

class CercadoraVisualitzaSerie {
public:
   /*vector<PassarelaVisualitzaSerie> cercaVisualitzacions(const string& sobrenom) {
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

    vector<DTOCapitol> cercaCapitolsPerTemporada(const string& sobrenomSerie, int numeroTemporada) {
        ConnexioBD bd;
        std::string sql =
            "SELECT c.numero, c.titol, DATE_FORMAT(c.dataEstrena, '%d/%m/%Y') AS dataEstrena, "
            "DATE_FORMAT(c.dataVisualitzacio, '%d/%m/%Y') AS dataVisualitzacio "
            "FROM capitol c "
            "WHERE c.sobrenomSerie = '" + sobrenomSerie + "' AND c.numeroTemporada = " + to_string(numeroTemporada) +
            " ORDER BY c.numero DESC";

        sql::ResultSet* res = bd.execQuery(sql);

        vector<DTOCapitol> capitols;

        if (res != nullptr) {
            while (res->next()) {
                int numero = res->getInt("numero");
                string titol = res->getString("titol");
                string dataEstrena = res->getString("dataEstrena");
                string dataVisualitzacio = res->getString("dataVisualitzacio");

                DTOCapitol capitol(numero, titol, dataEstrena, dataVisualitzacio);
                capitols.push_back(capitol);
            }
            delete res;
        }

        return capitols;
    }*/
};


