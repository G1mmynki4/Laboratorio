#include "include/compito.h"

int main() {
    cout << "--- PRIMA PARTE ---" << endl;
	
    cout << "Test costruttore e aggiungiFarmaco" << endl;
    CasaDiCura cc("Giardino felice", 2);
    cc.aggiungiFarmaco(1, "Fluifort", 10);
    cc.aggiungiFarmaco(1, "Tachiflu", 24); // orario scorretto
    cc.aggiungiFarmaco(2, "Lasonil", 7);
    cc.aggiungiFarmaco(2, "Aulin", 11);
    cc.aggiungiFarmaco(2, "Tachipirina", 18);
    cout << endl << cc;
    
    cout << endl << "Test assumiFarmaci" << endl;
    cc.assumiFarmaci(2, 7);
    cc.assumiFarmaci(2, 18);
    cout << endl << cc;

    
	cout << endl << "--- SECONDA PARTE ---" << endl;
	
    cout << "Test costruttore di copia" << endl;
    CasaDiCura cc2(cc);
    cout << endl << cc2;
    
    cout << endl << "Test eventuale distruttore" << endl;
    {
        //CasaDiCura cc1("Prova", 1);
        CasaDiCura cc2(cc);
    }
    cout << "Distruttore chiamato" << endl;
    /*
    cout << endl << "Test rimuoviFarmaco" << endl;
    CasaDiCura cc3 = cc.rimuoviFarmaco(2, "Tachipirina");
    cout << endl << cc3;

    cout << endl << "Test operatore negazione" << endl;
    !cc;
    cout << endl << cc;


    cout << endl << "--- TERZA PARTE ---" << endl;

    CasaDiCura cc4("Casa Test", 3);
    cout << "Test casa iniziale:" << endl;
    cout << endl << cc4; //stampa una sequenza di tre ospiti, senza alcun farmaco

    bool b1 = cc4.aggiungiFarmaco(0, "Aspirina", 8);    // id ospite non valido
    bool b2 = cc4.aggiungiFarmaco(4, "Aspirina", 8);    // id ospite non valido
    cc4.aggiungiFarmaco(1, "", 8);                      // nome farmaco vuoto
    cc4.aggiungiFarmaco(1, "FarmacoMoltoLungoNome", 5); // nome troppo lungo (> MAX_NOME_FARMACO)
    cc4.aggiungiFarmaco(1, "Aspirina", -1);             // orario non valido
    cc4.aggiungiFarmaco(1, "Aspirina", 8);              // inserimento valido
    cc4.aggiungiFarmaco(1, "Aspirina", 9);              // duplicato, non inserito
    cc4.aggiungiFarmaco(1, "Augmentin", 8);             // stesso orario, non inserito

    cout << endl << "Dopo inserimenti su Casa Test" << endl;
    cout << endl << b1 << b2 << endl; // deve stampare 00
    cout << endl << cc4; //solo l'utente 1 ha farmaci, con un unico farmaco Aspirina per le 8

    bool b3 = cc4.assumiFarmaci(1, 7);  // nessun farmaco all'orario indicato
    cc4.assumiFarmaci(1, 8);  // assunzione corretta
    bool b4 = cc4.assumiFarmaci(1, 8);  // fallisce perchÃ© giÃ  assunto

    cout << endl << "Dopo chiamate a assumiFarmaci" << endl;
    cout << endl << b3 << b4 << endl; // deve stampare 00
    cout << endl << cc4; // solo l'utente 1 ha farmaci, con un unico farmaco Aspirina per le 8 assunto

    !!cc4;
    cout << endl << cc4; // solo l'utente 1 ha farmaci, con un unico farmaco Aspirina per le 8 assunto
    */
    return 0;
}