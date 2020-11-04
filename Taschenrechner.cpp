#include"Taschenrechner.h"
#include <iostream>
#include <cmath>

using namespace std;

char Taschenrechner::peekZeichen()
{
    if (rechnung.empty())
    {
        return ' ';
    }
    if (rechnung.at(0) != ' ')
    {
        return rechnung.at(0);
    }
    else
    {
        rechnung = rechnung.substr(1);
        return peekZeichen();
    }
}

char Taschenrechner::leseZeichen()
{
    char c = peekZeichen();
    if(c != ' '){
        rechnung = rechnung.substr(1);
    }
    return c;
}

int Taschenrechner::leseZahl()
{
    string value;
    while (peekZeichen() >= '0' && peekZeichen() <= '9')
    {
        value += leseZeichen();
    }
    int out = 0;
    int multiply = 1;
    int number = stoi(value);
    while (number > 0){
        out += number % 10 * multiply;
        multiply *= 10;
        number /= 10;
    }     
    return out;
}

int Taschenrechner::leseFaktor(){
    int erg;
    char c = peekZeichen();
    if(c == '('){
        leseZeichen();
        erg = leseAusdruck();
        c = peekZeichen();
    }else{
        erg = leseZahl();
        return erg;
    }
    if(c == ')'){
        return erg;
    }
    throw "FEHLER: es wird ')' erwartet";
}

int Taschenrechner::leseSummand(){
    int erg = leseFaktor();
    char c = peekZeichen();
    while ( c == '*' || c == '/' ){
        if(c == '*'){
            leseZeichen();
            erg *= leseFaktor();
            c = peekZeichen();
        }else if(c == '/'){
            leseZeichen();
            erg /= leseFaktor();
            c = peekZeichen();
        }
    }
    return erg;
}

int Taschenrechner::leseAusdruck(){
    int erg = 0;
    char c = peekZeichen();
    if( c == '+'){
        leseZeichen();
        erg = leseSummand();
    }else if(c == '-'){
        leseZeichen();
        erg -= leseSummand();
    }else{
        erg = leseSummand();
    }
    c = peekZeichen();
    while ( c == '+' || c == '-' ){
        if(c == '+'){
            leseZeichen();
            erg += leseSummand();
            c = peekZeichen();
        }else if(c == '-'){
            leseZeichen();
            erg -= leseSummand();
            c = peekZeichen();
        }
    }
    return erg;
}

double Taschenrechner::getErgebnis(){
    return leseAusdruck();
}

string Taschenrechner::getAnfrage(){
    return anfrage;
}
