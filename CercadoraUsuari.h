#pragma once
#include "PassarelaUsuari.h"
#include "ConnexioBD.h"
class CercadoraUsuari
{
	public:
		PassarelaUsuari cercaPerSobrenom(std::string sobrenomU) {
			PassarelaUsuari u;
			ConnexioBD bd;
			string sql = "SELECT * FROM usuari WHERE sobrenom = '" + sobrenomU + "'";
			sql::ResultSet* res = bd.execQuery(sql);
			if (!res->next()) {
				throw runtime_error("Usuari no existeix");
			}
			else {
				u.posaSobrenom(res->getString("sobrenom"));
				u.posaNom(res->getString("nom"));
				u.posaCorreuElectronic(res->getString("correu_electronic"));
				u.posaModalitatSubscripcio(stoi(res->getString("subscripcio")));
				u.posaContrasenya(res->getString("contrasenya"));
				delete res;
			}
			return u;
		}

};

