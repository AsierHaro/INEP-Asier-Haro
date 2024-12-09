#pragma once
#include "PassarelaUsuari.h"
#include "ConnexioBD.h"
class CercadoraUsuari
{
	public:
		PassarelaUsuari cercaPerSobrenom(std::string sobrenomU) {
			PassarelaUsuari u;
			ConnexioBD bd;
			string sql = "SELECT u.sobrenom, u.nom, u.contrasenya, u.correu_electronic, DATE_FORMAT(u.data_naixament, '%d/%m/%Y') AS data_formateada, "
            "m.subscripcio AS nom_subscripcio "
            "FROM usuari u "
            "JOIN modalitat_subscripcio m ON u.subscripcio = m.id "
			"WHERE u.sobrenom = '" + sobrenomU + "'";
			sql::ResultSet* res = bd.execQuery(sql);
			if (!res->next()) {
				throw runtime_error("Usuari no existeix");
			}
			else {
				u.posaSobrenom(res->getString("sobrenom"));
				u.posaNom(res->getString("nom"));
				u.posaCorreuElectronic(res->getString("correu_electronic"));
				u.posaModalitatSubscripcio((res->getString("nom_subscripcio")));
				u.posaContrasenya(res->getString("contrasenya"));
				u.posaData(res->getString("data_formateada"));
				delete res;
			}
			return u;
		}

};

