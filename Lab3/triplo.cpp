#include <iostream>
#include <cmath>

using namespace  std;

/*
int main() {
    int n;
    cout<<"Inserisci un numero intero\n";
    cin>>n;

    cout<<"Il triplo del numero inserito vale: "<<n*3<<endl;

    return 0;
}
*/

/*
int main() {
    int n1, n2;

    cout<<"Inserisci il primo numero\n";
    cin>>n1;
    cout<<"Inserisci il secondo numero\n";
    cin>>n2;

    cout<<n1<<" x "<<n2<<" = "<<n1*n2<<endl;
    return 0;
}
*/

//DIVISIONE CON RESTO
/*
int main() {
    int n1, n2;
    cout<<"Inserisci il dividendo\n";
    cin>>n1;

    cout<<"Inserisci il divisore\n";
    cin>>n2;

    cout<<"La parte intera del quoziente e': "<<n1/n2<<endl;
    cout<<"Il resto della divisione intera e': "<<n1%n2<<endl;

    return 0;
}
*/

//CALCOLO DELLA RETTA
/*
int main() {
    float m, x, q, y;

    cout<<"Inserisci il valore di M (coefficiente angolare)\n";
    cin>> m;

    cout<<"Inserisci il valore di X\n";
    cin>>x;

    cout<<"Inserisci il valore di Q (intercetta)\n";
    cin>>q;

    y= (m*x)+q;

    cout<<"Il valore dell'ordinata Y e': "<<y<<endl;

    return 0;
}
*/

//CALCOLO VALORE ASSOLUTO
/*
int main() {
    int n;
    cout<<"Inserisci un numero intero\n";
    cin>>n;

    if (n >= 0)
        cout<<"Il valore assoluto del numero inserito vale: "<<n<<endl;
    else
        cout<<"Il valore assoluto del numero inserito vale: "<<-n<<endl;

    return 0;
}
*/

//NUM POS NEG O ZERO
/*
int main() {
    int n;

    cout<<"Inserisci un numero\n";
    cin>>n;

    if (n > 0)
        cout<<"P\n";
    if (n < 0)
        cout<<"N\n";
    if (n == 0)
        cout<<"Z\n";

    return 0;
}
*/

//MULTIPLO DI 2 E 4
/*
int main() {
    int n;

    cout<<"Inserisci un numero\n";
    cin>>n;

    if ( n % 2 == 0 && n % 4 != 0)
        cout<<"Il numero e' multiplo di 2 ma non di 4\n";

    return 0;
}
*/

//MASSIMO TRA 3 NUMERI
/*
int main() {
    int n1, n2, n3;

    cout<<"Inserisci 3 interi: ";
    cin>>n1>>n2>>n3;

    if (n1>n2 && n1>n3)
        cout<<"Il massimo e': "<<n1<<endl;

    if (n2>n1 && n2>n3)
        cout<<"Il massimo e': "<<n2<<endl;

    if (n3>n1 && n3>n2)
        cout<<"Il massimo e': "<<n3<<endl;

    return 0;
}
*/


//EQUAZIONE DI PRIMO GRADO
/*
int main () {
    int a, b, c, delta;
    float  res1, res2;

    cout<<"Inserisci i coefficienti ordinati a, b, c\n";
    cin>>a>>b>>c;

    if ( a == 0 && b == 0)
        cout<< "Equazione degenere\n";

    if ( a == 0 ) {
        res1 = -c/b;
        cout<<"Equazione di primo grado\n";
        cout<<"Il valore di x vale: "<<res1<<endl;
    }else {
        delta = b*b - (4*a*c);

        if (delta > 0) {
            res1 = (-b-sqrt(delta))/2*a;
            res2 = (-b+sqrt(delta))/2*a;
            cout<<"I risultati dell'equazione valgono:\n"<<"X1: "<<res1<<endl<<"X2: "<<res2<<endl;
        } else
            cout<<"Soluzioni immaginarie\n";
    }
    return 0;
}
*/

/////////////////////////////////////////////////
//              LEZIONE 3                      //
/////////////////////////////////////////////////

//ACQUISISCI INPUT FINCHE' POSITIVO
/*
int main() {
    int num;
    cout<<"Inserisci un valore intero positivo\n";
    cin>>num;

    while (num<0) {
        cout<<"Il valore inserito e' negativo\n";
        cout<<"Inserisci un valore intero positivo\n";
        cin>>num;
    }

    cout<<"Il valore inserito vale: "<<num<<endl;
    return 0;
}
*/

//MEDIA NUMERI POSITIVI
/*
int main() {
    int num, somma=0,ipos=0,i=0;
    float media=0;


    cout<<"Inserisci 10 numeri interi e verra' calcolata la media dei soli positivi\n";
    do {
        cout<<"Intero n. "<<i+1<<"/10\n";
        cin>>num;
        if (num>0) {
            somma= somma + num;
            ipos ++;
        }
        i++;
    }while (i<10);

    if (ipos == 0)
        cout<<"Non hai inserito nessun valore positivo\n";
    else{
        media= static_cast<float>(somma)/float(ipos);
        cout<<"La media dei valori positivi inseriti vale: "<<media<<endl;
    }

    return 0;
}
*/

//STAMPA QUADRATI DI ASTERISCHI
/*
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
*/

//MASCHERA DI BIT
/*
int main() {

    unsigned int i;
    unsigned short int M1 = 1, val1, val2;

    cout << "Inserisci un valore (0-15)\n";
    cin >> i;

    if(i<16){
        val1 = M1 << i;
        val2 = ~(M1 << i);

        cout << "Valore numerico della maschera M1: " << val1 << endl;
        // La prossima istruzione serve a fare in modo che d'ora in avanti i naturali
        // verranno mostrati a video in base sedici.
        // Per tornare a visualizzare i natarali in base 10, utilizzare lo statement cout<<dec;
        cout << hex;
        cout << "Visualizzato in base 16: " << val1 << endl;
        cout << dec;

        cout << "Valore numerico della maschera M2: " << val2 << endl;
        cout << hex;
        cout << "Visualizzato in base 16: " << val2 << endl;
        cout << dec;
    } else
        cout << "Numero non valido\n";

    return 0;
}
*/

//Stampa binario
/*
int main() {
    unsigned int x;
    unsigned int aux;
    cout << "Digita un numero senza segno: ";
    cin >> x;

    cout << "La codifica binaria di " << x << " e': ";
    unsigned int i = sizeof(unsigned int) * 8;  //sizeof rimanda i byte, *8 ottengo i bit
    while( i > 0 ) {
        i--;
        aux = x & (1u << i);
        if (aux != 0)
            cout << 1;
        else
            cout << 0;
    }
    cout << endl;
    return 0;
}
*/

//Stampa triangolo
/*
int main() {
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
*/

//Stampa triangolo isoscele
/*
int main() {
    int n;

    // Lettura di n con controllo
    cout << "Inserisci un numero intero positivo dispari: ";
    cin >> n;

    if (n <= 0 || n % 2 == 0) {
        cout << "Errore: il numero deve essere positivo e dispari." << endl;
        return 1;
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

        return 0;
}
*/
//Stampa tavola pitagorica

void stampa_riga(int i, int j) {
    cout << i * j << "  ";
}

int main() {
    int n, res1;

    cout<<"Inserisci un numero >0\n";
    cin>>n;

    if (n>0) {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n;j++) {
                //cout<<i*j<<"  ";
                stampa_riga(i, j);
            }
            cout<<endl;
        }
    }
}

