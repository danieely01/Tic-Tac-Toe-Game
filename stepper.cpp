//
// Created by danie on 2026. 04. 15..
//

#include "stepper.hpp"

#include <ostream>
using namespace genv;
using namespace std;

Stepper::Stepper(int x, int y, int x_meret, int y_meret, int min, int max) :
Widget(x, y, x_meret, y_meret)
{
    _min = min;
    _max = max;
}

const int GOMB_MERETE = 30;

void Stepper::rajzol() {
    //Keret
    gout << move_to(x_helye, y_helye) << color(255,255,255) << box(x_merete, y_merete);
    gout << move_to(x_helye + 2, y_helye + 2) << color(0,0,0) << box(x_merete - 4, y_merete - 4);

    // Ertek kiirasa
    gout << move_to(x_helye + 10, y_helye + y_merete/2 - 10) << color(255,255,255) << text(to_string(_ertek));

    //Noveles keret
    gout << move_to(x_helye + x_merete - GOMB_MERETE, y_helye)
         << color(100,100,100) << box(GOMB_MERETE, y_merete/2);

    //Noveles szoveg
    gout << move_to(x_helye + x_merete - GOMB_MERETE + 8, y_helye + 5)
         << color(255,255,255) << text("+");

    //Csokkenes keret
    gout << move_to(x_helye + x_merete - GOMB_MERETE, y_helye + y_merete/2)
         << color(70,70,70) << box(GOMB_MERETE, y_merete/2);

    //Csokkenes szoveg
    gout << move_to(x_helye + x_merete - GOMB_MERETE + 10, y_helye + y_merete/2 + 5)
         << color(255,255,255) << text("-");


}

void Stepper::kezel(genv::event ev) {


    if (ev.type == ev_mouse && ev.button == btn_left) {

        // eger poz a gombok felett vannak-e
        if (ev.pos_x > x_helye + x_merete - GOMB_MERETE && ev.pos_x < x_helye + x_merete) {

            // Noveles
            if (ev.pos_y > y_helye && ev.pos_y < y_helye + y_merete / 2) {
                if (_ertek < _max) {
                    _ertek++;
                }
            }

            // Csokkenees
            if (ev.pos_y > y_helye + y_merete / 2 && ev.pos_y < y_helye + y_merete) {
                if (_ertek > _min) {
                    _ertek--;
                }
            }
        }
    }


    //Nyilak es pagedown, up
    if (ev.type == ev_key) {
        if (ev.keycode == key_up && _ertek < _max) {
            _ertek++;
        }
        if (ev.keycode == key_down && _ertek > _min) {
            _ertek--;
        }
        if (ev.keycode == key_pgup) {
            _ertek += 10;
            if (_ertek > _max) _ertek = _max;
        }
        if (ev.keycode == key_pgdn) {
            _ertek -= 10;
            if (_ertek < _min) _ertek = _min;
        }
    }
}


