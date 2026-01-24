#include "compito.h"

Anfiteatro::Anfiteatro(const int k){
    head = nullptr;

    for (int i = k; i > 0; --i){
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