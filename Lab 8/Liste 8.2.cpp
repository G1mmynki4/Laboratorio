#include <iostream>

using namespace std;

struct node
{
    int data;
    node* next;
};

void add_head(node* &head, int value){

    node *new_head = new node;

    new_head->data = value;
    new_head->next = head;
    head = new_head;
}

void add_tail(node* &head, int value){

    node *new_tail = new node;
    new_tail->data = value;
    new_tail->next = nullptr;

    if(head == nullptr){
        head = new_tail;
        return;
    }

    node *tail = head;

    while (tail->next != nullptr)
        tail = tail->next;

    tail->next = new_tail;
}

void add_inPos(node* &List, int value, int pos){

    node *new_elem = new node;
    new_elem->data = value;

    if(List == nullptr){
        add_head(List, value);
        cout << "Lista vuota, elemeno posizionato in testa\n";
        return;
    }

    node *temp = List;
    int counter = 1;

    while(temp->next != nullptr && counter < pos-1){
        temp = temp->next;
        counter++;
    }
    if(temp->next == nullptr){
        add_tail(List, value);
        return;
    }

    new_elem->next = temp->next;
    temp->next = new_elem;
}

void delete_inPos(node* &List, int pos){
    
    if(List->next == nullptr){
        cout << "Impossibile eliminare da una lista vuota\n";
        return;
    }

    if(pos<=1){ //Delete Head
        node *temp = List;
        List = List->next;
        delete temp;
        return;
    }

    node *temp = List;
    int counter = 1;
    
    while(temp->next !=nullptr && counter <pos-1){
        temp = temp->next;
        counter++;
    }
    if(temp->next == nullptr){
        cout << "Impossibile eliminare\nPosizione non valida\n";
        return;
    }

    node *toDelete = temp->next;
    temp->next = toDelete->next;
    delete toDelete;
}

void printList(node* List){

    if(List == nullptr){
        cout << "Lista vuota\n";
        return;
    }

    while(List != nullptr){
        cout << List->data << "\t";
        List = List->next;
    }
    cout << endl;
}

int main(){

    node *L1 = nullptr;

    printList(L1);

    add_head(L1, 70);
    printList(L1);

    add_tail(L1, 60);
    printList(L1);

    add_inPos(L1, 50, 2);
    printList(L1);

    add_inPos(L1, 55, 2);
    printList(L1);

    delete_inPos(L1, 4);
    printList(L1);

    delete_inPos(L1, 3);
    printList(L1);

    delete_inPos(L1, 2);
    printList(L1);

    return 0;
}