#include <iostream>
using namespace std;

struct Node{
    int val;
    Node *left;
    Node *right;

    Node(int v) : val(v), left(nullptr), right(nullptr) {};
};


class BinTree{

    Node *root_;
    void inOrder(Node*)const;

public:
    BinTree() : root_(nullptr) {};
    void addNode(int);
    void printTree() const { inOrder(root_); };
    Node* getMin();
    Node* getMax();
};


void BinTree::inOrder(Node* root)const{

    if(!root)
        return;

    inOrder(root->left);
    cout << root->val <<"\t";
    inOrder(root->right);
}

void BinTree::addNode(int n){

    Node *toAdd = new Node(n);
    Node *current = root_;
    Node *prev = nullptr;

    while(current){
        prev = current;
        if(n <= current->val)
            current = current->left;
        else
            current = current->right;
    }

    if(!prev){
        root_ = toAdd;
        return;
    }

    if(n <= prev->val){
        prev->left = toAdd;
        return;
    }

    prev->right = toAdd;
}

Node* BinTree::getMin(){

    Node *tmp = root_;

    while (tmp->left)    // scorro solo i figli SX (contenenti quindi il val minore);
        tmp = tmp->left; // se non ho figlio sx allora sono io il valore minore;

    return tmp;
}

Node* BinTree::getMax(){

    Node *tmp = root_;

    while (tmp->right)    // scorro solo i figli dX (contenenti quindi il val maggiore);
        tmp = tmp->right; // se non ho figlio dx allora sono io il valore maggiore;

    return tmp;
}


int main(){
    
    int n, value;
    cin>>n;
    
    BinTree bt;
    for(int i = 0; i < n; ++i){
        cin>>value;
        bt.addNode(value);
    }

    bt.printTree();
    
    Node *min = bt.getMin();
    cout<<endl;
    cout<<min->val<<endl;
    
    Node *max = bt.getMax();
    cout<<max->val<<endl;
    
    
}
