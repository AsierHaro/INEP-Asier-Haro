#pragma once
#include "ConnexioBD.h"
class PassarelaUsuari
{
	private:
		string sobrenom;
		string nom;
		string correuElectronic;

	public:

		PassarelaUsuari() {
		}

		PassarelaUsuari(string sobrenomU, string nomU, string correuElectronicU) {
			sobrenom = sobrenomU; 
			nom = nomU;
			correuElectronic = correuElectronicU;
		}

		void insereix() {
			ConnexioBD bd;
			std::string query = "INSERT INTO usuari (sobrenom,usuari,correu_electronic) VALUES (sobrenom, nom, correuElectronic)";
			bd.execQuery(query);
		}

		void esborra() {
			ConnexioBD bd;
			string sql = "DELETE FROM usuari WHERE sobrenom = 'sobrenom";
			bd.exec(sql);
		}

		void modifica() {
			ConnexioBD bd;
			string sql = "UPDATE usuari SET name = 'Un altre nom', correu_electronic = 'un altre correu' WHERE sobrenom = 'sobrenom_usuari'";
			bd.exec(sql);
		}

		string obteSobrenom() {
			return sobrenom;
		}

		string obteNom() {
			return nom;
		}

		string obteCorreuElectronic() {
			return nom;
		}

		void posaSobrenom(string sobrenomU) {
			sobrenom = sobrenomU;
		}

		void posaNom(string nomU) {
			nom = nomU;
		}

		void posaCorreuElectronic(string correuElectronicU) {
			correuElectronic = correuElectronicU;
		}
};

