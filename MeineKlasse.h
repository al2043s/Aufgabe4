#ifndef MeineKlasse_H
#define MeineKlasse_H

class MeineKlasse {
    public:
        MeineKlasse();
        const int& readonlyAttribut;
        void aendern(int a);

    private: 
        int attribut;
};

inline MeineKlasse::MeineKlasse() : attribut(0), readonlyAttribut(attribut) {}

#endif