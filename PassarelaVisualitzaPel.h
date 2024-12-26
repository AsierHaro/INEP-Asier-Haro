#pragma once
#include "ConnexioBD.h"
class PassarelaVisualitzaPel
{
	private:
		string sobrenom;
		string Nom;
		string Data;
		string Descripcio;
		int Duracio;
		int Visualitzacio;
		int Edat;
		string Relacionades;


	public:
		PassarelaVisualitzaPel() {
			sobrenom;
			Nom = "";
			Descripcio = "";
			Edat = 0;
			Data = "";
			Duracio = 0;
			Visualitzacio = 0;
			Relacionades = "";
		}


		PassarelaVisualitzaPel(string NomP, string sobrenomP, string DescripcioP, int EdatP, string DataP, int DuracioP, int VisualitzacioP, string RelacionadesP) {
			Nom = NomP;
			sobrenom = sobrenomP;
			Descripcio = DescripcioP;
			Edat = EdatP;
			Data = DataP;
			Duracio = DuracioP;
			Visualitzacio = VisualitzacioP;
			Relacionades = RelacionadesP;
		}

		void insereix() const {
			ConnexioBD bd;
			std::string query = "INSERT INTO Pel (Descripcio,sobrenom, Nom, Data,Relacionades,Duracio,Visualitzacio,Edat) VALUES ('"+
				Nom + "', '" +
				sobrenom + "', '" +
				Descripcio + "', " +
				std::to_string(Edat) + ", STR_TO_DATE('" +
				Data + "', '%d/%m/%Y'), " +
				std::to_string(Duracio) + ", " +
				std::to_string(Visualitzacio) + ", '" +
				Relacionades + "')";
			bd.exec(query);
		}

		void esborra() const {
			ConnexioBD bd;
			string sql = "DELETE FROM Pel WHERE sobrenom = '" + sobrenom + "'";
			bd.exec(sql);
		}

		void modifica() {
			ConnexioBD bd;
			string sql = "UPDATE Pel SET "
				"Nom = '" + Nom + "', "
				"Descripcio = '" + Descripcio + "', "
				"Edat = " + std::to_string(Edat) + ", "
				"Data = STR_TO_DATE('" + Data + "', '%d/%m/%Y'), "
				"Duracio = " + std::to_string(Duracio) + ", "
				"Visualitzacio = " + std::to_string(Visualitzacio) + ", "
				"Relacionades = '" + Relacionades + "' "
				"WHERE sobrenom = '" + sobrenom + "';";
			bd.exec(sql);
		}

		string obteSobrenom() {
			return sobrenom;
		}

		string obteNom() {
			return Nom;
		}

		string obteDescripcio() {
			return Descripcio;
		}
		int obteEdat() {
			return Edat;
		}

		string obteData() {
			return Data;
		}

		int obteDuracio() {
			return Duracio;
		}
		int obteVisualitzacio() {
			return Visualitzacio;
		}

		string obteRelacioanades() {
			return Relacionades;
		}
};

