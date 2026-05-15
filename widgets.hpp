//
// Created by danie on 2026. 04. 10..
//

#ifndef CLIONGRAPHICSKIT_WIDGETS_HPP
#define CLIONGRAPHICSKIT_WIDGETS_HPP

#include "graphics.hpp"
using namespace genv;


class Widget {
protected:
    int x_helye, y_helye, x_merete, y_merete;
public:
    Widget(int x_helye, int y_helye, int x_merete, int y_merete);
    virtual bool kivalasztva(int x_egerpozi, int y_egerpozi);
    virtual void rajzol() = 0;
    virtual void kezel(event ev) = 0;

};


#endif //CLIONGRAPHICSKIT_WIDGETS_HPP