#include <iostream>
#include <string>
#include <locale>
#include "TxIniciSessio.h"
#include "TxTancaSessio.h"
#include "TxRegistraUsuari.h"
#include "TxConsultarUsuari.h"
#include "CtrlModificaUsuari.h"
#include "TxEsborraUsuari.h"
#include "TxConsultaProperesEstrenes.h"
#include "TxNovetatspelicules.h"
#include "TxNovetatsseries.h"
#include "TxConsultaPeliculesMesVistes.h"
#include "TxInformacioPel.h"
#include "TxVisualitzarPelicula.h"
#include "TxPeliculasVisualitzades.h"
#include "TxSeriesVisualitzades.h"
#include "TxInfoVisualitzacions.h"
#include "TxInfoTemporades.h"
#include "TxPeliculesRelacionades.h"
#include "TxComprobarEdat.h"
#include "TxVisualitzaSerie.h"
using namespace std;

class CapaDePresentacio
{
private:
	CapaDePresentacio() {
	}

public:

	static CapaDePresentacio& getInstance() {
		static CapaDePresentacio instance;
		return instance;
	}

	bool sessioIniciada = false;

	void registrarUsuari() {
		string sobrenomU, nomU, correuU, contrasenya, dataU, modalitat_subscripcio;
		cout << "** Registra usuari **" << endl;
		cout << "Nom: ";
		cin.ignore();
		getline(cin, nomU);
		cout << "Sobrenom: ";
		cin >> sobrenomU;
		cout << "Contrasenya: ";
		cin >> contrasenya;
		cout << "Correu electronic: ";
		cin >> correuU;
		cout << "Data naixament (DD/MM/AAAA): ";
		cin >> dataU;
		cout << "Modalitats de subscripcio disponibles " << endl;
		cout << " > 1. Completa " << endl;
		cout << " > 2. Cinefil " << endl;
		cout << " > 3. Infantil " << endl;
		cout << "Escull modalitat: ";
		cin >> modalitat_subscripcio;
		system("cls");
		try {
			TxRegistraUsuari tx(sobrenomU, nomU, correuU, contrasenya, dataU, modalitat_subscripcio);
			tx.executar();
			cout << "Usuari registrat correctament!" << endl;
		}
		catch (sql::SQLException& e) {
			if (e.getErrorCode() == 1452) {
				cout << "Modalitat no existeix" << endl;
			}
			else if (e.getErrorCode() == 1062) {
				string errorMessage = e.what();
				if (errorMessage.find("sobrenom") != string::npos) cout << "Ja existeix un usuari amb aquest sobrenom" << endl;
				else if (errorMessage.find("correu_electronic") != string::npos) cout << "Ja existeix un usuari amb aquest correu electronic" << endl;
			}
		}
		cin.ignore();
		cin.get();
		system("cls");
	}

	void consultaUsuari() {
		cout << "** Consulta usuari **" << endl;
		try {
			TxConsultarUsuari tx;
			tx.executar();
			DTOUsuari usu = tx.obteResultat();
			cout << usu << endl;
			TxInfoVisualitzacions txv;
			txv.executar();
			cout << txv.obtePel() << " pelicules visualitzades" << endl;
			cout << txv.obteSerie() << " capitols visualitzats" << endl;
		}
		catch (const exception& e) {
			std::cout << "Error: " << e.what() << endl;
		}
		cin.ignore();
		cin.get();
		system("cls");
	}

	void modificaUsuari() {
		cout << "** Modifica usuari **" << endl;
		CtrlModificaUsuari ctrl;
		DTOUsuari usu = ctrl.consultaUsuari();
		cout << usu << endl;
		cin.ignore();
		cin.get();
		system("cls");
		string sobrenomU, nomU, correuU, contrasenya, dataU, modalitat_subscripcio;
		cout << "Omplir la informacio que es vol modificar ..." << endl;
		cout << "Nom: ";
		getline(std::cin, nomU);
		cout << "Contrasenya: ";
		getline(std::cin, contrasenya);
		cout << "Correu electronic: ";
		getline(std::cin, correuU);
		cout << "Data naixament (DD/MM/AAAA): ";
		getline(std::cin, dataU);
		cout << "Modalitats de subscripcio disponibles " << endl;
		cout << " > 1. Completa " << endl;
		cout << " > 2. Cinefil " << endl;
		cout << " > 3. Infantil " << endl;
		cout << "Escull modalitat: ";
		getline(cin, modalitat_subscripcio);
		try {
			ctrl.modificaUsuari(nomU, contrasenya, correuU, dataU, modalitat_subscripcio);
			system("cls");
			usu = ctrl.consultaUsuari();
			cout << usu << endl;
		}
		catch (sql::SQLException& e) {
			if (e.getErrorCode() == 1062) {
				cout << "El nou  correu ja existeix" << endl;
			}
		}
		cin.get();
		system("cls");
	}

	void esborraUsuari() {
		string contrasenya;
		cout << "** Esborrar usuari **" << endl;
		cout << "Per confirmar l'esborrat, s'ha d'entrar la contrasenya ..." << endl;
		cout << "Contrasenya: ";
		cin >> contrasenya;
		system("cls");
		try {
			TxEsborraUsuari tx(contrasenya);
			tx.executar();
			cout << "Usuari esborrat correctament" << endl;
			TxTancaSessio ty;
			ty.executar();
			sessioIniciada = false;
		}
		catch (const runtime_error& e) {
			cout << "Error: " << e.what() << endl;
		}
		cin.ignore();
		cin.get();
		system("cls");
	}

	void iniciSesio() {
		string sobrenomU, contrasenyaU;
		cout << "** Inici sessio **" << std::endl;
		cout << "sobrenom: ";
		cin >> sobrenomU;
		cout << "contrasenya: ";
		cin >> contrasenyaU;
		try {
			TxIniciSessio tx(sobrenomU, contrasenyaU);
			tx.executar();
			sessioIniciada = true;
		}
		catch (const runtime_error& e) {
			cout << "Error: " << e.what() << endl;
		}

		if (sessioIniciada) {
			system("cls");
			cout << "Sessio iniciada correctament." << endl;
		}
		cin.ignore();
		cin.get();
	}
	void tancarSesio() {
		string tancar;
		cout << "** Tancar sessio **" << endl;
		cout << "Vols tancar la sessio (S/N): ";
		cin >> tancar;
		if (tancar == "S") {
			TxTancaSessio tx;
			tx.executar();
			sessioIniciada = false;
		}
		system("cls");
	}

	void ConsultaProperesEstrenes(bool x) {
		cout << "** Properes estrenes **" << endl;
		cout << "Modalitat: ";
		try {
			if (!x) {
				string modalitat;
				cin >> modalitat;
				if (modalitat != "Cinefil" and modalitat != "Completa" and modalitat != "Infantil") {
					throw std::runtime_error("La modalitat '" + modalitat + "' no existeix en la base de dades.");
				}
			}
			else {
				TxConsultarUsuari tx;
				tx.executar();
				DTOUsuari usu = tx.obteResultat();
				cout << usu.obteSubscripcio();
			}
			std::cout << std::endl << std::endl << std::endl;
			TxConsultarProperesEstrenes tx;
			tx.executar();
			vector<DTOEstrenes> v = tx.obteresultat();
			for (unsigned int i = 0; i < v.size(); i++) {
				cout << i + 1 << ".- " << v[i];
			}
		}
		catch (const runtime_error& e) {
			cerr << "Error:" << e.what() << endl;
		}
		cin.ignore();
		cin.get();
		system("cls");
	}

	void ConsultaUltimesNovetats(bool x) {
		cout << "** Novetats **" << endl;
		cout << "Modalitat: ";
		try {
			if (!x) {
				string modalitat;
				cin >> modalitat;
				if (modalitat != "Cinefil" and modalitat != "Completa" and modalitat != "Infantil") {
					throw std::runtime_error("La modalitat '" + modalitat + "' no existeix en la base de dades.");
				}
			}
			else {
				TxConsultarUsuari tx;
				tx.executar();
				DTOUsuari usu = tx.obteResultat();
				cout << usu.obteSubscripcio();
			}
			cout << endl << endl << endl;
			cout << "**  Novetats pelicules **" << endl
				<<  "*************************" << endl;
		
			TxNovetatspelicules tx;
			tx.executar();
			vector<DTONpel> vp = tx.obteresultat();
			for (unsigned int i = 0; i < vp.size(); i++) {
				cout << i + 1 << ".- " << vp[i];
			}
			cout << "**  Novetats Series **" << endl
				<<	"**********************" << endl;
			TxNovetatsseries ty;
			ty.executar();
			vector<DTONserie> vs = ty.obteresultat();
			for (unsigned int i = 0; i < vs.size(); i++) {
				cout << i + 1 << ".- " << vs[i];
			}
		}
		catch (const runtime_error& e) {
			cerr << "Error:" << e.what() << endl;
		}
		cin.ignore();
		cin.get();
		system("cls");
	}

	void ConsultaPeliculesMesVistes(bool x) {
		cout << "** Pelicules mes visualitzades **" << endl << endl;
		try {
			TxConsultaPeliculesMesVistes tx;
			tx.executar(x);
			vector<DTOPelMesV> v = tx.obteresultat();
			for (unsigned int i = 0; i < v.size(); i++) {
				cout << i + 1 << ".- " << v[i];
			}
		}
		catch (const runtime_error& e) {
			cerr << "Error:" << e.what() << endl;
		}
		cin.ignore();
		cin.get();
		system("cls");
	}

	void VisualitzaPel() {
		string titolPel, continuar;
		cout << "** Visualitza Pelicula **" << endl;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Nom pelicula: ";
		getline(std::cin, titolPel);
		try {
			TxInformacioPel txi;
			txi.executar(titolPel);
			system("cls");
			DTOPel pel = txi.obtenPelicula();
			TxConsultarUsuari tx;
			tx.executar();
			DTOUsuari usu = tx.obteResultat();
			TxComprobarEdat txed;
			txed.comp(usu.obteEdat(), pel.obteQualificacio());
			cout << "Informacio pelicula ..." << endl;
			cout << pel << endl;
			cout << "vols continuar amb la visulitzacio (S/N):";
			cin >> continuar;
			system("cls");
			if (continuar == "S") {
				string titol = pel.obteTitolPel();
				string sobrenom = usu.obteSobrenom();
				TxVisualitzarPelicula txv;
				string data = txv.executar(sobrenom, titol);
				cout << "Visualitzaci0 registrada: " << data << endl;
				cout << "Pelicules relacionades:" << endl;
				TxPeliculesRelacionades txr;
				txr.executar(titol);
				vector<DTOPeliR> v = txr.obteresultat();
				for (unsigned int i = 0; i < v.size(); i++) {
					cout << v[i];
				}
			}
			else if (continuar != "N") {
				cout << endl << "Error: Tecla incorrecta." << endl;
			}
		}
		catch (const std::runtime_error& e) {
			cout << "Error: " << e.what() << endl;
		}
		cin.ignore();
		cin.get();
		system("cls");
	}
	void VisualitzarCapitol() {
		string titolSerie, continuar;
		cout << "** Visualitza Capitol **" << endl;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Nom de la serie: ";
		getline(cin, titolSerie);
		try {
			TxInfoTemporades txt;
			txt.executar(titolSerie);
			DTOTemporada  t = txt.obteTemporada();
			TxConsultarUsuari tx;
			tx.executar();
			int numt = t.obtenumtemporada();
			DTOUsuari usu = tx.obteResultat();
			TxComprobarEdat txed;
			txed.comp(usu.obteEdat(), t.obtequalificacio());
			system("cls");
			cout << "La serie te " << numt << " temporades." << endl << " Escull temporada: ";
			int temp;
			cin >> temp;
			if (temp > numt or temp < 0) throw std::runtime_error("No existeis la temporada");
			TxVisualitzaSerie tv;
			tv.executar(usu.obteNom(), titolSerie, temp);
			vector<DTOCapitol> v = tv.obteresultat();
			system("cls");
			cout << "Llista capítols:" << endl;
			for (unsigned int i = 0; i < v.size(); i++) {
				cout << v[i];
			}
			int cap;
			cout << "Numero de capitol a visualitzar: ";
			cin >> cap;
			if (cap > v.size() or 0 > cap)  throw std::runtime_error("No existeis el capitol");
			system("cls");
			cout << "Vols continuar amb la visualitzacio (S/N):";
			string sn;
			cin >> sn;
			if (sn == "S") {
				system("cls");
				string data = tv.visualitzar(cap);
				cout << "Visualitzacio registrada: " << data << endl;
			}
		}
		catch (const runtime_error& e) {
			cout << "Error: " << e.what() << endl;
		}
		cin.ignore();
		cin.get();
		system("cls");

	}
	void ConsultaVisualitzacions() {
		cout << "** Consulta visualitzacions **" << endl << endl;
		cout << "** Visualitzacions pelicules **" << endl
			<<	"*******************************" << endl;
		try {
			TxConsultarUsuari tx;
			tx.executar();
			DTOUsuari usu = tx.obteResultat();
			string sobrenom = usu.obteSobrenom();
			TxPeliculasVisualitzades txp;
			txp.executar(sobrenom);
			vector<DTOPeliV> vp = txp.obteresultat();
			for (unsigned int i = 0; i < vp.size(); i++) {
				cout << vp[i];
			}
			cout << "** Visualitzacions series **" << endl
				 << "****************************" << endl;
			TxSeriesVisualitzades txs;
			txs.executar(sobrenom);
			vector<DTOSerieV> vs = txs.obteresultat();
			for (unsigned int i = 0; i < vs.size(); i++) {
				cout << vs[i];
			}
		}
		catch (const runtime_error& e) {
			cout << "Error: " << e.what() << endl;
		}
		cin.ignore();
		cin.get();
		system("cls");
	}
};
