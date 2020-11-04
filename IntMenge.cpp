#include"IntMenge.h"
#include<iostream>

using namespace std;

void IntMenge::hinzufuegen(int el){
    if(!istMitglied(el)){
        v.push_back(el);
        std::cout << "ok" << endl;
    }else{
        std::cout << "keine Wirkung , " << el << " gibt es schon" << endl;
    }
}



void IntMenge::entfernen(int el){

}

bool IntMenge::istMitglied(int el){
    for(size_t i = 0; i < v.size(); i++){
        if (v.at(i) == el) {
            return true;
        }   
    }
    return false;
}

size_t IntMenge::size(){
    return v.size();
}

void IntMenge::anzeigen(){

}

void IntMenge::loeschen(){

}

int IntMenge::getMax(){
    int max; 

    return max;
}

int IntMenge::getMin(){
    int min;

    return min;
}