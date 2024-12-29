#pragma once
#include "PassarelaNPelicula.h"
#include "ConnexioBD.h"

class CercadorNPelicules
{
public:
	CercadorNPelicules() {

	}
	vector<PassarelaNPelicula> cercaNovetats() {
		vector<PassarelaNPelicula> continguts;
		ConnexioBD bd;
		string sqlp =
			"SELECT c.tipus, c.titol, c.qualificacio, "
			"p.duracio, DATE_FORMAT(p.data_estrena, '%d/%m/%Y') AS data_formateada "
			"FROM contingut c "
			"INNER JOIN pelicula p ON c.titol = p.titol "
			"WHERE c.tipus = 'pelicula' "
			"AND p.data_estrena <= CURDATE() "
			"ORDER BY p.data_estrena DESC "
			"LIMIT 5";
		sql::ResultSet* res = bd.execQuery(sqlp);
		while (res->next()) {
			PassarelaNPelicula p = PassarelaNPelicula(res->getString("data_formateada"), res->getString("titol"), res->getString("qualificacio"), res->getInt("duracio"));
			continguts.push_back(p);
		}
		delete res;
		return continguts;

	}
};