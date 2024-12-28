#pragma once
#include "ConnexioBD.h"
#include "DTOSerie.h"
#include <vector>

class PassarelaVisualitzaSerie {
private:
    string sobrenom;
    string titolSerie;
    int numTemporades;

public:
    PassarelaVisualitzaSerie() {
        sobrenom = "";
        titolSerie = "";
        numTemporades = 0;
    }

    PassarelaVisualitzaSerie(string titol, string sobrenomSerie, int temporades) {
        titolSerie = titol;
        sobrenom = sobrenomSerie;
        numTemporades = temporades;
    }

    void insereix() const {
        ConnexioBD bd;
        string query = "INSERT INTO Serie (titolSerie, sobrenom, numTemporades) VALUES ('" +
            titolSerie + "', '" +
            sobrenom + "', " +
            to_string(numTemporades) + ")";
        bd.exec(query);
    }

    void esborra() const {
        ConnexioBD bd;
        string sql = "DELETE FROM Serie WHERE sobrenom = '" + sobrenom + "'";
        bd.exec(sql);
    }

    void modifica() {
        ConnexioBD bd;
        string sql = "UPDATE Serie SET "
            "titolSerie = '" + titolSerie + "', "
            "numTemporades = " + to_string(numTemporades) +
            " WHERE sobrenom = '" + sobrenom + "'";
        bd.exec(sql);
    }

   
    bool registraVisualitzacioCapitol(const string& sobrenomSerie, int numeroTemporada, int numeroCapitol) {
        ConnexioBD bd;
        string query = "UPDATE Capitol SET dataVisualitzacio = CURRENT_DATE "
            "WHERE sobrenomSerie = '" + sobrenomSerie +
            "' AND numeroTemporada = " + to_string(numeroTemporada) +
            " AND numero = " + to_string(numeroCapitol);
        bd.exec(query);
        return true;
    }
    string obteSobrenom() {
        return sobrenom;
    }

    string obteTitolSerie() {
        return titolSerie;
    }

    int obteTemporada() {
        return numTemporades;
    }
    
};
