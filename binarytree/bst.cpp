#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data):
                data(data),
                left(nullptr),
                right(nullptr)
    {

    }
};

class BST {
    public:
    Node* root;

    BST():
                root(nullptr)
    {

    }

    ~BST(){
        destroy(root);
    }

    void destroy(Node* node){
        if(node == nullptr){
            return;
        }

        destroy(node->left);
        destroy(node->right);
        delete node;
    }

    Node* insert(Node* node, int x){
        if(node == nullptr){
            return new Node(x);
        }

        if(x < node->data){
            node->left = insert(node->left, x);
        }
        else if(x > node->data){
            node->right = insert(node->right, x);
        }

        return node;
    }

    bool search(Node* node, int x){
        if(node == nullptr){
            return false;
        }

        if(x == node->data){
            return true;
        }

        if(x < node->data){
            return search(node->left, x);
        }

        return search(node->right, x);
    }

    void preorder(Node* node){
        if(node == nullptr){
            return;
        }

        cout << node->data << "\t";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(Node* node){
        if(node == nullptr){
            return;
        }

        postorder(node->left);
        postorder(node->right);
        cout << node->data << "\t";
    }
};



int main(){
    BST tree;

    cout << "Now, enter the elements" << endl;

    while(true){
        int x;
        cout << "Enter element: ";
        cin >> x;
        tree.root = tree.insert(tree.root, x);
        cout << "are you done? 1/0 : ";
        int a;
        cin >> a;
        if(a){
            break;
        }
        
    }

    cout << "Pre order: " << endl;
    tree.preorder(tree.root);
    cout << endl;

    cout << "Post order: " << endl;
    tree.postorder(tree.root);
    cout << endl;

    int key;
    cout << "Enter element to search: ";
    cin >> key;

    if(tree.search(tree.root, key)){
        cout << key << " found" << endl;
    }
    else{
        cout << key << " not found" << endl;
    }
}