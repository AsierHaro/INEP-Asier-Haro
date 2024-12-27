#include <iostream>
#include <string>
#include <locale>
#include "TxIniciSessio.h"
#include "TxTancaSessio.h"
#include "TxRegistraUsuari.h"
#include "TxConsultarUsuari.h"
#include "CtrlModificaUsuari.h"
#include "TxEsborraUsuari.h"
#include "TxConsultaProperesEstrenes.h"

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

	bool sessioIniciada = false;

	void registrarUsuari() {
		std::string sobrenomU, nomU, correuU, contrasenya, dataU, modalitat_subscripcio;
		std::cout << "** Registra usuari **" << std::endl;
		std::cout << "Nom: ";
		cin.ignore();
		std::getline(cin, nomU);
		cout << "Sobrenom: ";
		cin >> sobrenomU;
		std::cout << "Contrasenya: ";
		cin >> contrasenya;
		std::cout << "Correu electronic: ";
		cin >> correuU;
		std::cout << "Data naixament (DD/MM/AAAA): ";
		cin >> dataU;
		std::cout << "Modalitats de subscripcio disponibles " << endl;
		std::cout << " > 1. Completa " << endl;
		std::cout << " > 2. Cinefil " << endl;
		std::cout << " > 3. Infantil " << endl;
		std::cout << "Escull modalitat: ";
		cin >> modalitat_subscripcio;
		system("cls");
		try {
			TxRegistraUsuari tx(sobrenomU, nomU, correuU, contrasenya, dataU, modalitat_subscripcio);
			tx.executar();
			std::cout << "Usuari registrat correctament!" << std::endl;
		}
		catch (sql::SQLException& e) {
			if (e.getErrorCode() == 1452) {
				cout << "Modalitat no existeix" << endl;
			}
			else if (e.getErrorCode() == 1062) {
				string errorMessage = e.what();
				if(errorMessage.find("sobrenom") != string::npos) cout << "Ja existeix un usuari amb aquest sobrenom" << endl;
				else if(errorMessage.find("correu_electronic") != string::npos) cout << "Ja existeix un usuari amb aquest correu electronic" << endl;
			}
		}
		cin.ignore();
		cin.get();
		system("cls");
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
		std::getline(cin, modalitat_subscripcio);
		try {
			ctrl.modificaUsuari(nomU, contrasenya, correuU, dataU, modalitat_subscripcio);
			system("cls");
			usu = ctrl.consultaUsuari();
			cout << usu << endl;
		}
		catch (sql::SQLException& e) {
			if (e.getErrorCode() == 1062) {
				cout << "El nou  correu ja existeix" << endl;
			}
		}
		cin.get();
		system("cls");
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
			sessioIniciada = false;
		}
		catch (const std::runtime_error& e) {
			std::cout << "Error: " << e.what() << endl;
		}
		cin.ignore();
		cin.get();
		system("cls");
	}

	void iniciSesio() {
		string sobrenomU, contrasenyaU;
		std::cout << "** Inici sessio **" << std::endl;
		cout << "sobrenom: ";
		cin >> sobrenomU;
		cout << "contrasenya: ";
		cin >> contrasenyaU;
		try {
			TxIniciSessio tx(sobrenomU, contrasenyaU);
			tx.executar();
			sessioIniciada = true;
		}
		catch (const std::runtime_error& e) {
			std::cout << "Error: " << e.what() << endl;
		}
	
		if (sessioIniciada) {
			system("cls");
			cout << "Sessio iniciada correctament." << endl;
		}
		cin.ignore();
		cin.get();
	}
	void tancarSesio() {
		string tancar;
		std::cout << "** Tancar sessio **" << std::endl;
		cout << "Vols tancar la sessio (S/N): ";
		cin >> tancar;
		if (tancar == "S") {
			TxTancaSessio tx;
			tx.executar();
			sessioIniciada = false;
		}
		system("cls");
	}

	void ConsultaProperesEstrenes() {
		std::cout << "** Properes estrenes **" << std::endl;
		std::cout << "Modalitat: " << std::endl << std::endl << std::endl;
		//TxConsultaProperesEstrenes tx;
	}

};