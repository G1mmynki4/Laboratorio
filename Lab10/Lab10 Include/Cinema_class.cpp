#include "Cinema_class.h"
#include <iostream>
#include <cstring>

using namespace std;
char c = 'A';

 Cinema::Cinema(int n, int p, char s[]) {

   strcpy(nome, s);
   matr = new bool[n*p];

   posti = p;
   ftot = n;

   for (int i=0; i<posti*ftot;++i)
     matr[i] = 0;


 }

bool Cinema::prenota(char l, int j) {
   int fila = l-'A';
   //cout<<endl;
   //cout<<"Fila prenota = "<<fila<<endl;

   if (!matr[posti*fila + (j-1)]) {
     matr[posti*fila + (j-1)] = 1;
     cout<<"Prenotato posto"<<posti*fila + (j-1)<<endl;
     return true;
   }
   return false;
 }


bool Cinema::cancella(char l, int j) {
   int fila = l-'A';
   //cout<<endl;
   //cout<<"Fila prenota = "<<fila<<endl;

   if (matr[posti*fila + (j-1)]) {
     matr[posti*fila + (j-1)] = 0;
     cout<<"Cancellato posto"<<posti*fila + (j-1)<<endl;
     return true;
   }
   return false;
 }

void Cinema::stampa() {

   cout<<"Nome del cinema: "<<nome<<endl;
   cout<<" ";

   for (int i = 0; i<posti; ++i)
     cout<<i+1;
   cout<<"\n";
   cout<<endl;
 }


