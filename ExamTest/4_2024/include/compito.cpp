#include "compito.h"
#include <cstring>

//Prima Parte
OggettiViaggio::OggettiViaggio(){
    head = nullptr;
}

//Copy constructor
OggettiViaggio::OggettiViaggio(const OggettiViaggio& ov){

    Object *tmpHead = nullptr;
    this->head = nullptr;

    for (tmpHead = ov.head; tmpHead != nullptr; tmpHead = tmpHead->next){
        this->aggiungi(tmpHead->descr);

        if(tmpHead->isTaken)
            this->prendi(tmpHead->descr);
    }

}

ostream& operator<<(ostream& os, const OggettiViaggio& Ov){
    OggettiViaggio::Object *tmp = Ov.head;

    while (tmp){
        if(!tmp->isTaken)
            os << "- ";
        else
            os << "X ";
        os << tmp->descr << endl;
        tmp = tmp->next;
    }

    return os;
}

void OggettiViaggio::aggiungi(const char* descr){
    if (strlen(descr) > MAX_L || strlen(descr) == 0)
        return;

    Object *toAdd = new Object;

    strcpy(toAdd->descr, descr);
    toAdd->isTaken = false;
    toAdd->next = nullptr;

    if(head == nullptr)
        head = toAdd;
    else{

        Object *tmp, *cur;

        for (tmp = head; tmp != nullptr; tmp = tmp->next){
            if(strcmp(tmp->descr, descr) == 0){
                delete toAdd;
                return;
            }

            cur = tmp;
        }
        cur->next = toAdd;
    }
}

void OggettiViaggio::prendi(const char* descr){
    if (strlen(descr) > MAX_L || strlen(descr) == 0)
        return;

    Object *tmp, *cur = nullptr;

    for (tmp = head; tmp != nullptr; tmp = tmp->next){
        if(strcmp(tmp->descr, descr) == 0)
            cur = tmp;
    }

    if(cur != nullptr)
        cur->isTaken = true;
    else
        return;
}

void OggettiViaggio::viaggia(){
    Object *tmp = head;

    while(tmp){
        if(tmp->isTaken)
            tmp->isTaken = false;

        tmp = tmp->next;
    }
}

//Seconda Parte
OggettiViaggio::~OggettiViaggio(){
    Object *cur;

    while(head){
        cur = head;
        head = head->next;
        delete cur;
    }
}

void OggettiViaggio::rimuovi(const char* descr){
    if (strlen(descr) > MAX_L || strlen(descr) == 0)
        return;

    Object *tmp = head, *cur;

    if(strcmp(descr, tmp->descr) == 0){
        cur = head;
        head = head->next;
        delete cur;
    }

    for (tmp = head; tmp != nullptr; tmp = tmp->next){
        
        if(tmp->next != nullptr && strcmp(tmp->next->descr, descr) == 0){
            cur = tmp->next;
            tmp->next = cur->next;
            delete cur;
            break;
        }

    }
}

OggettiViaggio& OggettiViaggio::operator+=(const OggettiViaggio& ov2){
    Object *tmpHead = nullptr;

    for (tmpHead = ov2.head; tmpHead != nullptr; tmpHead = tmpHead->next){
        this->aggiungi(tmpHead->descr);

        if(tmpHead->isTaken)
            this->prendi(tmpHead->descr);
    }

    return *this;
}

OggettiViaggio OggettiViaggio::operator!()const {
    OggettiViaggio ov2;

    Object *tmp = nullptr;

    for (tmp = head; tmp != nullptr; tmp = tmp->next)
        if(!tmp->isTaken)
            ov2.aggiungi(tmp->descr);

    return ov2;
}