#ifndef Taschenrechner_H
#define Taschenrechner_H

#include<string>

using namespace std;

class Taschenrechner {
    public: 
        Taschenrechner();
        Taschenrechner(string anfrage);
        string getAnfrage();
        double getErgebnis();

    private:
        int leseFaktor();
        int leseSummand();
        int leseAusdruck();
        char peekZeichen();
        char leseZeichen();
        int leseZahl();
        string rechnung;
        string anfrage;


};

inline Taschenrechner::Taschenrechner() : rechnung(""), anfrage("") {}
inline Taschenrechner::Taschenrechner(string anfrage) : rechnung(anfrage), anfrage(anfrage) {}


#endif
