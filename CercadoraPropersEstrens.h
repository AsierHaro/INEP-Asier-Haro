#pragma once
#include <string>
#include "PassarelaEstrenes.h"
#include "ConnexioBD.h"

class CercadoraPropersEstrens
{
public:
		
		vector<PassarelaEstrenes> cercaEstrens() {
			vector<PassarelaEstrenes> continguts;
			ConnexioBD bd;
			try {
				string sqlp = "SELECT  tipus,titol,calificacio,duracio,DATE_FORMAT(data, '%d/%m/%Y') AS data_estrena, 0 AS temporadas"
					"FROM pelicula "
					"UNION ALL"
					"SELECT tipus,titol,calificacio,0 AS duracio,DATE_FORMAT(data, '%d/%m/%Y') AS data_estrena, numero_temporada AS temporada"
					"FROM serie "
					"ORDER BY data_estrena ASC";
				sql::ResultSet* res = bd.execQuery(sqlp);
				while (res->next()) {
					PassarelaEstrenes p = PassarelaEstrenes(res->getString("data_estrena"), res->getString("tipus"), res->getString("titol"), res->getString("calificacio"), res->getInt("duracio"), res->getInt("temporada"));
					continguts.push_back(p);
				}
				delete res;
			}
			catch (sql::SQLException& e) {
				cerr << "Error en la consulta SQL: " << e.what() << endl;
			}
			return continguts;

		}
};