//
// Created by danie on 2026. 04. 15..
//

#include "listbox.hpp"
#include "widgets.hpp"
#include "graphics.hpp"



using namespace genv;
using namespace std;

ListBox::ListBox(int x, int y, int x_meret, int y_meret, vector<string> elemek) :
    Widget(x, y, x_meret, y_meret)
{
    _elemek = elemek;
    _kivalasztott = 0; // elso elem kivalasztasa alapertelmezettkent
    _gorgetes = 0;
    _sor_magassag = 30;
    lathato_darab = y_merete / _sor_magassag; // hany elem fer el, rogton az inditas utan
}

string ListBox::get_ertek() const {
    if (_elemek.empty()) return "";
    return _elemek[_kivalasztott];
}

void ListBox::rajzol() {
    //Keret
    gout << move_to(x_helye, y_helye) << color(255,255,255) << box(x_merete, y_merete);
    gout << move_to(x_helye + 2, y_helye + 2) << color(0,0,0) << box(x_merete - 4, y_merete - 4);

    //Elemek
    for (int i = 0; i < lathato_darab; i++) {

        int aktualis_index = _gorgetes + i;
        if (aktualis_index >= (int)_elemek.size()) {
            break;
        }

        //Menu 'y' koordinataja
        int sor_y = y_helye + 2 + (i * _sor_magassag);



        //Hatter valtoztatas, kijelolt elem eseten
        if (aktualis_index == _kivalasztott) {
            gout << move_to(x_helye + 2, sor_y) << color(50, 100, 200)
                 << box(x_merete - 4, _sor_magassag);
        }

        //Szoveg felulirasa
        gout << move_to(x_helye + 10, sor_y + 5)
             << color(255, 255, 255) << text(_elemek[aktualis_index]);
    }
}

void ListBox::kezel(genv::event ev) {
    // Elem kivalasztaasa
    if (ev.type == ev_mouse && ev.button == btn_left) {

        // Eger a widget felett van-e
        if (ev.pos_x > x_helye && ev.pos_x < x_helye + x_merete &&
            ev.pos_y > y_helye && ev.pos_y < y_helye + y_merete) {

            // Fentrol szamolva az y koordinata
            int relativ_y = ev.pos_y - y_helye;
            int kattintott_sor = relativ_y / _sor_magassag;


            // Ha tortent gorgetes a menusorban
            int tenyleges_index = _gorgetes + kattintott_sor;

            // elemre kattintottunk-e
            if (tenyleges_index >= 0 && tenyleges_index < (int)_elemek.size()) {
                _kivalasztott = tenyleges_index;
            }
        }
    }

    //Gorgetes
    if (ev.type == ev_mouse) {
        if (ev.button == btn_wheeldown) {
            if (_gorgetes + lathato_darab < (int)_elemek.size()) {
                _gorgetes++;
            }
        }
        if (ev.button == btn_wheelup) {
            if (_gorgetes > 0) {
                _gorgetes--;
            }
        }
    }

    //Nyilak
    if (ev.type == ev_key) {
        if (ev.keycode == key_up && _kivalasztott > 0) {
            _kivalasztott--;
            if (_kivalasztott < _gorgetes) {
                _gorgetes--;
            }
        }
        if (ev.keycode == key_down && _kivalasztott < (int)_elemek.size() - 1) {
            _kivalasztott++;

            if (_kivalasztott >= _gorgetes + lathato_darab) {
                _gorgetes++;
            }
        }
    }
}
