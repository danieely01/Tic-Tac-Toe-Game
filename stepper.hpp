//
// Created by danie on 2026. 04. 15..
//

#ifndef CLIONGRAPHICSKIT_STEPPER_HPP
#define CLIONGRAPHICSKIT_STEPPER_HPP
#include "widgets.hpp"
#include "graphics.hpp"
using namespace genv;

class Stepper : public Widget {
protected:
    int _ertek = 0;
    int _max;
    int _min;

public:
    Stepper(int x, int y, int x_meret, int y_meret, int min, int max);
    virtual void rajzol() override;
    virtual void kezel(event ev) override;
    virtual int get_ertek() const { return _ertek; }

};


#endif //CLIONGRAPHICSKIT_STEPPER_HPP