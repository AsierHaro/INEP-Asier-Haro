#pragma once
#include "PassarelaUsuari.h"
class CapaDeDomini
{
    private:
        CapaDeDomini();
	public:

        static CapaDeDomini& getInstance() {
            static CapaDeDomini instance;
            return instance;
        }

        void consulta_usuari(string sobrenom_usuari)
        {
            try {
                ConnexioBD bd;
                string sql = "SELECT * FROM usuari WHERE sobrenom = 'sobrenom_usuari'";
                sql::ResultSet* res = bd.execQuery(sql);
                while (res->next()) {
                    cout << "Sobrenom: " << res->getString("sobrenom") << endl;
                    cout << "Nom: " << res->getString("nom") << endl;
                    cout << "Correu: " << res->getString("correu_electronic") << endl;
                }
                bd.getCon()->close();
            }
            catch (sql::SQLException& e) {
                std::cerr << "SQL Error: " << e.what() << std::endl;
            }
        }

        void registrarUsuari(string sobrenom, string usuari, string correu_electronic)
        {
            try {
                ConnexioBD bd;
                string sql = "INSERT INTO usuari (sobrenom,usuari,correu_electronic) VALUES (asierhr, 'Asier Haro', asier.haro@estudiantat.upc.edu)";
                bd.exec(sql);
                bd.getCon()->close();
            }
            catch (sql::SQLException& e) {
                std::cerr << "SQL Error: " << e.what() << std::endl;
            }
        }

        void modificar_usuari()
        {
            try {
                ConnexioBD bd;
                string sql = "UPDATE usuari SET name = 'Un altre nom', correu_electronic = 'un altre correu' WHERE sobrenom = 'sobrenom_usuari'";
                bd.exec(sql);
                bd.getCon()->close();
            }
            catch (sql::SQLException& e) {
                std::cerr << "SQL Error: " << e.what() << std::endl;
            }
        }
};

