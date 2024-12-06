#pragma once
#include <iostream>
#include <string>
#include "CapaDeDomini.h"
using namespace std;
class CapaDePresentacio
{
	private:
		CapaDePresentacio(){
		}
	public:

		static CapaDePresentacio& getInstance() {
			static CapaDePresentacio instance;
			return instance;
		}

		void registrarUsuari() {
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

		void consultaUsuari() {
			string nomU;
			std::cout << "Nom usuari:";
			std::cin >> nomU;
			try {
				CapaDeDomini& domini = CapaDeDomini::getInstance();
				DTOUsuari usu = domini.consultaUsuari(nomU);
				std::cout << "Informació usuari: " << usu.obteNom();
				std::cout << std::endl;
				std::cout << "Nom: " << usu.obteNom() << std::endl;
				std::cout << "Correu: " << usu.obteCorreu() << std::endl;
			}
			catch (const exception& e) {
				std::cout << "Error: " << e.what() << endl;
			}
		}

		void modificaUsuari() {
			std::string sobrenomU, nomU, correuU;
			std::cout << "** Modificar usuari **" << std::endl;
			std::cout << "Sobrenom: ";
			std::cin >> sobrenomU;
			std::cout << "Nom: ";
			std::cin >> nomU;
			std::cout << "Correu electrònic: ";
			std::cin >> correuU;
			std::cout << "Nom usuari:";
			std::cin >> nomU;
			try {
				CapaDeDomini& domini = CapaDeDomini::getInstance();
				domini.modificar_usuari(sobrenomU,nomU,correuU);
			}
			catch (const exception& e) {
				std::cout << "Error: " << e.what() << endl;
			}
		}

		void esborraUsuari() {
			string nomU;
			std::cout << "Nom usuari:";
			std::cin >> nomU;
			try {
				CapaDeDomini& domini = CapaDeDomini::getInstance();
				domini.esborrar_usuari(nomU);
			}
			catch (const exception& e) {
				std::cout << "Error: " << e.what() << endl;
			}
		}

};

