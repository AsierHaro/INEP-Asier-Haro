#pragma once
#include "PassarelaUsuari.h"
#include "DTOUsuari.h"
#include "CercadoraUsuari.h"
#include "Petitflix.h"
class CapaDeDomini
{
    private:
        CapaDeDomini() {
        }
	public:

        static CapaDeDomini& getInstance() {
            static CapaDeDomini instance;
            return instance;
        }

        DTOUsuari consultaUsuari() {
            Petitflix& petitflix = Petitflix::getInstance();
            PassarelaUsuari usu = petitflix.obteUsuari();
            return DTOUsuari(usu);
        }

        void registrarUsuari(string sobrenom, string nom, string correuElectronic, string contrasenyaU, string modalitat_subscripcioU)
        {
            PassarelaUsuari usuari(sobrenom, nom, correuElectronic, contrasenyaU, modalitat_subscripcioU);
            usuari.insereix();
        }

        void modificar_usuari(string sobrenom, string nom, string correuElectronic, string contrasenyaU, string modalitat_subscripcioU)
        {
            PassarelaUsuari usuari(sobrenom, nom, correuElectronic, contrasenyaU, modalitat_subscripcioU);
            usuari.modifica();
        }

        void esborrar_usuari(string sobrenom) {
            CercadoraUsuari cerca;
            PassarelaUsuari usuari = cerca.cercaPerSobrenom(sobrenom);
            usuari.esborra();
        }

        void iniciarSesio(string sobrenomU, string contrasenyaU) {
            CercadoraUsuari cerca;
            PassarelaUsuari usu = cerca.cercaPerSobrenom(sobrenomU);
            string contrasenya = usu.obteContrasenya();
            if (contrasenya == contrasenyaU) {
                Petitflix& petitflix = Petitflix::getInstance();
                petitflix.iniciaSesio(usu);
            }
        }

        void tancarSesio() {
            Petitflix& petitflix = Petitflix::getInstance();
            petitflix.tancaSesio();
        }
};

