#include <iostream>
#include <cmath>

using namespace std;

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