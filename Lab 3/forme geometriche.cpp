#include <iostream>
using namespace std;


void triangolo_rettangolo(){
    int n;

    cout<<"Inserisci un numero > 0\n";
    cin>>n;

    if (n>0) {
        cout<<"Stampo triangolo\n";
        for (int i=0; i<n; i++) {
            for (int j=0; j<=i; j++) {
                cout<<"* ";
            }
            cout<<endl;
        }
        cout<<"Stampo triangolo rovesciato\n";
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (j < i) {
                    cout<<"  ";
                }else
                    cout<<"* ";
            }
            cout<<endl;
        }

    }
}

void triangolo_isoscele(){
    int n;

    // Lettura di n con controllo
    cout << "Inserisci un numero intero positivo dispari: ";
    cin >> n;

    if (n <= 0 || n % 2 == 0) {
        cout << "Errore: il numero deve essere positivo e dispari." << endl;
        return;
    }

    cout << "Triangolo isoscele rovesciato\n";

    // Parte 1: triangolo isoscele rovesciato
    for (int i = 0; i < n; i += 2) {
        // Spazi prima delle stelle
        for (int s = 0; s < i / 2; s++)
            cout << "  ";
        // Stelle
        for (int j = 0; j < n - i; j++)
            cout << "* ";
        cout << endl;
    }

    cout << "Triangolo isoscele ruotato verso destra\n";

    for (int i = 0; i < (n/2)+1; i++){
        for (int j = 0; j <= i; j++){
            cout << "* ";
        }
        cout << endl;
    }
    
    for (int i = (n/2)+1; i < n; i++){
        for (int j = 0; j < n-i; j++){
            cout << "* ";
        }
        cout << endl;
    }
}

void quadrato(){
        int n = 0, r = 0, c = 0;

    cout << "Inserisci un numero naturale\n";
    cin >> n;

    if(n>1){

        cout << "Stampo quadrato pieno di n righe e n colonne\n";
        while(c<n){
            while(r<n){
                cout << "* ";
                r++;
            }
            c++;
            cout << "\n";
            r = 0;
        }
        c = 0;
        r = 0;

        cout << "Stampo quadrato vuoto di n righe e n colonne\n";
        while(c<n){
            while(r<n){
                if(c==0||c==n-1||r==0||r==n-1)
                    cout << "* ";
                else
                    cout << "  ";
                r++;
            }
            c++;
            cout << "\n";
            r = 0;
        }

    }
}

int main(){
    int opz;

    cout << "\n----Menu opzioni grafiche----\n"<< "Seleziona un opzione\n";
    cout << "1: Stampa Triangolo rettangolo\n2: Stampa Triangolo isoscele\n3: Stampa quadrato\n";
    cin >> opz;

    switch (opz)
    {
    case 1:
        triangolo_rettangolo();
        break;
    case 2:
        triangolo_isoscele();
        break;
    case 3:
        quadrato();
        break;

    default:
        cout<<"Opzione non valida.\n----Uscita dal programma----\n";
        break;
    }
    return 0;
}