#pragma once
#include "PassarelaUsuari.h"
#include "ConnexioBD.h"
class CercadoraUsuari
{
public:
	PassarelaUsuari cercaPerSobrenom(std::string sobrenomU) {
		PassarelaUsuari u;
		ConnexioBD bd;
		string sql = "SELECT u.sobrenom, u.nom, u.contrasenya, u.correu_electronic, "
			"DATE_FORMAT(u.data_naixament, '%d/%m/%Y') AS data_formateada, "
			"TIMESTAMPDIFF(YEAR, u.data_naixament, CURRENT_DATE) AS edat, "
			"m.nom AS nom_subscripcio "
			"FROM usuari u "
			"JOIN modalitat_subscripcio m ON u.subscripcio = m.nom "
			"WHERE u.sobrenom = '" + sobrenomU + "'";
		sql::ResultSet* res = bd.execQuery(sql);
		if (!res->next()) {
			throw runtime_error("Hi ha hagut un error amb el sobrenom o la contrasenya");
		}
		else {
			u.posaSobrenom(res->getString("sobrenom"));
			u.posaNom(res->getString("nom"));
			u.posaCorreuElectronic(res->getString("correu_electronic"));
			u.posaModalitatSubscripcio((res->getString("nom_subscripcio")));
			u.posaContrasenya(res->getString("contrasenya"));
			u.posaData(res->getString("data_formateada"));
			u.posaEdat(res->getInt("edat"));
			delete res;
		}
		return u;
	}

};
