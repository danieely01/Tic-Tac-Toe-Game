//
// Created by danie on 2026. 05. 13..
//

#ifndef CLIONGRAPHICSKIT_JATEKMESTER_HPP
#define CLIONGRAPHICSKIT_JATEKMESTER_HPP


#include "widgets.hpp"
#include "mezo.hpp"
#include <vector>
using namespace std;
using namespace genv;

class JatekMester {
protected:
    vector<vector<Mezo*>> _palya;
    int _kovetkezo_jatekos;
    bool _jatek_vege;

    void lepes(int sor, int oszlop);
    int szamol_iranyba(int sor, int oszlop, int d_sor, int d_oszlop, int jatekos);
    bool ellenoriz_gyozelmet(int utolso_sor, int utolso_oszlop, int jatekos);

public:
    JatekMester();
    void rajzol();
    void kezel(event ev);
    void reset();
};




#endif //CLIONGRAPHICSKIT_JATEKMESTER_HPP