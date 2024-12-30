#include <locale>
#include "CapaDePresentacio.h"
#include <windows.h>
using namespace std;


int main()
{
    SetConsoleOutputCP(CP_UTF8);
    int opcio;
    bool sortir = false;
    CapaDePresentacio& presentacio = CapaDePresentacio::getInstance();
    while (!sortir) {
        cout << "*********************" << endl;
        cout << "    Menu Principal" << endl;
        cout << "*********************" << endl;
        cout << "1. Iniciar sessió" << endl << "2. Registrar Usuari" << endl
            << "3. Consultes" << endl << "4. Sortir" << endl;
        cout << "Escriu opció: ";
        cin >> opcio;
        system("cls");
        if (opcio == 1) {
            presentacio.iniciSesio();
            system("cls");
            if (presentacio.sessioIniciada) {
                while (presentacio.sessioIniciada && !sortir) {
                    cout << "*********************" << endl;
                    cout << "    Menu Principal" << endl;
                    cout << "*********************" << endl;
                    cout << "1. Gestió usuaris" << std::endl;
                    cout << "2. Visualitzar" << std::endl;
                    cout << "3. Consultes" << std::endl;
                    cout << "4. Tancar sessió" << endl;
                    wcout << "5. Sortir" << std::endl;
                    wcout << " Escriu opció: ";
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
                            cout << "3. Esborrar usuari" << endl;
                            wcout << "4. Tornar" << std::endl;
                            wcout << " Escriu opció: ";
                            cin >> opcio;
                            system("cls");
                            if (opcio == 1) presentacio.consultaUsuari();
                            else if (opcio == 2) presentacio.modificaUsuari();
                            else if (opcio == 3) presentacio.esborraUsuari();
                            else tornar = true;
                        }
                    }
                    else if (opcio == 2) {
                        bool tornar = false;
                        while (!tornar) {
                            cout << "-----------------------" << endl;
                            cout << "      Visualitzar" << endl;
                            cout << "-----------------------" << endl;
                            cout << "1. Visualitzar pel·lícula" << std::endl;
                            cout << "2. Visualitzar capítol" << std::endl;
                            cout << "3. Consultar visualitzacions" << endl;
                            wcout << "4. Tornar" << std::endl;
                            wcout << " Escriu opció: ";
                            cin >> opcio;
                            system("cls");
                            if (opcio == 1) presentacio.VisualitzaPel();
                            else if (opcio == 2) presentacio.VisualitzarCapitol();
                            else if (opcio == 3) presentacio.ConsultaVisualitzacions();
                            else if (opcio == 4) tornar = true;

                        }
                    }
                    else if (opcio == 3) {
                        bool tornar = false;
                        while (!tornar) {
                            cout << "-----------------------" << endl;
                            cout << "      Consultes" << endl;
                            cout << "-----------------------" << endl;
                            cout << "1. Properes estrenes" << std::endl;
                            cout << "2. Últimes novetats" << std::endl;
                            cout << "3. Pel·lícules més vistes" << endl;
                            wcout << "4. Tornar" << std::endl;
                            wcout << " Escriu opció: ";
                            cin >> opcio;
                            system("cls");
                            if (opcio == 1) presentacio.ConsultaProperesEstrenes(true);
                            else if (opcio == 2) presentacio.ConsultaUltimesNovetats(true);
                            else if (opcio == 3) presentacio.ConsultaPeliculesMesVistes(true);
                            else if (opcio == 4) tornar = true;

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
                cout << "-----------------------" << endl;
                cout << "      Consultes" << endl;
                cout << "-----------------------" << endl;
                cout << "1. Properes estrenes" << std::endl;
                cout << "2. Últimes novetats" << std::endl;
                cout << "3. Pel·lícules més vistes" << endl;
                wcout << "4. Tornar" << std::endl;
                wcout << " Escriu opció: ";
                cin >> opcio;
                system("cls");
                if (opcio == 1) presentacio.ConsultaProperesEstrenes(false);
                else if (opcio == 2) presentacio.ConsultaUltimesNovetats(false);
                else if (opcio == 3) presentacio.ConsultaPeliculesMesVistes(false);
                else if (opcio == 4) tornar = true;
            }
        }
        else if (opcio == 4) {
            sortir = true;
        }
    }
}
