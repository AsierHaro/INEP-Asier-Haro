#pragma once
#include "DTOPelMesV.h"
#include "ConnexioBD.h"

class CercadoraPelMesV
{
public:
	CercadoraPelMesV() {

	}
	vector<DTOPelMesV> cercaMesVistes(bool x) {
		vector<DTOPelMesV> continguts;
		ConnexioBD bd;
		string sobrenom = "";
		if (x) {
			TxConsultarUsuari tx;
			tx.executar();
			DTOUsuari usu = tx.obteResultat();
			sobrenom = usu.obteSobrenom();
		}
		string sqlp =
			"SELECT c.tipus, c.titol, c.qualificacio, "
			"p.duracio, SUM(v.num_visualitzacions) AS total_visualitzacions, "
			"CASE WHEN MAX(CASE WHEN v.sobrenom_usuari = '" + sobrenom + "' THEN DATE_FORMAT(v.data, '%d/%m/%Y') ELSE NULL END) IS NOT NULL "
			"     THEN MAX(CASE WHEN v.sobrenom_usuari = '" + sobrenom + "' THEN DATE_FORMAT(v.data, '%d/%m/%Y') ELSE NULL END) "
			"     ELSE '' END AS data_filtrada "
			"FROM contingut c "
			"INNER JOIN pelicula p ON c.titol = p.titol "
			"INNER JOIN visualitzacio_pelicula v ON c.titol = v.titol_pelicula "
			"WHERE c.tipus = 'pelicula' "
			"GROUP BY c.tipus, c.titol, c.qualificacio, p.duracio "
			"ORDER BY total_visualitzacions DESC "
			"LIMIT 5";
		sql::ResultSet* res = bd.execQuery(sqlp);

		while (res->next()) {
			DTOPelMesV p = DTOPelMesV(res->getString("data_filtrada"), res->getString("titol"), res->getString("qualificacio"), res->getInt("duracio"), res->getInt("total_visualitzacions"));
			continguts.push_back(p);
		}
		delete res;
		return continguts;

	}
};