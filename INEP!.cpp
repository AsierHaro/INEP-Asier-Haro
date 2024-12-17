#include <locale>
#include "CapaDePresentacio.h"
using namespace std;


int main()
{
    int opcio;
    bool sortir = false;
    CapaDePresentacio& presentacio = CapaDePresentacio::getInstance();
    while (!sortir) {
        cout << "*********************" << endl;
        cout << "    Menu Principal" << endl;
        cout << "*********************" << endl;
        cout << "1. Iniciar sessio" << endl << "2. Registrar Usuari" << endl 
            << "3. Consultes" << endl << "4. Sortir" << endl;
        cout << "Escriu opcio: ";
        cin >> opcio;
        system("cls");
        if (opcio == 1){
            presentacio.iniciSesio();
            system("cls");
            if(presentacio.sessioIniciada){
                while (presentacio.sessioIniciada && !sortir) {
                    cout << "*********************" << endl;
                    cout << "    Menu Principal" << endl;
                    cout << "*********************" << endl;
                    cout << "1. Gestio usuaris" << std::endl;
                    cout << "2. Visualitzar" << std::endl;
                    cout << "3. Consultes" << std::endl;
                    cout << "4. Tancar sessio" << endl;
                    wcout << "5. Sortir" << std::endl;
                    wcout << " Escriu opcio: ";
                    cin >> opcio;
                    system("cls");
                    if (opcio == 1) {
                        bool tornar = false;
                        while (!tornar && presentacio.sessioIniciada) {
                            cout << "-----------------------" << endl;
                            cout << "    Gestio Usuari" << endl;
                            cout << "-----------------------" << endl;
                            cout << "1. Consulta usuari" << std::endl;
                            cout << "2. Modificar usuari" << std::endl;
                            cout << "3. Modificar contrasenya" << std::endl;
                            cout << "4. Esborrar usuari" << endl;
                            wcout << "5. Tornar" << std::endl;
                            wcout << " Escriu opcio: ";
                            cin >> opcio;
                            system("cls");
                            if (opcio == 1) presentacio.consultaUsuari();
                            else if (opcio == 2) presentacio.modificaUsuari();
                            else if (opcio == 3);
                            else if (opcio == 4) presentacio.esborraUsuari();
                            else tornar = true;
                        }
                    }
                    else if (opcio == 2) {
                        bool tornar = false;
                        while (!tornar) {
                            cout << "-----------------------" << endl;
                            cout << "      Visualitzar" << endl;
                            cout << "-----------------------" << endl;
                            cout << "1. Visualitzar pel·licula" << std::endl;
                            cout << "2. Visualitzar capitol" << std::endl;
                            cout << "3. Consultar visualitzacions" << endl;
                            wcout << "4. Tornar" << std::endl;
                            wcout << " Escriu opcio: ";
                            cin >> opcio;
                        }
                    }
                    else if (opcio == 3) {
                        bool tornar = false;
                        while (!tornar) {
                            cout << "-----------------------" << endl;
                            cout << "      Consultes" << endl;
                            cout << "-----------------------" << endl;
                            cout << "1. Properes estrenes" << std::endl;
                            cout << "2. Ultimes novetats" << std::endl;
                            cout << "3. Pel·licules mes vistes" << endl;
                            wcout << "4. Tornar" << std::endl;
                            wcout << " Escriu opcio: ";
                            cin >> opcio;
                        }
                    }
                    else if (opcio == 4) {
                        presentacio.tancarSesio();
                    }
                    else {
                        sortir = true;
                    }
                }
            }
        }
        else if (opcio == 2) {
            presentacio.registrarUsuari();
        }
        else if (opcio == 3) {
            bool tornar = false;
            while (!tornar) {
                cout << "1. Properes estrenes" << std::endl;
                cout << "2. Ultimes novetats" << std::endl;
                cout << "3. Pel·licules mes vistes" << endl;
                wcout << "4. Tornar" << std::endl;
                wcout << " Escriu opcio: ";
                cin >> opcio;
            }
        }
        else if(opcio == 4) {
            sortir = true;
        }
    }
}
