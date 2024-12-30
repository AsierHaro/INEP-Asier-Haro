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
	int edat;

public:

	PassarelaUsuari() {
		sobrenom = " ";
		nom = " ";
		correu_electronic = " ";
		contrasenya = " ";
		modalitatSubscripcio = " ";
		data = " ";
		edat = 0;
	}


	PassarelaUsuari(string sobrenomU, string nomU, string correuElectronicU, string contrasenyaU, string num_subscripcioU, string dataU) {
		sobrenom = sobrenomU;
		nom = nomU;
		correu_electronic = correuElectronicU;
		contrasenya = contrasenyaU;
		modalitatSubscripcio = num_subscripcioU;
		data = dataU;
		edat = 0;
	}

	void insereix() const {
		ConnexioBD bd;
		std::string query = "INSERT INTO usuari (sobrenom, nom, correu_electronic, contrasenya, subscripcio, data_naixament) VALUES ('"
			+ sobrenom + "', '"
			+ nom + "', '"
			+ correu_electronic + "', '"
			+ contrasenya + "', '"
			+ modalitatSubscripcio + "', STR_TO_DATE('"
			+ data + "', '%d/%m/%Y'))";
		bd.exec(query);
	}

	void esborra() const {
		ConnexioBD bd;
		string sql = "DELETE FROM usuari WHERE sobrenom = '" + sobrenom + "'";
		bd.exec(sql);
	}

	void modifica() {
		ConnexioBD bd;
		string sql = "UPDATE usuari SET "
			"nom = '" + nom + "', "
			"correu_electronic = '" + correu_electronic + "', "
			"contrasenya = '" + contrasenya + "', "
			"subscripcio = '" + modalitatSubscripcio + "', "
			"data_naixament = STR_TO_DATE('" + data + "', '%d/%m/%Y') "
			"WHERE sobrenom = '" + sobrenom + "';";
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
	int obteEdat() {
		return edat;
	}
	void posaSobrenom(string sobrenomU) {
		if (sobrenomU != "") sobrenom = sobrenomU;
	}

	void posaNom(string nomU) {
		if (nomU != "") nom = nomU;
	}

	void posaCorreuElectronic(string correuElectronicU) {
		if (correuElectronicU != "") correu_electronic = correuElectronicU;
	}

	void posaModalitatSubscripcio(string modalitat_subscripcioU) {
		if (modalitat_subscripcioU != "") modalitatSubscripcio = modalitat_subscripcioU;
	}

	void posaContrasenya(string contrasenyaU) {
		if (contrasenyaU != "") contrasenya = contrasenyaU;
	}

	void posaData(string dataU) {
		if (dataU != "") data = dataU;
	}
	void posaEdat(int edatU) {
		if (edatU > 0) edat = edatU;
	}
};
