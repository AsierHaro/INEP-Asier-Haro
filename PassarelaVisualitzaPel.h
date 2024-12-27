#pragma once
#include "ConnexioBD.h"
class PassarelaVisualitzaPel
{
	private:
		string sobrenom;
		string titolPel;
		string data;
		int numVisualitzacions;


	public:
		PassarelaVisualitzaPel() {
			sobrenom = "";
			titolPel= "";
			data = "";
			numVisualitzacions = 0;
		}


		PassarelaVisualitzaPel(string NomP, string sobrenomP,string DataP, int VisualitzacioP) {
			titolPel = NomP;
			sobrenom = sobrenomP;
			data = DataP;
			numVisualitzacions = VisualitzacioP;
		}

		void insereix() const {
			ConnexioBD bd;
			std::string query = "INSERT INTO Pel (sobrenom, titolPel, data,numVisualitzacions) VALUES ('" +
				titolPel + "', '" +
				sobrenom + "', '" +
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
				"data = STR_TO_DATE('" + data + "', '%d/%m/%Y'), "
				"numVisualitzacions = " + std::to_string(numVisualitzacions) + ", "
				"WHERE sobrenom = '" + sobrenom + "';";
			bd.exec(sql);
		}

		string obteSobrenom() {
			return sobrenom;
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
};

