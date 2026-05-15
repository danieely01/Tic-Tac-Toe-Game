//
// Created by danie on 2026. 05. 13..
//

#include "mezo.hpp"

using namespace genv;


Mezo::Mezo(int x, int y, int meret, std::function<void()> akcio)
    : Widget(x, y, meret, meret)
{
    _allapot = 0;
    _kattintas_akcio = akcio;
}

void Mezo::rajzol() {
    gout << move_to(x_helye, y_helye) << color(255, 255, 255) << box(x_merete, y_merete);
    gout << move_to(x_helye + 2, y_helye + 2) << color(0, 0, 0) << box(x_merete - 4, y_merete - 4);

    if (_allapot == 1) {  // X
        gout << move_to(x_helye + 10, y_helye + y_merete / 2 -10)
             << color(255, 100, 100) << text("X");
    }
    else if (_allapot == 2) { // o
        gout << move_to(x_helye + 10, y_helye + y_merete / 2 -10)
             << color(100, 100, 255) << text("O");
    }
}

void Mezo::kezel(event ev) {
    if (ev.type == ev_mouse && ev.button == btn_left) {

        if (ev.pos_x > x_helye && ev.pos_x < x_helye + x_merete &&
            ev.pos_y > y_helye && ev.pos_y < y_helye + y_merete) {

            //CSAK HA URES a gomb
            if (_allapot == 0) {

                if (_kattintas_akcio) {
                    _kattintas_akcio();
                }
            }
            }
    }
}

int Mezo::get_allapot() const {
    return _allapot;
}

void Mezo::set_allapot(int uj_allapot) {
    _allapot = uj_allapot;
}