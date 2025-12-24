#include <iostream>
#include<cstring>
#include "compito.h"

using namespace std;

LibreriaDigitale::LibreriaDigitale(){
    head = nullptr;
}

void LibreriaDigitale::aggiungiScaffale(char sname[], unsigned int capacity){

    if(strlen(sname)>=21)
        return;

    if(sname == "")
        return;
    
    if(capacity == 0)
        return;

    for (Scaffale *tmp = head; tmp != nullptr; tmp = tmp->next)
        if(strcmp(tmp->s_name, sname) == 0)
            return;

    Scaffale *tmp = nullptr, *current;
    for (current = head; current != nullptr; current = current->next)
        tmp = current;

    Scaffale *nuovo = new Scaffale;
    strcpy(nuovo->s_name, sname);
    nuovo->max = capacity;
    nuovo->nBook = 0;
    nuovo->ptr = nullptr;
    nuovo->next = nullptr;
    
    if(tmp != nullptr)
        tmp->next = nuovo;
    else
        head = nuovo;
}

bool LibreriaDigitale::aggiungiLibro(char nScaffale[], char bname[], bool isUsed){
    if(strlen(bname)>=31 || strlen(bname) == 0)
        return false;

    for (Scaffale *stmp = head; stmp != nullptr; stmp = stmp->next){

        if(strcmp(nScaffale, stmp->s_name) == 0 && stmp->nBook<stmp->max){

            Libri *btmp = nullptr, *current;
            for (current = stmp->ptr; current != nullptr; current = current->next){
                btmp = current;
                if(strcmp(btmp->b_name, bname) == 0)
                    return false;
            }
            
            Libri *nBook = new Libri;
            strcpy(nBook->b_name, bname);
            nBook->isUsed = isUsed;
            nBook->next = nullptr;

            for (current = stmp->ptr; current != nullptr; current = current->next)
                btmp = current;
            if(btmp != nullptr)
                btmp->next = nBook;
            else
                stmp->ptr = nBook;
            ++stmp->nBook;
            return true;
        }
    }
    return false;
}

ostream& operator<<(ostream &os, const LibreriaDigitale& ld){
    if(ld.head == nullptr)
        return os<<"vuota";

    for (Scaffale *current = ld.head; current != nullptr; current = current->next){
        os << "- Scaffale: " << current->s_name << endl;

        int count = 0;
        for (Libri *bCurr = current->ptr; bCurr != nullptr; bCurr = bCurr->next){
            os << "\t"<<count+1<<". '"<<bCurr->b_name << "' ("<<(bCurr->isUsed ? "Usato" : "Nuovo") << ")"<< endl;
            ++count;
        }
        os << "  Totale libri: " << count << "/" << current->max << endl;
    }
    return os;
}
