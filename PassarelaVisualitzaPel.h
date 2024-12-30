#pragma once
#include "ConnexioBD.h"
class PassarelaVisualitzaPel
{
private:
	string sobrenom;
	string titolPel;
	string descripcio;
	string data;
	string qualificacio;
	int numVisualitzacions;
	int duracio;


public:
	PassarelaVisualitzaPel() {
		sobrenom = "";
		titolPel = "";
		duracio = 0;
		descripcio = "";
		qualificacio = "";
		data = "";
		numVisualitzacions = 0;
	}


	PassarelaVisualitzaPel(string NomP, int duracioP, string sobrenomP, string DataP, string descripcioP, int VisualitzacioP, string qualificacioP) {
		titolPel = NomP;
		sobrenom = sobrenomP;
		descripcio = descripcioP;
		qualificacio = qualificacioP;
		duracio = duracioP;
		data = DataP;
		numVisualitzacions = VisualitzacioP;
	}

	string visualitza(string sobrenom, string titol) {
		ConnexioBD bd;
		std::string sql =
			"INSERT INTO visualitzacio_pelicula (sobrenom_usuari, titol_pelicula, data, num_visualitzacions) "
			"SELECT '" + sobrenom + "', '" + titol + "', NOW(), 1 "
			"WHERE EXISTS (SELECT 1 FROM usuari WHERE sobrenom = '" + sobrenom + "') "
			"AND EXISTS (SELECT 1 FROM pelicula WHERE titol = '" + titol + "') "
			"ON DUPLICATE KEY UPDATE num_visualitzacions = num_visualitzacions + 1, data = NOW();";
		bd.exec(sql);
		string sqlFecha = "SELECT DATE_FORMAT(v.data, '%d/%m/%Y %H:%i') AS data_formateada "
			"FROM visualitzacio_pelicula v "
			"WHERE v.titol_pelicula = '" + titol + "' "
			"AND v.sobrenom_usuari = '" + sobrenom + "'";
		string fecha = " ";
		sql::ResultSet* res = bd.execQuery(sqlFecha);
		if (res->next()) {
			fecha = res->getString("data_formateada");
		}
		delete res;
		return fecha;

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

	string obteQualificacio() {
		return qualificacio;
	}
	int obteDuracio() {
		return duracio;
	}

	int obtenNumVisualitzacions() {
		return numVisualitzacions;
	}
};


