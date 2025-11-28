#include <iostream>
#include <cmath>

using namespace  std;

int main() {
    int n;
    cout<<"Inserisci un numero intero\n";
    cin>>n;

    cout<<"Il triplo del numero inserito vale: "<<n*3<<endl;

    return 0;
}


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