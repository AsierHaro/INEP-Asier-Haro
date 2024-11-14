// INEP!.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "ConnexioBD.h"
using namespace std;


void consulta_usuari(string sobrenom_usuari)
{
    try {
        ConnexioBD bd;
        string sql = "SELECT * FROM usuari WHERE sobrenom='sobrenom_usuari'";
        sql::ResultSet* res = bd.execQuery(sql);
        while (res->next()) {
            cout << "Sobrenom: " << res->getString("sobrenom") << endl;
            cout << "Nom: " << res->getString("nom") << endl;
            cout << "Correu: " << res->getString("correu_electronic") << endl;
        }
        bd.getCon()->close();
    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << std::endl;
        if (con != NULL) con->close();
    }
}


void registrar_usuari()
{
    try {
        ConnexioBD bd;
        string sql = "INSERT INTO usuari (sobrenom,usuari,correu_electronic) VALUES (asierhr, 'Asier Haro', asier.haro@estudiantat.upc.edu)";
        bd.exec(sql);
        bd.getCon()->close();
    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << std::endl;
        if (bd.getCon() != NULL) bd.getCon()->close();
    }
}


void modificar_usuari()
{
    try {
        ConnexioBD bd;
        string sql = "UPDATE usuari SET name = 'Un altre nom', correu_electronic = 'un altre correu' WHERE sobrenom = 'sobrenom_usuari'";
        bd.exec(sql);
        bd.getCon()->close();
    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << std::endl;
        if (bd.getCon() != NULL) bd.getCon()->close();
    }
}


void esborrar_usuari()
{
    try {
        ConnexioBD bd;
        string sql = "DELETE FROM usuari WHERE sobrenom = 'sobrenom_usuari'";
        bd.exec(sql);
        bd.getCon()->close();
    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << std::endl;
        if (bd.getCon() != NULL) bd.getCon->close();
    }
}








void procesarRegistreUsuari() {
    string sobrenom, nom;
    cin >> sobrenom;
    getline(cin, nom);
    if (sobrenom == " " or nom == " ") {
        cout << "Error al registrar l'usuari" << endl;
    }
    else {
        cout << "El registre de l'usuari " << nom <<" " << "(" << sobrenom << ") s'ha processat correctament." << endl;
    }
}

int main()
{
    int opció;
    bool sortir = false;
    cout << "1. Gestio usuari" << endl << "2. Gestio continguts" <<
        endl << "3. Consultes" << endl << "4. Sortir" << endl;
    while (cin >> opció && sortir != true) {
        if (opció == 1) {
            cout << "1. Registre usuari" << endl << "2. Consulta usuari" <<
                endl << "3. Modifica usuari" << endl << "4. Esborra usuari" << endl << "5. Tornar" << endl;
            cin >> opció;
            if (opció == 1) {
                procesarRegistreUsuari();
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
