#pragma once
#include "ConnexioBD.h"

class TxComprobarEdat {
public:
    void comp(int edat, string qualificacio) {
        bool trobat = false;
        if (qualificacio == "TP") trobat = true;
        else if (qualificacio == "7+" && edat >= 7) trobat = true;
        else if (qualificacio == "12+" && edat >= 12) trobat = true;
        else if (qualificacio == "16+" && edat >= 16) trobat = true;
        else if (qualificacio == "18+" && edat >= 18) trobat = true;

        if (!trobat) {
            throw runtime_error("Pel·lícula no apta per la teva edat");
        }
    }
};
