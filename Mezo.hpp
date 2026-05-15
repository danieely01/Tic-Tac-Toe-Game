//
// Created by danie on 2026. 05. 13..
//

#ifndef CLIONGRAPHICSKIT_MEZO_HPP
#define CLIONGRAPHICSKIT_MEZO_HPP
#include <functional>
#include "widgets.hpp"
using namespace std;


class Mezo : public Widget {
protected:
    int _allapot;
    function<void()> _kattintas_akcio;


public:
    Mezo(int x, int y, int meret, function<void()> akcio);

    virtual void rajzol() override;
    virtual void kezel(genv::event ev) override;

    //getterek setterek
    int get_allapot() const;
    void set_allapot(int uj_allapot);
};

#endif //CLIONGRAPHICSKIT_MEZO_HPP