#include "graphics.hpp"
#include <fstream>

#include "Jatekmester.hpp"

using namespace genv;
using namespace std;

int main() {
    gout.open(440, 600);
    gout << font("LiberationSans-Regular.ttf", 20);
    gout << refresh;

    event ev;
    JatekMester jatek;

    jatek.rajzol();
    gout << refresh;

    while (gin >> ev) {
        jatek.kezel(ev);
        gout << move_to(0, 0) << color(0,0,0) << box(440, 600);
        jatek.rajzol();
        gout << refresh;
        if (ev.type == ev_key && ev.keycode == 'r') {
            jatek.reset();
        }
    }
    return 0;
}
