#include <iostream>
#include <string>
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

class BinaryTree {
    public:
    Node* root;

    BinaryTree():
                root(nullptr)
    {

    }

    ~BinaryTree(){
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

    Node* build(string where){
        int x;
        cout << "Enter " << where << " (-1 for none): ";
        cin >> x;

        if(x == -1){
            return nullptr;
        }

        Node* node = new Node(x);
        node->left = build("left of " + to_string(x));
        node->right = build("right of " + to_string(x));

        return node;
    }

    void preorder(Node* node){
        if(node == nullptr){
            return;
        }

        cout << node->data << "\t";
        preorder(node->left);
        preorder(node->right);
    }
};



int main(){
    BinaryTree tree;

    cout << "Now, enter the tree" << endl;
    tree.root = tree.build("root");

    cout << "Pre order: " << endl;
    tree.preorder(tree.root);
    cout << endl;
}