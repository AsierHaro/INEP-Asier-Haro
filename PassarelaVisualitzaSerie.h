#pragma once
#include "ConnexioBD.h"

class PassarelaVisualitzaSerie {
private:
    string sobrenom;
    string titolSerie;
    int numTemporada;
    int num;

public:
    PassarelaVisualitzaSerie() {
        sobrenom = "";
        titolSerie = "";
        numTemporada = 0;
    }

    PassarelaVisualitzaSerie(string titolSerieS, string sobrenomS, int temporadesS, int numS) {
        titolSerie = titolSerieS;
        sobrenom = sobrenomS;
        numTemporada = temporadesS;
        num = numS;
    }

    string visualitzar() const {
        ConnexioBD bd;
        string sqlp = "SELECT c.data_estrena <= NOW() AS estrenada "
            "FROM capitol c "
            "WHERE c.titol_serie = '" + titolSerie + "' "
            "AND c.numero_temporada = " + to_string(numTemporada) + " "
            "AND c.numero = " + to_string(num) + ";";
        sql::ResultSet* p = bd.execQuery(sqlp);
        if (p->next() and !p->getBoolean("estrenada")) {
            delete p;
            throw std::runtime_error("El capitol " + to_string(num) + " de la temporada  " + to_string(numTemporada) + " de la serie " + titolSerie + " aun no s'ha estrenat.");
        }
        std::string sql =
            "INSERT INTO visualitzacio_capitol (sobrenom_usuari, titol_serie, num_temporada, num_capitol, data, num_visualitzacions) "
            "SELECT '" + sobrenom + "', '" + titolSerie + "', " + to_string(numTemporada) + ", " + to_string(num) + ", NOW(), 1 "
            "WHERE EXISTS (SELECT 1 FROM usuari WHERE sobrenom = '" + sobrenom + "') "
            "AND EXISTS (SELECT 1 FROM capitol WHERE titol_serie = '" + titolSerie + "') "
            "AND EXISTS (SELECT 1 FROM capitol WHERE numero_temporada = " + to_string(numTemporada) + ") "
            "AND EXISTS (SELECT 1 FROM capitol WHERE numero = " + to_string(num) + ") "
            "ON DUPLICATE KEY UPDATE num_visualitzacions = num_visualitzacions + 1, data = NOW();";
        bd.exec(sql);
        string sqlFecha =
            "SELECT DATE_FORMAT(v.data, '%d/%m/%Y %H:%i') AS data_formateada "
            "FROM visualitzacio_capitol v "
            "WHERE v.titol_serie = '" + titolSerie + "' "
            "AND v.sobrenom_usuari = '" + sobrenom + "' "
            "AND v.num_temporada = " + to_string(numTemporada) + " "
            "AND v.num_capitol = " + to_string(num) + ";";

        string fecha = " ";
        sql::ResultSet* res = bd.execQuery(sqlFecha);
        if (res->next()) {
            fecha = res->getString("data_formateada");
        }
        delete res;
        return fecha;


    }
    string obteSobrenom() {
        return sobrenom;
    }

    string obteTitolSerie() {
        return titolSerie;
    }

    int obteTemporada() {
        return numTemporada;
    }

};
