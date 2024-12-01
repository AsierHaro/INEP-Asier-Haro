#pragma once
#include <iostream>
#include <string>
#include "CapaDeDomini.h"
using namespace std;
class CapaDePresentacio
{
	private:
		CapaDePresentacio();
	public:

		static CapaDePresentacio& getInstance() {
			static CapaDePresentacio instance;
			return instance;
		}

		void processarRegistreUsuari() {
			std::string sobrenomU, nomU, correuU;
			std::cout << "** Registra usuari **" << std::endl;
			std::cout << "Sobrenom: ";
			std::cin >> sobrenomU;
			std::cout << "Nom: ";
			std::cin >> nomU;
			std::cout << "Correu electrònic: ";
			std::cin >> correuU;
			CapaDeDomini& domini = CapaDeDomini::getInstance();
			try {
				domini.registrarUsuari(sobrenomU, nomU, correuU);
				std::cout << "Usuari registrat correctament!" << std::endl;
			}
			catch (const std::exception& e) {
				std::cout << "Error: << e.what() << std::endl";
			}
		}

		void processarConsultaUsuari() {
			std::cout << "Nom usuari:";
			std::cin >> nomU;
			try {
				DTOUsuari usu = cercaUsuari(nomU);
				std::cout << "Informació usuari: " << usu.obteNom();
				std::cout << std::endl;
				std::cout << "Nom: " << usu.obteNom() << std::endl;
				std::cout << "Correu: " << usu.obteCorreu() << std::endl;
			}
			catch (const exception& e) {
				std::out << "Error: " << e.what() << endl;
			}
		}


};

