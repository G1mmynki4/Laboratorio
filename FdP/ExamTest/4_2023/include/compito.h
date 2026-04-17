#include<iostream>

class Log{
    static const int MAX_CHAR = 80;
    enum ePriority
    {
        INFO, // 0
        WARN, // 1
        ERR,  // 2
        CRIT, // 3
        INVALID //4
    };

    struct Date{
        int yy, mm, dd;
    };

    struct Time{
        int hour, min;
    };
    
    struct Event{
        char msg[MAX_CHAR + 1];
        bool IsDeleted = false;
        ePriority prio;
        Date date;
        Time time;
        Event *next;
    };

    Event* head;

    //Funzioni di controllo/utilità
    static ePriority toEnum(const char);
    static char toChar(const ePriority);
    static bool isValidMsg(const char*);
    static bool isValidDate(const Date);
    static bool isValidTime(const Time);
    static int compare(const Date, const Date, const Time, const Time);
    static void printDate(std::ostream &, const int);
    
public:
    //Prima parte
    Log();
    void registra(const char, const Date, const Time, const char*);
    void cancella(const char *);
    friend std::ostream &operator<<(std::ostream &, const Log &);

    //Seconda parte
    ~Log();
    void cancella(const Date, const Time, const Date, const Time);
    Log *filtra(const char);
    Log *biforca(const Date, const Time, const Log &);
};