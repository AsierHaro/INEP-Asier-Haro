#pragma once
#include <stdexcept>
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

        void registrarUsuari(string sobrenom, string nom, string correuElectronic, string contrasenyaU, int modalitat_subscripcioU, string dataU)
        {
            PassarelaUsuari usuari(sobrenom, nom, correuElectronic, contrasenyaU, modalitat_subscripcioU, dataU);
            usuari.insereix();
        }

        void modificar_usuari(string sobrenom, string nom, string correuElectronic, string contrasenyaU, int modalitat_subscripcioU, string dataU)
        {
            PassarelaUsuari usuari(sobrenom, nom, correuElectronic, contrasenyaU, modalitat_subscripcioU, dataU);
            usuari.modifica();
        }

        void esborrar_usuari(string contrasenya) {
            Petitflix& petitflix = Petitflix::getInstance();
            PassarelaUsuari usu = petitflix.obteUsuari();
            if (usu.obteContrasenya() == contrasenya) {
                usu.esborra();
            }
        }

        void iniciarSesio(string sobrenomU, string contrasenyaU) {
            CercadoraUsuari cerca;
            PassarelaUsuari usu = cerca.cercaPerSobrenom(sobrenomU);
            string contrasenya = usu.obteContrasenya();
            if (contrasenya == contrasenyaU) {
                Petitflix& petitflix = Petitflix::getInstance();
                petitflix.iniciaSesio(usu);
            }else{
                throw std::runtime_error("Contrasenya incorrecta.");
            }
        }

        void tancarSesio() {
            Petitflix& petitflix = Petitflix::getInstance();
            petitflix.tancaSesio();
        }
};

