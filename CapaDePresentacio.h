#pragma once
#include <iostream>
#include <string>
#include <locale>
#include "CapaDeDomini.h"
using namespace std;
class CapaDePresentacio
{
private:
	CapaDePresentacio() {
	}
public:

	static CapaDePresentacio& getInstance() {
		static CapaDePresentacio instance;
		return instance;
	}

	void registrarUsuari() {
		std::string sobrenomU, nomU, correuU, contrasenya, dataU;
		int modalitat_subscripcio;
		std::cout << "** Registra usuari **" << std::endl;
		std::cout << "Nom: ";
		std::cin >> nomU;
		std::cout << "Sobrenom: ";
		std::cin >> sobrenomU;
		std::cout << "Contrasenya: ";
		std::cin >> contrasenya;
		std::cout << "Correu electronic: ";
		std::cin >> correuU;
		std::cout << "Data naixament (DD/MM/AAAA): ";
		std::cin >> dataU;
		std::cout << "Modalitats de subscripcio disponibles " << endl;
		std::cout << " > 1. Completa " << endl;
		std::cout << " > 2. Cinefil " << endl;
		std::cout << " > 3. Infantil " << endl;
		std::cout << "Escull modalitat: ";
		std::cin >> modalitat_subscripcio;
		CapaDeDomini& domini = CapaDeDomini::getInstance();
		try {
			domini.registrarUsuari(sobrenomU, nomU, correuU, contrasenya, modalitat_subscripcio, dataU);
			std::cout << "Usuari registrat correctament!" << std::endl;
		}
		catch (const std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
	}

	void consultaUsuari() {
		std::cout << "** Consulta usuari **" << std::endl;
		try {
			CapaDeDomini& domini = CapaDeDomini::getInstance();
			DTOUsuari usu = domini.consultaUsuari();
			std::cout << "Nom complet: " << usu.obteNom() << endl;
			std::cout << "Sobrenom: " << usu.obteSobrenom() << std::endl;
			std::cout << "Correu electronic: " << usu.obteCorreu() << std::endl;
			std::cout << "Data naixament (DD/MM/AAAA): " << usu.obteData() << std::endl;
			std::cout << "Modalitat subscripcio: " << usu.obteSubscripcio() << std::endl;

		}
		catch (const exception& e) {
			std::cout << "Error: " << e.what() << endl;
		}
	}

	void modificaUsuari() {
		consultaUsuari();
		cin.ignore();
		cin.get();
		system("cls");
		std::string sobrenomU, nomU, correuU, contrasenya, dataU;
		int modalitat_subscripcio;
		std::cout << "Omplir la informacio que es vol modificar ..." << std::endl;
		std::cout << "Nom: ";
		std::cin >> nomU;
		std::cout << "Contrasenya: ";
		std::cin >> contrasenya;
		std::cout << "Correu electronic: ";
		std::cin >> correuU;
		std::cout << "Data naixament (DD/MM/AAAA): ";
		std::cin >> dataU;
		std::cout << "Modalitats de subscripcio disponibles " << endl;
		std::cout << " > 1. Completa " << endl;
		std::cout << " > 2. Cinefil " << endl;
		std::cout << " > 3. Infantil " << endl;
		std::cout << "Escull modalitat: ";
		std::cin >> modalitat_subscripcio;
		try {
			CapaDeDomini& domini = CapaDeDomini::getInstance();
			domini.modificarUsuari(nomU, correuU, contrasenya, modalitat_subscripcio, dataU);
		}
		catch (const exception& e) {
			std::cout << "Error: " << e.what() << endl;
		}
	}

	void esborraUsuari() {
		string contrasenya;
		std::cout << "** Registra usuari **" << std::endl;
		std::cout << "Per confirmar l'esborrat, s'ha d'entrar la contrasenya ..." << std::endl;
		std::cout << "Contrasenya: " << std::endl;
		std::cin >> contrasenya;
		try {
			CapaDeDomini& domini = CapaDeDomini::getInstance();
			domini.esborrar_usuari(contrasenya);
		}
		catch (const exception& e) {
			std::cout << "Error: " << e.what() << endl;
		}
	}

	void iniciarSesio() {
		string sobrenomU, contrasenyaU;
		bool iniciat = false;
		while (!iniciat) {
			cout << "sobrenom: ";
			cin >> sobrenomU;
			cout << "contrasenya: ";
			cin >> contrasenyaU;
			try {
				CapaDeDomini& domini = CapaDeDomini::getInstance();
				domini.iniciarSesio(sobrenomU, contrasenyaU);
				iniciat = true;
			}
			catch (const exception& e) {
				std::cout << "Error: " << e.what() << endl;
			}
			catch (const std::runtime_error& e) {
				std::cout << "Error: " << e.what() << endl;
			}
		}
		cout << "Sessio iniciada correctamente." << endl;
	}


	void tancarSesio() {
		string tancar;
		cout << "Vols tancar la sessio (S/N): ";
		cin >> tancar;
		if (tancar == "S") {
			try {
				CapaDeDomini& domini = CapaDeDomini::getInstance();
				domini.tancarSesio();
			}
			catch (const exception& e) {
				std::cout << "Error: " << e.what() << endl;
			}
		}
	}

};