union numero {
  int i;
  double d;
};
numero num; // dichiarazione union (uguale a struct)

// union anonima uguale alla dichiarazione delle struct
union {
  int i;
  double d;
}n ; // unico modo di dichiarare union senza identificatore (senza nome)

// approccio ibrido
union numeronuovo {
  int i;
  double d;
} ndue;

int main() {

  numero n;
  numero* ptr = &n;

  //accesso ai membri
  n.d;
  ptr->d; // ricordiamo essere zucchero sintattico (*ptr).d
  n.i = 4;

  //copia di un oggetto esistente

  numero s,m;
  s = m; // copia membro a membro come nelle struct

  //cosa cambia tra struct e union ?
  // le union iniziano dallo stesso indirizzo di memoria, sia i che d hanno le stesso indirizzo di memoria

  // mentre le struct allocano per ogni membro della memoria, le union condividono la memoria per tutti i membri

  //ad esempio se avessi un intero (4 byte) ed un float (8 byte) i primi 4 byte di entrambi i membri saranno condivisi

  union inf {
    unsigned n; // 4 byte
    float d;    // 4 byte     ---------> mi permette di avere gli stessi bit in memoria ma una interpretazione (casting) la prima ad un unsigned e la seconda ad un float
  };

  // se cambio il primo membro ovviamente starò cambiando anche il secondo perchè sono la stessa memoria

  // ovviamente per le struct l' ammontare di memoria è complessivo per le union solamente il numero maggiore dei byte tra i membri + un po' di padding(non verrà spiegato nel corso)

  union {int i; double d;} prova_anonima = {5}; // quello che verrà interpretato sarà uguale a (vedi riga sotto)
  // prova_anonima.i = 5; ovvero i parametri(in questo caso 5) verranno interpretati come il tipo del primo membro



  // -----------> casi d' uso delle union

  // 1. rispiarmare memoria ram in caso ci sia spazio
  // 2. manipolare il contenuto di un tipo di dato primitivo a basso livello di bit (indirettamente tramite il casting all altro valore)
  // ad esempio voglio avere una union che abbia 1. float 2. unsigned per poter utilizzare operatori bit a bit (con unsigend)

  // ha fatto un esempio in classe veloce negli ultimi 3 minuti dove ha fatto vedere un applicazione del punto 2 per fare il valore assoluto
  // (ha assegnato 2.5 tramite il membro float e poi fatto una maschera che "forzava" il primo bit a 1 (ovvero lo forzava a positivo))tramite lo stesso membro però come unsigned per rendere possibili le manipolazionoi bit a bit)




  // secondo argomento (fuori orario, ha sforato oltre le ore 15:30)
  // funzione che prende una lista e elimina tutte le occorrenze di una determinata informazione

  // elemnti della list
  struct elem {
    int inf;
    elem* pun;
  };

  // eliminare tutti i valori della lista che hanno come campo informativo il campo 4

  // ha suddiviso il caso in parti distinte

  // 1. rimozione deve avvenire in cima (fino a quando non elimino tutti i 4 dalla cima, (anche dopo la rimozione dopo la prima, potrebbe accadere che anche la seconda lo sia, ovvero la nuova testa))
  // in questo momento è previsto che la testa non si sposti più

  // 2. almeno 1 elemento con campo inf in 4 al centro dopo che è finita l' eliminazione in testa

}