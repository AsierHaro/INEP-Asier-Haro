#pragma once
#include "ConnexioBD.h"
class PassarelaVisualitzaPel
{
	private:
		string sobrenom;
		string titolPel;
		string descripcio;
		string data;
		int numVisualitzacions;


	public:
		PassarelaVisualitzaPel() {
			sobrenom = "";
			titolPel= "";
			descripcio = "";
			data = "";
			numVisualitzacions = 0;
		}


		/*PassarelaVisualitzaPel(string NomP, string sobrenomP, string DataP, string descripcioP, int VisualitzacioP) {
			titolPel = NomP;
			sobrenom = sobrenomP;
			descripcio = descripcioP;
			data = DataP;
			numVisualitzacions = VisualitzacioP;
		}

		void insereix() const {
			ConnexioBD bd;
			std::string query = "INSERT INTO Pel (sobrenom, titolPel, data,numVisualitzacions) VALUES ('" +
				titolPel + "', '" +
				sobrenom + "', '" +
				descripcio +"', '" +
				data + "', '%d/%m/%Y'), " +
				std::to_string(numVisualitzacions) + ")";
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
				"titolPel = '" + titolPel + "', "
				"descripcio = '" + descripcio + " ', "
				"data = STR_TO_DATE('" + data + "', '%d/%m/%Y'), "
				"numVisualitzacions = " + std::to_string(numVisualitzacions) + ", "
				"WHERE sobrenom = '" + sobrenom + "';";
			bd.exec(sql);
		}

		string obteSobrenom() {
			return sobrenom;
		}

		string obteDescripcio() {
			return descripcio;
		}

		string obteTitolPel() {
			return titolPel;
		}

		string obteData() {
			return data;
		}

		int obtenNumVisualitzacions() {
			return numVisualitzacions;
		}
		*/
};

