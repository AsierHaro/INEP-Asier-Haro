// INEP!.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "CapaDePresentació.h"
using namespace std;


int main()
{
    int opció;
    bool sortir = false;
    cout << "1. Gestio usuari" << endl << "2. Gestio continguts" <<
        endl << "3. Consultes" << endl << "4. Sortir" << endl;
    while (cin >> opció && sortir != true) {
        if (opció == 1) {
            int op;
            cout << "1. Consultar usuari" << std::endl;
            cout << "2. Modificar usuari" << std::endl;
            cout << "3. Esborrar usuari" << std::endl;
            cout << "4. Registrar Usuari" << endl;
            std::wcout << "5. Tornar" << std::endl;
            std::wcout << "Opcio: ";
            std::cin >> op;
            CapaDePresentacio& presentacio = CapaDePresentacio::getInstance();
            switch (op) {
            case 1: presentacio.consultaUsuari(); break;
            case 2: presentacio.modificaUsuari(); break;
            case 3: presentacio.esborraUsuari(); break;
            case 4: presentacio.registrarUsuari();
            }

        }
        else if (opció == 2) {
            cout << "1. Gestio pel·licules" << endl << "2. Gestio series" << "3. Tornar" << endl;
        }
        else if (opció == 3) {
            cout << "1. Consulta per qualificació d’edat" << endl << "2. Ultimes novetats" <<
                endl << "3. Proximes estrenes" << "4. Tornar" << endl;
        }
        else if (opció == 4) {
            sortir = true;
        }
    }
}
// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
