#include <vector>
#include <iostream>

using namespace std;

struct Elem{
    int key;
    Elem *next_;
    Elem(int v): key(v), next_(NULL){}
};

class HashTable{
    Elem **table_;
    int size_;
    vector<int> occupancy;

public:
    HashTable(int size);
    int getHash(int value);
    void insert(int value);

    void print();
    void printOccupancy();

    bool find(int value);
};



HashTable::HashTable(int size){

    size_ = size;
    table_ = new Elem*[size_];

    for (int i = 0; i < size_; ++i)
        table_[i] = nullptr;

    occupancy.assign(size_, 0);
}

int HashTable::getHash(int val){
    return val % size_;
}

void HashTable::insert(int val){
    int idx = getHash(val);

    Elem* newVal = new Elem(val);
    newVal->next_ = table_[idx];
    table_[idx] = newVal;

    ++occupancy.at(idx);
}

void HashTable::printOccupancy(){

    for (int i = 0; i < size_; ++i){
        cout << occupancy.at(i) << ", ";
    }
    cout << endl;
}

void HashTable::print(){

    for (int i = 0; i < size_; ++i){

        Elem *tmp = table_[i];
        while (tmp)
        {
            cout << tmp->key << ", ";
            tmp = tmp->next_;
        }
        cout << endl;
    }
}

bool HashTable::find(int val){

    int idx = getHash(val);
    Elem *tmp = table_[idx];

    if(!tmp)
        return false;

    while(tmp){
        if(tmp->key == val)
            return true;
        tmp = tmp->next_;
    }
}

int main(){
    
    int M, N, K;
    cin>>M>>N>>K;
    HashTable h(M);
    
    int value;
    for(int i = 0; i < M; ++i){
        cin>>value;
        h.insert(value);
    }
    
    //h.print();
    h.printOccupancy();

    bool trovato = h.find(K);

    if (trovato) {
        cout<<"SI"<<endl;
    } else {
        cout<<"NO"<<endl;
    }
    
}