#include <iostream>

using namespace std;

void raddoppia(int &n){
    cout<<"\ndentro raddoppia(), indirizzo di n: "<<&n<<endl;
    cout<<"dentro raddoppia(), valore di n: "<<n<<endl;
	n*=2;
    cout<<"dentro raddoppia(), valore di n: "<<n<<endl;

}

void raddoppia_ptr(int *n) {
    cout<<"\ndentro raddoppia_ptr(), indirizzo di n: "<<n<<endl;
    cout<<"dentro raddoppia_ptr(), valore di n: "<<*n<<endl;
    *n*=2;
    cout<<"dentro raddoppia_ptr(), valore di n: "<<*n<<endl;
}

int main() {
    int n;
    int* pn = &n;

    cout<<"Numero ?\n";
    cin>>n;

    cout<<"L'indirizzo di n in main() e': "<<&n<<endl;
    raddoppia(n);
    cout<<"\ndentro main(), nuovo valore di n: "<<n<<endl;
    raddoppia_ptr(pn);
    cout<<"\ndentro main(), indirizzo di ptr n: "<<pn<<endl;
    cout<<"\ndentro main(), valore di ptr n: "<<*pn<<endl;
}