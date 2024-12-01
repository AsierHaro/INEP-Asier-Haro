#pragma once
#include "PassarelaUsuari.h"
#include "ConnexioBD.h"
class CercadoraUsuari
{
	public:
		PassarelaUsuari cercaPerSobrenom(std::string sobrenomU) {
			PassarelaUsuari u;
			ConnexioBD bd;
			string sql = "SELECT * FROM Usuari WHERE sobrenom = '" +
				sobrenomU + "'";
			sql::ResultSet* res = bd.execQuery(sql);
			if (!res->next()) {
				throw runtime_error("Usuari no existeix");
			}
			else {
				u.posaSobrenom(res->getString("sobrenom"));
				u.posaNom(res->getString("nom"));
				u.posaCorreuElectronic(res->getString("correu_electronic"));
				delete res;
			}
			return u;
		}

};

