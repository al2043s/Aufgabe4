#include "rational.h"
#include "iostream"

using namespace std;

int main(){
    Rational r = Rational(5,10);
    r.ausgabe();
    //so klappts
    r.add(Rational(5));
    r.ausgabe();
    //das gibt einen Fehler beim Linken
    //r.add(5);
    //r.ausgabe();

    return 0;
}