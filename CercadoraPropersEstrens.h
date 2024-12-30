#pragma once
#include "ConnexioBD.h"
#include "DTOEstrenes.h"
class CercadoraPropersEstrens
{
public:
	CercadoraPropersEstrens() {

	}
	vector<DTOEstrenes> cercaEstrens() {
		vector<DTOEstrenes> continguts;
		ConnexioBD bd;
		string sqlp =
			"SELECT c.tipus, c.titol, c.qualificacio, "
			"p.duracio, p.data_estrena AS data_original, DATE_FORMAT(p.data_estrena, '%d/%m/%Y') AS data_formateada, 0 AS temporada "
			"FROM contingut c "
			"INNER JOIN pelicula p ON c.titol = p.titol "
			"WHERE c.tipus = 'pelicula' "
			"AND p.data_estrena > CURDATE() "
			"UNION ALL "
			"SELECT k.tipus, k.titol, k.qualificacio, "
			"0 AS duracio, ca.data_estrena AS data_original, DATE_FORMAT(ca.data_estrena, '%d/%m/%Y') AS data_formateada, ca.numero_temporada AS temporada "
			"FROM capitol ca "
			"INNER JOIN contingut k ON k.titol = ca.titol_serie "
			"WHERE k.tipus = 'serie' "
			"AND ca.data_estrena > CURDATE() "
			"ORDER BY data_original ASC, temporada ASC";
		sql::ResultSet* res = bd.execQuery(sqlp);
		while (res->next()) {
			DTOEstrenes p = DTOEstrenes(res->getString("data_formateada"), res->getString("tipus"), res->getString("titol"), res->getString("qualificacio"), res->getInt("duracio"), res->getInt("temporada"));
			continguts.push_back(p);
		}
		delete res;


		return continguts;

	}
};