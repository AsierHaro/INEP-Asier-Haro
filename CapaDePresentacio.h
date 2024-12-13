#pragma once
#include <iostream>
#include <string>
#include <locale>
#include "TxIniciSessio.h"
#include "TxTancaSessio.h"
#include "TxRegistraUsuari.h"
#include "TxConsultarUsuari.h"
#include "CtrlModificaUsuari.h"
#include "TxEsborraUsuari.h"
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
		try {
			TxRegistraUsuari tx(sobrenomU, nomU, correuU, contrasenya, dataU, modalitat_subscripcio);
			tx.executar();
			std::cout << "Usuari registrat correctament!" << std::endl;
		}
		catch (const std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
	}

	void consultaUsuari() {
		std::cout << "** Consulta usuari **" << std::endl;
		try {
			TxConsultarUsuari tx;
			tx.executar();
			DTOUsuari usu = tx.obteResultat();
			cout << usu << endl;
			cin.ignore();
			cin.get();
			system("cls");
		}
		catch (const exception& e) {
			std::cout << "Error: " << e.what() << endl;
		}
	}

	void modificaUsuari() {
		std::cout << "** Modifica usuari **" << std::endl;
		CtrlModificaUsuari ctrl;
		DTOUsuari usu = ctrl.consultaUsuari();
		cout << usu << endl;
		cin.ignore();
		cin.get();
		system("cls");
		string sobrenomU, nomU, correuU, contrasenya, dataU, modalitat_subscripcio;
		std::cout << "Omplir la informacio que es vol modificar ..." << std::endl;
		std::cout << "Nom: ";
		std::getline(std::cin, nomU);
		std::cout << "Contrasenya: ";
		std::getline(std::cin, contrasenya);
		std::cout << "Correu electronic: ";
		std::getline(std::cin, correuU);
		std::cout << "Data naixament (DD/MM/AAAA): ";
		std::getline(std::cin, dataU);
		std::cout << "Modalitats de subscripcio disponibles " << endl;
		std::cout << " > 1. Completa " << endl;
		std::cout << " > 2. Cinefil " << endl;
		std::cout << " > 3. Infantil " << endl;
		std::cout << "Escull modalitat: ";
		std::getline(std::cin, modalitat_subscripcio);
		try {
			ctrl.modificaUsuari(nomU, contrasenya, correuU, dataU, modalitat_subscripcio);
			system("cls");
			usu = ctrl.consultaUsuari();
			cout << usu << endl;
			cin.get();
			system("cls");
		}
		catch (const exception& e) {
			std::cout << "Error: " << e.what() << endl;
		}
	}

	void esborraUsuari() {
		string contrasenya;
		std::cout << "** Esborrar usuari **" << std::endl;
		std::cout << "Per confirmar l'esborrat, s'ha d'entrar la contrasenya ..." << std::endl;
		std::cout << "Contrasenya: ";
		std::cin >> contrasenya;
		system("cls");
		try {
			TxEsborraUsuari tx(contrasenya);
			tx.executar();
			cout << "Usuari esborrat correctament" << endl;
			TxTancaSessio ty;
			ty.executar();
		}
		catch (const exception& e) {
			std::cout << "Error: " << e.what() << endl;
		}
		catch (const std::runtime_error& e) {
			std::cout << "Error: " << e.what() << endl;
		}
	}

	void iniciarSesio() {
		std::cout << "** Inici sessio **" << std::endl;
		string sobrenomU, contrasenyaU;
		bool iniciat = false;
		while (!iniciat) {
			cout << "sobrenom: ";
			cin >> sobrenomU;
			cout << "contrasenya: ";
			cin >> contrasenyaU;
			try {
				TxIniciSessio tx(sobrenomU, contrasenyaU);
				tx.executar();
				iniciat = true;
			}
			catch (const exception& e) {
				std::cout << "Error: " << e.what() << endl;
			}
			catch (const std::runtime_error& e) {
				std::cout << "Error: " << e.what() << endl;
			}
		}
		cout << "Sessio iniciada correctament." << endl;
	}


	void tancarSesio() {
		string tancar;
		std::cout << "** Tancar sessio **" << std::endl;
		cout << "Vols tancar la sessio (S/N): ";
		cin >> tancar;
		if (tancar == "S") {
			try {
				TxTancaSessio tx;
				tx.executar();
			}
			catch (const exception& e) {
				std::cout << "Error: " << e.what() << endl;
			}
		}
	}

};