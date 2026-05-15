//
// Created by danie on 2026. 04. 10..
//

#include "widgets.hpp"

Widget::Widget(int x_helye, int y_helye, int x_merete, int y_merete) :
x_helye(x_helye),
y_helye(y_helye),
x_merete(x_merete),
y_merete(y_merete)
{

}

bool Widget::kivalasztva(int x_egerpozi, int y_egerpozi) {
    bool valasztva = x_egerpozi > x_helye && x_egerpozi < x_helye + x_merete && y_egerpozi > y_helye && y_egerpozi < y_helye + y_merete;
    return valasztva;
}