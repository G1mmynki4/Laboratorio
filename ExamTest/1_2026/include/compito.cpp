#include <cstring>
#include "compito.h"

void CasaDiCura::initGuest(){
    Guest *newG = new Guest;

    newG->guestId = nGuests;
    newG->med = nullptr;
    newG->next = nullptr;

    if(head == nullptr)
        head = newG;
    else{
        Guest *cur = nullptr;

        for (Guest *tmp = head; tmp != nullptr; tmp = tmp->next)
            cur = tmp;

        cur->next = newG;
    }
    
}

//Prima parte
CasaDiCura::CasaDiCura(const char* name, int gNum){
    if(strlen(name) > CLEN)
        return;

    strcpy(cName, name);
    nGuests = 0;

    head = nullptr;
    for (int i = 0; i < gNum; ++i){
        ++nGuests;
        initGuest();
    }

}

ostream& operator<<(ostream& os, const CasaDiCura& cc){

    if(cc.head == nullptr)
        return os;
    
    os << "Casa di Cura '" << cc.cName << "'" << endl;

    CasaDiCura::Guest *tmp = cc.head;

    int i = 1;
    while(tmp != nullptr){
        CasaDiCura::Meds *mTmp = tmp->med;
        int nmed = 1;

        os << "- Ospite " << i << ":" << endl;
        while(mTmp!=nullptr){
            os << "  " << nmed << ". " << "'" << mTmp->mName << "'" << endl;

            if(mTmp->taken){
                os << "     Assunto" << endl;
                os << "     Ore " << mTmp->time << endl;
            }
            else
                os << "     Non assunto" << endl;

            nmed++;
            mTmp = mTmp->next;
        }

        os << endl;
        i++;
        tmp = tmp->next;
    }

    return os;
}

bool CasaDiCura::aggiungiFarmaco(int id, const char* medNm, int time){
    if(id < 0 || id > nGuests)
        return false;

    if(strlen(medNm) > MLEN)
        return false;

    if(time < 0 || time > 23)
        return false;

    Guest *tmp, *cur = nullptr;
    for (tmp = head; tmp != nullptr; tmp = tmp->next){
        if(tmp->guestId == id){
            cur = tmp;
            break;
        }
    }

    Meds *mtmp, *mcur;
    Meds *newMed = new Meds;

    strcpy(newMed->mName, medNm);
    newMed->time = time;
    newMed->taken = false;
    newMed->next = nullptr;

    if(cur->med == nullptr){
        cur->med = newMed;
        return true;
    }

    for (mtmp = cur->med; mtmp != nullptr; mtmp = mtmp->next){

        if(strcmp(mtmp->mName, medNm) == 0 || mtmp->time == time){
            delete newMed;
            return false;
        }
        mcur = mtmp;
    }

    mcur->next = newMed;
    
    return true;
}

bool CasaDiCura::assumiFarmaci(int id, int time){
    if(id < 0 || id > nGuests)
        return false;

    if(time < 0 || time > 23)
        return false;

    Guest *tmp;
    Meds *mTmp;

    for (tmp = head; tmp != nullptr; tmp = tmp->next){
        if(tmp->guestId == id){
            for (mTmp = tmp->med; mTmp != nullptr; mTmp = mTmp->next){
                if(mTmp->time == time && !mTmp->taken){
                    mTmp->taken = true;
                    return true;
                }
            }  
        }
    }

    return false;
}

//Seconda parte