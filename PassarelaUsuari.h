#pragma once
#include "ConnexioBD.h"
class PassarelaUsuari
{
	private:
		string sobrenom;
		string nom;
		string correu_electronic;
		string contrasenya;
		string modalitat_subscripcio;
		string data;

	public:

		PassarelaUsuari() {
		}

		PassarelaUsuari(string sobrenomU, string nomU, string correuElectronicU, string contrasenyaU, string modalitat_subscripcioU, string dataU) {
			sobrenom = sobrenomU; 
			nom = nomU;
			correu_electronic = correuElectronicU;
			contrasenya = contrasenyaU;
			modalitat_subscripcio = modalitat_subscripcioU;
			data = dataU;
		}

		void insereix() const{
			ConnexioBD bd; 
			std::string query = "INSERT INTO usuari (sobrenom, nom, correu_electronic, contrasenya, modalitat_subscripcio, data) VALUES ('" 
				+ sobrenom + "', '"
				+ nom + "', '"
				+ correu_electronic + "', '"
				+ contrasenya + "', '"
				+ modalitat_subscripcio + "')";
			bd.exec(query);
		}

		void esborra() const{
			ConnexioBD bd;
			string sql = "DELETE FROM Usuari WHERE Sobrenom = '" + sobrenom + "'";
			bd.exec(sql);
			cout << "Usuari correctament esborrat" << endl;
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
			return correu_electronic;
		}
		string obteContrasenya() {
			return contrasenya;
		}

		void posaSobrenom(string sobrenomU) {
			sobrenom = sobrenomU;
		}

		void posaNom(string nomU) {
			nom = nomU;
		}

		void posaCorreuElectronic(string correuElectronicU) {
			correu_electronic = correuElectronicU;
		}

		void posaModalitatSubscripcio(string modalitat_subscripcioU) {
			modalitat_subscripcio = modalitat_subscripcioU;
		}

		void posaContrasenya(string contrasenyaU) {
			contrasenya = contrasenyaU;
		}
};

