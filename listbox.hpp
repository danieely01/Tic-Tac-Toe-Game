//
// Created by danie on 2026. 04. 15..
//

#ifndef CLIONGRAPHICSKIT_LISTBOX_HPP
#define CLIONGRAPHICSKIT_LISTBOX_HPP
#include "widgets.hpp"

using namespace std;

class ListBox : public Widget {
protected:
    vector<string> _elemek;
    int _kivalasztott;
    int _gorgetes;
    int _sor_magassag;
    int lathato_darab;
public:
    ListBox(int x, int y, int x_merete, int y_merete, vector<string> elemek);
    virtual void rajzol() override;
    virtual void kezel(event ev) override;
    virtual string get_ertek() const;

};


#endif //CLIONGRAPHICSKIT_LISTBOX_HPP