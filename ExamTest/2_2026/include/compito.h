//
// Created by SI1 on 26/01/2026.
//

#ifndef COMPITO_H
#define COMPITO_H
#include <iostream>
using namespace std;

enum Stato {
    MODIFICA,
    AVVIATO,
    VINTO,
    PERSO

};

class TiltMaze {
    char** Maze;
    int nRow;
    int nCol;

    int rStart;
    int cStart;
    int rExit;
    int cExit;

    int rBall;  //added also in avvia() and copy constr
    int cBall;  //added also in avvia() and copy constr

    Stato gameState;
    const char* toChar(const Stato) const;
public:
    TiltMaze(int, int, int, int, int, int);
    bool aggiungiMuro(const int, const int, const int, const int);
    bool aggiungiBuca(const int, const int);
    void avvia();
    friend ostream& operator<<(ostream&, const TiltMaze&);
    Stato stato()const;

    ~TiltMaze();
    TiltMaze(const TiltMaze&);
    void inclina(const int, const int);
    //added later
    friend TiltMaze operator+(const TiltMaze& t1, const TiltMaze& t2);
};



#endif //COMPITO_H

// fine file