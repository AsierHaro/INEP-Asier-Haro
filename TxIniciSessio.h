#include "cercadoraUsuari.h"
#include "PassarelaUsuari.h"
#include "PetitFlix.h"
class TxIniciSessio
{	private :
		string sobrenomU;
		string contrasenyaU;
public:
	TxIniciSessio() {
		sobrenomU = " ";
		contrasenyaU = " ";
	}

	TxIniciSessio(string sobrenom, string contrasenya) {
		sobrenomU = sobrenom;
		contrasenyaU = contrasenya;
	}
	
	void executar() const{
		CercadoraUsuari cerca;
		PassarelaUsuari usu = cerca.cercaPerSobrenom(sobrenomU);
		string contrasenya = usu.obteContrasenya();
		if (contrasenya == contrasenyaU) {
			Petitflix& petitflix = Petitflix::getInstance();
			petitflix.iniciaSesio(usu);
		}
		else {
			throw std::runtime_error("Hi ha hagut un error amb el sobrenom o la contrasenya");
		}
	}
};

