#include "compito.h"
#include <cstring>

//Prima Parte
OggettiViaggio::OggettiViaggio(){
    head = nullptr;
}

//Copy constructor
OggettiViaggio::OggettiViaggio(const OggettiViaggio& ov){

    Objects *tmpHead = nullptr;
    this->head = nullptr;
    
    for (tmpHead = ov.head; tmpHead != nullptr; tmpHead = tmpHead->next){
        this->aggiungi(tmpHead->descr);

        if(tmpHead->isTaken)
            this->prendi(tmpHead->descr);
    }

}

ostream& operator<<(ostream& os, const OggettiViaggio& Ov){
    OggettiViaggio::Objects *tmp = Ov.head;

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

    Objects *toAdd = new Objects;

    strcpy(toAdd->descr, descr);
    toAdd->isTaken = false;
    toAdd->next = nullptr;

    if(head == nullptr)
        head = toAdd;
    else{

        Objects *tmp, *cur;

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

    Objects *tmp, *cur = nullptr;

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
    Objects *tmp = head;

    while(tmp){
        if(tmp->isTaken)
            tmp->isTaken = false;

        tmp = tmp->next;
    }
}
