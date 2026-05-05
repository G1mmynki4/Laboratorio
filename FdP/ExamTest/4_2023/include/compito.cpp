#include "compito.h"
#include <cstring>

using namespace std;

//Funzioni di controllo / utilità
Log::ePriority Log::toEnum(const char c){
    switch (c)
    {
    case 'i':
        return ePriority::INFO;
        break;
    case 'w':
        return ePriority::WARN;
        break;
    case 'e':
        return ePriority::ERR;
        break;
    case 'c':
        return ePriority::CRIT;
        break;
    default:
        return ePriority::INVALID;
        break;
    }
}

char Log::toChar(const ePriority pr){
    switch (pr)
    {
    case INFO:
        return 'i';
        break;
    case WARN:
        return 'w';
        break;
    case ERR:
        return 'e';
        break;
    case CRIT:
        return 'c';
        break;
    default:
        return 'n';
        break;
    }
}

bool Log::isValidMsg(const char* msg){
    if(strlen(msg)>80 || strlen(msg) == 0)
        return false;
    return true;
}

bool Log::isValidDate(const Date d){
    if(d.yy>9999 || d.yy < 1970)
        return false;
    if(d.mm < 1 || d.mm >12)
        return false;
    if(d.dd < 1 || d.dd > 31)
        return false;
    return true;
}

bool Log::isValidTime(const Time t){
    if(t.hour < 0 || t.hour > 23)
        return false;
    if(t.min < 0 || t.min > 59)
        return false;
    return true;
}

int Log::compare(const Date a, const Date b, const Time a_t, const Time b_t){
    if(a.yy > b.yy)
        return 1;
    if(a.yy < b.yy)
        return -1;
    //Confronto mese
    if(a.mm > b.mm)
        return 1;
    if(a.mm < b.mm)
        return -1;
    //Confronto giorno
    if(a.dd > b.dd)
        return 1;
    if(a.dd < b.dd)
        return -1;
    //Confronto Time
    if(a_t.hour > b_t.hour)
        return 1;
    if(a_t.hour < b_t.hour)
        return -1;
    if(a_t.min > b_t.min)
        return 1;
    if(a_t.min < b_t.min)
        return -1;
    return 0;
}

void Log::printDate(ostream& os, const int value){
    if(value < 10)
        os << "0" << value;
    else
        os << value;
}

//Prima Parte
Log::Log(){
    head = nullptr;
}

void Log::registra(const char prio, const Date date, const Time time, const char msg[]){
    Event *newEv = new Event;

    if(!isValidDate(date) || !isValidTime(time) || !isValidMsg(msg) || toEnum(prio) == INVALID)
        return;
    
    newEv->prio = toEnum(prio);
    newEv->date = date;
    newEv->time = time;
    strcpy(newEv->msg, msg);

    if(strcmp(msg, "(cancellato)") == 0)
        newEv->IsDeleted = true;

    Event *cur, *tmp;

    for (cur = head; cur != nullptr && compare(cur->date, date, cur->time, time) <= 0; cur = cur->next)
        tmp = cur;
    
    if(cur == head){
        head = newEv;
        newEv->next = cur;
    }
    else{
        tmp->next = newEv;
        newEv->next = cur;  
    }
}

void Log::cancella(const char* msg){
    Event *tmp;

    for (tmp = head; tmp != nullptr && (tmp->IsDeleted || strcmp(tmp->msg, msg)); tmp = tmp->next);
    if(tmp == nullptr)
        return;
    tmp->IsDeleted = true;
}

ostream& operator<<(ostream& os, const Log& l){
    os << "--- LOG ---" << endl;
    for (Log::Event *e = l.head; e != nullptr; e = e->next){
        switch (e->prio)
        {
        case Log::ePriority::INFO:
            os << "INFO, ";
            break;
        case Log::ePriority::WARN:
            os << "WARN, ";
            break;
        case Log::ePriority::ERR:
            os << "ERRO, ";
            break;
        case Log::ePriority::CRIT:
            os << "CRIT, ";
            break;
        }
        os << e->date.yy<<"-";
        Log::printDate(os, e->date.mm);
        os << "-";
        Log::printDate(os, e->date.dd);
        os << ",";
        Log::printDate(os, e->time.hour);
        os << ":";
        Log::printDate(os, e->time.min);
        os << ",";
        if(e->IsDeleted)
            os << " (cancellato)" << endl;
        else
            os <<" "<< e->msg << endl;
    }
    os << "--- FINE LOG ---" << endl;
    return os;
}

//Seconda Parte
Log::~Log(){
    Event *toDel;
    while(head != nullptr){
        toDel = head;
        head = head->next;
        delete toDel;
    }
}

void Log::cancella(const Date da_data, const Time da_ora, const Date a_data, const Time a_ora){
    Event *tmp;
    for (tmp = head; tmp != nullptr; tmp = tmp->next)
        if(compare(da_data, tmp->date, da_ora, tmp->time)<=0 &&
           compare(a_data, tmp->date, a_ora, tmp->time)>=0){
            strcpy(tmp->msg, "(cancellato)");
            tmp->IsDeleted = true;
        }
}

Log* Log::filtra(const char prio){
    ePriority pr = toEnum(prio);
    if(pr==INVALID)
        return nullptr;

    Log *filter = new Log;
    Event *tmp;

    for (tmp = head; tmp != nullptr; tmp = tmp->next){
        if(!tmp->IsDeleted && tmp->prio == pr){
            filter->registra(tmp->prio, tmp->date, tmp->time, tmp->msg);
        }
    }
    return filter;
}

Log* Log::biforca(const Date data, const Time ora, const Log& l2){
    Log* bif = new Log;

    Event *newHead = l2.head;
    Event *tmp;

    for (tmp = head; tmp != nullptr; tmp = tmp->next){
        if(compare(tmp->date, data, tmp->time, ora)<=0){
            bif->registra(toChar(tmp->prio), tmp->date, tmp->time, tmp->msg);
        }
    }

    for (tmp = newHead; tmp != nullptr; tmp = tmp->next){
        if(compare(tmp->date, data, tmp->time, ora) > 0)
            bif->registra(toChar(tmp->prio), tmp->date, tmp->time, tmp->msg);
    }

    return bif;
}