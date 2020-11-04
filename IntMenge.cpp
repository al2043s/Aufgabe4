#include"IntMenge.h"
#include<iostream>

using namespace std;

void IntMenge::hinzufuegen(int el){
    if(!istMitglied(el)){
        v.push_back(el);
    }
}



void IntMenge::entfernen(int el){
    if(istMitglied(el)){
        for(size_t i = 0; i <= v.size(); i++ ){
            if(v.at(i) == el){
                v.erase(v.begin() + i);
            }
        }
    }
}

bool IntMenge::istMitglied(int el){
    for(int i : v){
         if( i == el){
             return true;
        }
    }
    return false;
}

size_t IntMenge::size(){
    return v.size();
}

void IntMenge::anzeigen(){
    for(int i : v){
        cout << i << endl;
    }
}

void IntMenge::loeschen(){
    v.clear();
}

int IntMenge::getMax(){
    int max = v.at(0); 
    for(int i : v){
        if(i > max){
            max = i;
        }
    }
    return max;
}

int IntMenge::getMin(){
    int min = v.at(0);
    for(int i : v){
        if(i < min){
            min = i;
        }
    }
    return min;
}