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
            PassarelaUsuari usuari(sobrenom, nom, correuElectronic);
            usuari.modifica();
        }

        void esborrar_usuari(string sobrenom) {
            CercadoraUsuari cerca;
            PassarelaUsuari usuari = cerca.cercaPerSobrenom(sobrenom);
            usuari.esborra();
        }
};

