#include <iostream>

using namespace std;

int main() {
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

    return 0;
}