//
// Created by SI1 on 26/01/2026.
//

#include "compito.h"

const char* TiltMaze::toChar(Stato st) const {
    switch (st) {
        case MODIFICA:
            return "MODIFICA";
            break;
        case AVVIATO:
            return "AVVIATO";
            break;
        case VINTO:
            return "VINTO";
        case PERSO:
            return "PERSO";
    }
    return nullptr;
}

TiltMaze::TiltMaze(int R, int C, int rSt, int cSt, int rEx, int cEx) {
    if (R < 0 || C < 0) {
        R = 3;
        C = 3;
    }
    nRow = R-1;
    nCol = C-1;

    gameState = MODIFICA;
    Maze = new char*[R];
    for (int i = 0; i < R; i++) {
        Maze[i] = new char[C];
    }
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            Maze[i][j] = '.';
        }
    }
    rStart = rSt;
    rExit = rEx;
    cStart = cSt;
    cExit = cEx;

    if (rSt < 0)
        rStart = 0;
    if (rEx < 0)
        rExit = 0;
    if (rSt > R-1)
        rStart = R - 1;
    if (rEx > R-1)
        rExit = R - 1;
    if (cSt < 0)
        cStart = 0;
    if (cEx < 0)
        cExit = 0;
    if (cSt > C-1)
        cStart = C - 1;
    if (cEx > C-1)
        cExit = C - 1;

    Maze[rStart][cStart] = 'S';
    Maze[rExit][cExit] = 'E';

}

bool TiltMaze::aggiungiMuro(const int r1, const int c1, const int r2, const int c2) {
    if (gameState!=MODIFICA)
        return false;
    if (r2 < r1 || c2 < c1)
        return false;
    if (r1!=r2 && c1!=c2)
        return false;

    if (r1 == rStart && c1 == cStart)
        return false;

    if (r2 == rStart && c2 >= rExit)
        return false;

    if (r1 == r2) {
        for (int i = c1; i <= c2; i++)
            Maze[r1][i] = '#';
        return true;
    }

    for (int i = r1; i <= r2; i++)
        Maze[i][c1] = '#';
    return true;

}

bool TiltMaze::aggiungiBuca(const int r, const int c) {
    if (gameState!=MODIFICA)
        return false;
    if (r == rStart && c == cStart)
        return false;
    if (r == rExit && c == cExit)
        return false;

    if (Maze[r][c] == '#' || Maze[r][c] == '.') {
        Maze[r][c] = 'O';
        return true;
    }
    return false;
}

void TiltMaze::avvia() {
    //Maze[rStart][cStart] = 'x'; //to delete
    rBall = rStart;               //add
    cBall = cStart;               //add
    gameState = AVVIATO;
}

ostream& operator<<(ostream& os, const TiltMaze& t) {
    os<<"Stato: "<<t.toChar(t.gameState)<<endl;

    for (int i = t.nRow; i >= 0 ; i--) {
        os<<i<<" ";
        for (int j = 0; j <=t.nCol; j++) {
            //if (t.Maze[i][j] == 'x' && t.gameState == AVVIATO)  //cambiata da X a x
            //    os<<"x"<<" ";                                   //cambiata da X a x
            if (t.gameState == AVVIATO && i == t.rBall && j == t.cBall) {   //added
                os<<"x"<<" ";
            }                                                               //stop
            else
                if (t.Maze[i][j] == 'S')
                    os<<"S"<<" ";
                else
                    os<<t.Maze[i][j]<<" ";
        }
        os<<endl;
    }
    os<<"  ";
    for (int j = 0; j <=t.nCol; j++)
        os<<j<<" ";
    os<<endl;
    return os;
}

Stato TiltMaze::stato() const {
    return gameState;
}

//Seconda parte
TiltMaze::~TiltMaze() {
    for (int i = 0; i < nRow; i++) {
        delete[] Maze[i];
    }
    delete[] Maze;
}

TiltMaze::TiltMaze(const TiltMaze & t) {
    nRow = t.nRow;
    nCol = t.nCol;
    gameState = MODIFICA;
    rStart = t.rStart;
    rExit = t.rExit;

    cStart = t.cStart;  //added
    cExit = t.cExit;    //added

    Maze = new char*[nRow+1];
    for (int i = 0; i < nRow+1; i++) {
        Maze[i] = new char[nCol-1];
    }

    for (int i = 0; i < nRow+1; i++) {
        for (int j = 0; j < nCol+1; j++) {
            if (t.Maze[i][j] == 'x')        //cambiata da X a x
                Maze[i][j] = '.';
            else
                Maze[i][j] = t.Maze[i][j];
        }
    }

    Maze[rStart][cStart] = 'S';
    Maze[rExit][cExit] = 'E';
}

//void TiltMaze::inclina(const int dirV, const int dirH) {
//    if (dirV == 0 && dirH == 0)
//        return;
//    if (dirV != 0 && dirH == 0)
//        return;
//    if (dirV == 0 && dirH != 0)
//        return;
//
//
//
//}

void TiltMaze::inclina(const int dirV, const int dirH) {
    // 1. Controlli preliminari
    if (gameState != AVVIATO) 
        return;
    
    // Deve esserci una sola direzione attiva (XOR logico o controllo esplicito)
    // Se entrambi 0 o entrambi diversi da 0, non fa nulla
    if ((dirV == 0 && dirH == 0) || (dirV != 0 && dirH != 0)) 
        return;

    // 2. Ciclo di movimento (Fisica)
    while (true) {
        int nextR = rBall + dirV;
        int nextC = cBall + dirH;

        // A. Controllo Bordi
        if (nextR < 0 || nextR > nRow || nextC < 0 || nextC > nCol) {
            break; // Sbatte contro il bordo del quadro
        }

        // B. Controllo Muri
        if (Maze[nextR][nextC] == '#') {
            break; // Sbatte contro un muro
        }

        // Se non è muro e non è bordo, la pallina entra nella cella
        rBall = nextR;
        cBall = nextC;

        // C. Controllo Buca (La pallina cade DOPO essere entrata)
        if (Maze[rBall][cBall] == 'O') {
            gameState = PERSO;
            // Nota: rBall/cBall rimangono sulla buca, ma nel disegno non verrà stampata la 'x' 
            // perché nel operator<< stamperemo 'x' solo se AVVIATO (o modifichiamo operator<< per VINTO/PERSO)
            // Secondo il testo: "sparisce dalla griglia".
            break;
        }

        // D. Controllo Uscita
        if (Maze[rBall][cBall] == 'E') {
            gameState = VINTO;
            break;
        }
        
        // Se è '.' o 'S', il ciclo continua e la pallina scivola ancora
    }
    
}



TiltMaze operator+(const TiltMaze& t1, const TiltMaze& t2) {
    // 1. Controllo compatibilità righe
    if (t1.nRow != t2.nRow) {
        return TiltMaze(t1); // Restituisce una copia di t1 se le righe non coincidono
    }

    // 2. Calcolo nuove dimensioni
    // Ricorda: nRow/nCol sono indici massimi, quindi la dimensione reale è +1
    int rows = t1.nRow + 1;
    int cols1 = t1.nCol + 1;
    int cols2 = t2.nCol + 1;
    
    // Il nuovo Exit sarà quello di t2, traslato orizzontalmente di cols1
    int newRExit = t2.rExit;
    int newCExit = t2.cExit + cols1;

    // 3. Creazione nuovo oggetto (Start di t1, Exit di t2 traslato)
    TiltMaze result(rows, cols1 + cols2, t1.rStart, t1.cStart, newRExit, newCExit);

    // 4. Copia del labirinto t1 (Parte Sinistra)
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols1; j++) {
            char c = t1.Maze[i][j];
            // Il vecchio punto di Exit di t1 non è più speciale, diventa vuoto
            if (c == 'E') 
                result.Maze[i][j] = '.'; 
            else 
                result.Maze[i][j] = c;
        }
    }

    // 5. Copia del labirinto t2 (Parte Destra)
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols2; j++) {
            char c = t2.Maze[i][j];
            // Il vecchio punto di Start di t2 non è più speciale, diventa vuoto
            if (c == 'S') 
                result.Maze[i][j + cols1] = '.'; 
            else 
                result.Maze[i][j + cols1] = c;
        }
    }
    
    // Assicuriamoci che i nuovi S ed E siano scritti correttamente sulla matrice
    // (Il costruttore lo fa, ma noi abbiamo sovrascritto copiando i char da t1 e t2)
    result.Maze[result.rStart][result.cStart] = 'S';
    result.Maze[result.rExit][result.cExit] = 'E';

    // Il risultato è in stato MODIFICA di default (dal costruttore)
    return result;
    
}
// fine file