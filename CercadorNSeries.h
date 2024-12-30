#pragma once
#include "ConnexioBD.h"
#include "DTONserie.h"
class CercadorNSeries
{
public:
	CercadorNSeries() {

	}
	vector<DTONserie> cercaNovetats() {
		vector<DTONserie> continguts;
		ConnexioBD bd;
		string sqlp =
			"SELECT c.tipus, c.titol, c.qualificacio, "
			"ca.numero_temporada, DATE_FORMAT(ca.data_estrena, '%d/%m/%Y') AS data_formateada, ca.numero, ca.duracio "
			"FROM contingut c "
			"INNER JOIN serie s ON c.titol = s.titol "
			"INNER JOIN capitol ca ON c.titol = ca.titol_serie "
			"WHERE c.tipus = 'serie' "
			"AND ca.data_estrena <= CURDATE() "
			"AND ca.numero = ("
			"SELECT MAX(ca2.numero) "
			"FROM capitol ca2 "
			"WHERE ca2.titol_serie = c.titol "
			"AND ca2.data_estrena <= CURDATE() "
			") "
			"ORDER BY ca.data_estrena DESC "
			"LIMIT 5";
		sql::ResultSet* res = bd.execQuery(sqlp);
		int i = 0;
		while (res->next()) {
			DTONserie s = DTONserie(res->getString("data_formateada"), res->getString("titol"), res->getString("qualificacio"), res->getInt("duracio"), res->getInt("numero"), res->getInt("numero_temporada"));
			continguts.push_back(s);
			i++;
		}
		delete res;
		return continguts;

	}
};