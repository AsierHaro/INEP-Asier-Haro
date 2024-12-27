#pragma once
#include "Petitflix.h"
#include "PassarelaVisualitzaPel.h"
#include "DTOPel.h"

class TxVisualitzaPel {
private:
    std::string titolPel; // Título de la película
    PassarelaVisualitzaPel pelicula; // Objeto para manejar la película seleccionada
    std::vector<PassarelaVisualitzaPel> relacionades; // Lista de películas relacionadas

public:
    // Constructor que recibe el título de la película
    explicit TxVisualitzaPel(const std::string& titol) : titolPel(titol) {}

    // Método principal para ejecutar la transacción
    void executar() {
        // Obtener el usuario loggeado
        Petitflix& petitflix = Petitflix::getInstance();
        PassarelaUsuari* usuari = petitflix.obteUsuari();

        if (usuari == nullptr) {
            throw std::runtime_error("No hi ha cap usuari loggejat.");
        }

        std::string sobrenom = usuari->obteSobrenom();

        // Validar si la película existe
        CercadoraVisualitzaPel cercadora;
    

       

        // Registrar visualización
        std::cout << "Vols visualitzar la pel·lícula '" << titolPel << "'? (S/N): ";
        std::string confirmacio;
        std::cin >> confirmacio;

        if (confirmacio == "S" || confirmacio == "s") {
            pelicula = PassarelaVisualitzaPel(titolPel, sobrenom, "24/12/2024", 1); // Fecha y numVisualitzacions ejemplo
            pelicula.insereix();

            // Mostrar información de la película
            DTOPel dto(pelicula);
            std::cout << dto << std::endl;

            // Obtener películas relacionadas y mostrarlas
            
            mostrarRelacionades();
        }
        else {
           cout << "Visualització cancel·lada." << std::endl;
        }
    }

private:
    // Método para mostrar películas relacionadas
    void mostrarRelacionades() const {
        if (relacionades.empty()) {
            cout << "No hi ha pel·lícules relacionades." << endl;
            return;
        }

        std::cout << "Pel·lícules relacionades:" << std::endl;
        for ( pel : relacionades) {
           cout << "  - Títol: " << pel.obteTitolPel() << std::endl;
           cout << "    Data visualització: " << pel.obteData() << std::endl;
           cout << "    Número de visualitzacions: " << pel.obteNumVisualitzacions() << std::endl;
        }
    }
};

