#pragma once
#include "ConnexioBD.h"
class PassarelaUsuari
{
	private:
		string sobrenom;
		string nom;
		string correu_electronic;
		string contrasenya;
		string modalitatSubscripcio;
		string data;

	public:

		PassarelaUsuari() {
			sobrenom = " ";
			nom = " ";
			correu_electronic = " ";
			contrasenya = " ";
			modalitatSubscripcio = " ";
			data = " ";
		}
		

		PassarelaUsuari(string sobrenomU, string nomU, string correuElectronicU, string contrasenyaU, string num_subscripcioU, string dataU) {
			sobrenom = sobrenomU; 
			nom = nomU;
			correu_electronic = correuElectronicU;
			contrasenya = contrasenyaU;
			modalitatSubscripcio = num_subscripcioU;
			data = dataU;
		}

		void insereix() const{
			ConnexioBD bd; 
			std::string query = "INSERT INTO usuari (sobrenom, nom, correu_electronic, contrasenya, subscripcio, data_naixament) VALUES ('" 
				+ sobrenom + "', '"
				+ nom + "', '"
				+ correu_electronic + "', '"
				+ contrasenya + "',"
				+ modalitatSubscripcio + ", STR_TO_DATE('"
				+ data + "', '%d/%m/%Y'))";
			bd.exec(query);
		}

		void esborra() const{
			ConnexioBD bd;
			string sql = "DELETE FROM usuari WHERE sobrenom = '" + sobrenom + "'";
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

		string obteData() {
			return data;
		}

		string obteSubscripcio() {
			return modalitatSubscripcio;
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
			modalitatSubscripcio = modalitat_subscripcioU;
		}

		void posaContrasenya(string contrasenyaU) {
			contrasenya = contrasenyaU;
		}

		void posaData(string dataU) {
			data = dataU;
		}
};

