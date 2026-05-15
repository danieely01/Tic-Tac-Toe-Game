//
// Created by danie on 2026. 05. 13..
//

#include "Jatekmester.hpp"
#include <iostream>

using namespace genv;
using namespace std;

JatekMester::JatekMester() {
    _kovetkezo_jatekos = 1; //alapbol az 1-es jatekos
    _jatek_vege = false;

    _palya.resize(15, vector<Mezo*>(15, nullptr));

    //Jatekter generalása
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {

            int x_koord = 10 + (j * 30);
            int y_koord = 10 + (i * 30);

            Mezo* uj_mezo = new Mezo(x_koord, y_koord, 30, [this, i, j]() {
                this->lepes(i, j);
            });

            _palya[i][j] = uj_mezo;
        }
    }
}

void JatekMester::lepes(int sor, int oszlop) {
    if (_jatek_vege) return;

    _palya[sor][oszlop]->set_allapot(_kovetkezo_jatekos);

    if (ellenoriz_gyozelmet(sor, oszlop, _kovetkezo_jatekos)) {
        _jatek_vege = true;
        cout << "GYOZELEM! A " << _kovetkezo_jatekos << ". jatekos ( "
                  << (_kovetkezo_jatekos == 1 ? "X" : "O") << " ) nyert!" << endl;
    } else {
        if (_kovetkezo_jatekos == 1) {
            _kovetkezo_jatekos = 2;
        } else {
            _kovetkezo_jatekos = 1;
        }
    }
}

int JatekMester::szamol_iranyba(int sor, int oszlop, int d_sor, int d_oszlop, int jatekos) {
    int darab = 0;
    int akt_sor = sor + d_sor;
    int akt_oszlop = oszlop + d_oszlop;

    while (akt_sor >= 0 && akt_sor < 15 && akt_oszlop >= 0 && akt_oszlop < 15) {
        if (_palya[akt_sor][akt_oszlop]->get_allapot() == jatekos) {
            darab++;
            akt_sor += d_sor;
            akt_oszlop += d_oszlop;
        } else {
            break;
        }
    }
    return darab;
}

bool JatekMester::ellenoriz_gyozelmet(int utolso_sor, int utolso_oszlop, int jatekos) {
    //5 kell a gyozelemhez
    // vizszint ellenorzes
    if (szamol_iranyba(utolso_sor, utolso_oszlop, 0, -1, jatekos) +
        szamol_iranyba(utolso_sor, utolso_oszlop, 0, 1, jatekos) + 1 >= 5) return true;

    // fuggoleges ell.
    if (szamol_iranyba(utolso_sor, utolso_oszlop, -1, 0, jatekos) +
        szamol_iranyba(utolso_sor, utolso_oszlop, 1, 0, jatekos) + 1 >= 5) return true;

    //bal-jobb atlo
    if (szamol_iranyba(utolso_sor, utolso_oszlop, -1, -1, jatekos) +
        szamol_iranyba(utolso_sor, utolso_oszlop, 1, 1, jatekos) + 1 >= 5) return true;

    //jobb-bal atlo
    if (szamol_iranyba(utolso_sor, utolso_oszlop, -1, 1, jatekos) +
        szamol_iranyba(utolso_sor, utolso_oszlop, 1, -1, jatekos) + 1 >= 5) return true;

    return false;
}

void JatekMester::rajzol() {
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            _palya[i][j]->rajzol();
        }
    }
    if (_jatek_vege) {
        gout << move_to(10, 480) << color(0, 255, 0) << text("VÉGE A JÁTÉKNAK!");
        string gyoztes = (_kovetkezo_jatekos == 1 ? "Az X jatekos nyert!" : "Az O jatekos nyert!");
        gout << move_to(10, 510) << text(gyoztes);
    } else {
        gout << move_to(10, 480) << color(255, 255, 255);
        gout << text("Soron kovetkezo: ") << text(_kovetkezo_jatekos == 1 ? "X" : "O");
    }
    gout << move_to(10, 550) << color(255, 255, 255);
    gout << text("'r' - jatek ujrainditasa ");
}

void JatekMester::kezel(event ev) {
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            _palya[i][j]->kezel(ev);
        }
    }
}

void JatekMester::reset() {
    _kovetkezo_jatekos = 1; // alapbol az 1-es jatekos
    _jatek_vege = false;

    //Mezo torles
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            _palya[i][j]->set_allapot(0);
        }
    }
}