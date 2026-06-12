# Amőba (Gomoku) - C++ Grafikus Alkalmazás

Egyetemi beadandó projekt, amely a klasszikus Amőba (Gomoku) játékot valósítja meg egy 15x15-ös játéktéren. Az alkalmazás C++ nyelven készült, fókuszban az objektumorientált tervezéssel (OOP), a dinamikus memóriakezeléssel, valamint az eseményvezérelt programozással.

## Főbb funkciók
* **Grafikus felület:** A játék a `genv` (Graphics Environment) grafikus könyvtárat használja a megjelenítéshez (440x600-as ablak).
* **15x15-ös játéktér:** Két játékos (X és O) váltott körös játéka.
* **Automatikus győzelem-ellenőrzés:** A rendszer minden lépés után mind a négy irányban (vízszintes, függőleges, átlók) ellenőrzi, hogy kigyűlt-e az 5 egyforma jel.
* **Játékmenet vezérlés:** * Érvénytelen lépések (már foglalt mező) szűrése.
  * Játék vége üzenet és a győztes kihirdetése.
  * A játék bármikor újraindítható az `r` billentyű megnyomásával.

## Technológiai háttér és Architektúra

A kód moduláris felépítésű, az egyes felelősségi körök külön osztályokba lettek kiszervezve.

* **OOP és Öröklődés:** * A felhasználói felület elemei egy alap `Widget` osztályból származnak.
  * A `Mezo` osztály (amely a `Widget`-ből öröklődik) felel a saját állapota (üres, X, O) tárolásáért, kirajzolásáért és az egéresemények lekezeléséért.
* **Modern C++ eszközök:** A mezők kattintásakor lefutó események (callbackek) `std::function` és **lambda kifejezések** segítségével kommunikálnak a fő játékvezérlővel.
* **Dinamikus memóriakezelés és Mutatók:** * A játéktér egy kétdimenziós vektor (`std::vector<std::vector<Mezo*>>`), amely dinamikusan foglalt mutatókat tartalmaz. 
  * A játékmester (`JatekMester`) felel a mezők inicializálásáért a Heap-en.

## Fájlszerkezet
* `main.cpp` - A program belépési pontja, az ablak inicializálása és a fő eseményhurok (event loop).
* `Jatekmester.hpp / .cpp` - A játék fő logikája, a játéktér (mátrix) kezelése, lépések validálása és a győzelem ellenőrzése.
* `mezo.hpp / .cpp` - A cellák vizuális megjelenítése és a kattintások (bal egérgomb) lokális kezelése.
* `widgets.hpp / .cpp` - Ősosztály a grafikus elemekhez.

## Fordítás és Futtatás
A projekt fordításához szükséges a `genv` grafikus könyvtár megléte és linkelése. 
A fordítás során a szabványos C++11 (vagy újabb) verzió használata javasolt a lambda kifejezések miatt.

---
*Készült a PPKE ITK mérnökinformatikus képzése keretében.*
