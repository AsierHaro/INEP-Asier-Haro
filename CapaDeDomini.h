#pragma once
#include "PassarelaUsuari.h"
#include "DTOUsuari.h"
#include "CercadoraUsuari.h"
class CapaDeDomini
{
    private:
        CapaDeDomini();
	public:

        static CapaDeDomini& getInstance() {
            static CapaDeDomini instance;
            return instance;
        }

        DTOUsuari consultaUsuari(std::string sobrenom) {
            CercadoraUsuari cerca;
            PassarelaUsuari usu = cerca.cercaPerSobrenom(sobrenom);
            return DTOUsuari(usu);
        }

        void registrarUsuari(string sobrenom, string nom, string correuElectronic)
        {
            PassarelaUsuari usuari(sobrenom, nom, correuElectronic);
            usuari.insereix();
        }

        void modificar_usuari(string sobrenom, string nom, string correuElectronic)
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

