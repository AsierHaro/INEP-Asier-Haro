#pragma once
#include "ConnexioBD.h"
class PassarelaVisualitzaPel
{
	private:
		string sobrenom;
		string titolPelicula;
		string data;
		int numVisualitzacions;

	public:
		PassarelaVisualitzaPel() {
			string Nom = "";
			string Descripcio = "";
			string Edat = "";
			string Data = "";
			string Duracio = " ";
			string Visualitzacio = " ";
			string Relacionades = " ";
		}


		PassarelaUsuari(string NomP, string DescripcioP, string EdatP, string DataP, string DuracioP, string VisualitzacioP, string RelacionadesP) {
			Nom = NomP;
			Descripcio = DescripcioP;
			Edat = EdatP;
			Data = DataP;
			Duracio = DuracioP;
			Visualitzacio = VisualitzacioP;
			Relacionades = RelacionadesP;
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
};

