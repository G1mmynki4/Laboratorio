#include "compito.h"

//
Anfiteatro::Anfiteatro(const int k){
    head = nullptr;
    int ncol = k;
    if( k <= 0)
        ncol = 3;

    for (int i = ncol; i > 0; --i){
        Cols *toAdd = new Cols;
        toAdd->nRows = 0;
        toAdd->next = nullptr;

        if(head == nullptr)
            head = toAdd;
        else{
            auto tmp = head;
            while(tmp->next){
                tmp = tmp->next;
            }
            tmp->next = toAdd;
        }
    }

}

void Anfiteatro::aggiungiMattonelle(const int k){
    if(k == 0)
        return;

    Cols* tmp;
    int nCol = 0, nMin = 0;

    for (tmp = head; tmp->next != nullptr; tmp = tmp->next){
        nCol = tmp->nRows;

        if(nCol < nMin)
            nMin = nCol;
    }

    for (tmp = head; tmp != nullptr; tmp = tmp->next)
        if(tmp->nRows == nMin){
            tmp->nRows += k;
            break;
        }
}

void Anfiteatro::aggiungiColonna(const int k){
    if(k <= 0)
        return;
        
    Cols *toAdd = new Cols;
    toAdd->nRows = k;
    toAdd->next = nullptr;

    if(head == nullptr)
        head = toAdd;
    else{
        auto tmp = head;
        while(tmp->next){
            tmp = tmp->next;
        }
        tmp->next = toAdd;
    }
}

ostream& operator<<(ostream& os, const Anfiteatro& Af){
    Anfiteatro::Cols *tmp = Af.head;
    os << "< ";

    while(tmp){
        os << "[" << tmp->nRows << "]";

        if(tmp->next != nullptr)
            os << ", ";
        else
            os << ">" << endl;

        tmp = tmp->next;
    }
    

    return os;
}

//Seconda Parte
Anfiteatro::~Anfiteatro(){
    Cols *toDel;

    while(head){
        toDel = head;
        head = head->next;
        delete toDel;
    }
}

void Anfiteatro::togliColonna(const int j){
    if( j == 0 || head == nullptr)
        return;

    Cols *tmp = nullptr, *cur = nullptr;

    if( j == 1 ){
        tmp = head;
        head = head->next;
        delete tmp;
        return;
    }

    tmp = head;
    for (int i = 0; i < j-1; ++i){
        if (tmp != nullptr){
            cur = tmp;
            tmp = tmp->next;
        }
    }

    cur->next = tmp->next;
    delete tmp;
}

Anfiteatro& Anfiteatro::operator=(const Anfiteatro& At){
    if(At.head == nullptr)
        return *this;

    while(head)
        togliColonna(1);

    Cols *tmp = nullptr;
    for (tmp = At.head; tmp != nullptr; tmp = tmp->next)
        aggiungiColonna(tmp->nRows);

    return *this;
}