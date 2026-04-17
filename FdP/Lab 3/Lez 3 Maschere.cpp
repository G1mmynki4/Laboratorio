#include <iostream>

using namespace std;

int main() {
    int hex1 = 0x0, hex2 = 0x0;
    unsigned int i;
    unsigned short int M1 = 1, val1, val2;

    cout << "Inserisci un valore (0-15)\n";
    cin >> i;

    if(i<16){
        val1 = M1 << i;
        val2 = ~(M1 << i);

        cout << "\nValore decimale della maschera M1: " << val1 << endl;
        cout << hex;        //da ora in poi stampa valori in forma esadecimale

        cout << "\nValore esadecimale della maschera M1: " << val1 << endl;
        cout << dec;        //da ora in poi ritorna a stampare valori in forma decimale (default)

        cout << "\nValore decimale della maschera M2: " << val2 << endl;
        cout << hex;

        cout << "\nValore esadecimale della maschera M1: " << val2 << endl;
        cout << dec;
    } else
        cout << "Numero non valido\n";

    return 0;
}