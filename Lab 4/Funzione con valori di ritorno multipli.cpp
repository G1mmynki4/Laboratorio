#include <iostream>

using namespace std;

void calcolaStatistiche(int n1, int n2, int n3, int &min, int &max, float &media) {
  if (n1<n2 && n1<n3)
    min = n1;
  else if (n1>n2 && n1>n3)
    max = n1;
  if (n2<n1 && n2<n3)
    min = n2;
  else if (n2>n1 && n2>n3)
    max = n2;
  if (n3<n1 && n3<n2)
    min = n3;
  else if (n3>n1 && n3>n2)
    max = n3;

  media = static_cast<float>(n1+n2+n3)/3;

}

int main() {
  int n1, n2, n3, min, max;
  float media;

  cout<<"Inserisci 3 interi\n";
  cin>>n1>>n2>>n3;

  calcolaStatistiche(n1, n2, n3, min, max,media);
  cout<<"Il minimo e': "<<min<<endl;
  cout<<"Il massimo e': "<<max<<endl;
  cout<<"La media e': "<<media<<endl;

  return 0;

}