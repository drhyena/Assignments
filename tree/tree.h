#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <cstring>
using namespace std;

template <typename T = char>
struct Node {
    T data;
    Node<T>* left;
    Node<T>* right;
};

template <typename T = char>
class Tree {
private:
    Node<T>* root;

    Node<T>* new_node(T data);
    Node<T>* copy_helper(Node<T>* node) const;
    void infix_helper(Node<T>* node);
    void prefix_helper(Node<T>* node);
    void postfix_helper(Node<T>* node);
    bool inorder_search_helper(Node<T>* node, T target);

public:
    Tree();
    Tree(Node<T>* r);

    void create_tree(char postfix_expr[]);
    void infix();
    void prefix();
    void postfix();
    void inorder_search(T target);

    Tree<T> operator+(const Tree<T>& other) const;
    Tree<T> operator-(const Tree<T>& other) const;
};

template <typename T>
Tree<T>::Tree() {
    root = NULL;
}

template <typename T>
Tree<T>::Tree(Node<T>* r) {
    root = r;
}

template <typename T>
Node<T>* Tree<T>::new_node(T data) {
    Node<T>* n = new Node<T>();
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

template <typename T>
Node<T>* Tree<T>::copy_helper(Node<T>* node) const {
    if (node == NULL) {
        return NULL;
    }
    Node<T>* n = new Node<T>();
    n->data = node->data;
    n->left = copy_helper(node->left);
    n->right = copy_helper(node->right);
    return n;
}

template <typename T>
void Tree<T>::create_tree(char postfix_expr[]) {
    Node<T>* node_stack[100];
    int top = -1;
    int len = strlen(postfix_expr);

    for (int i = 0; i < len; i++) {
        char ch = postfix_expr[i];

        if (ch == ' ') {
            continue;
        }

        if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            if (top < 1) {
                cout << "Error: invalid postfix expression" << "\n";
                return;
            }
            Node<T>* right_node = node_stack[top];
            top--;
            Node<T>* left_node = node_stack[top];
            top--;

            Node<T>* op_node = new_node(ch);
            op_node->left = left_node;
            op_node->right = right_node;

            top++;
            node_stack[top] = op_node;
        } else {
            top++;
            node_stack[top] = new_node(ch);
        }
    }

    if (top != 0) {
        cout << "Error: invalid postfix expression" << "\n";
        return;
    }

    root = node_stack[top];
}

template <typename T>
void Tree<T>::infix_helper(Node<T>* node) {
    if (node == NULL) {
        return;
    }
    if (node->left == NULL && node->right == NULL) {
        cout << node->data;
        return;
    }
    cout << "(";
    infix_helper(node->left);
    cout << node->data;
    infix_helper(node->right);
    cout << ")";
}

template <typename T>
void Tree<T>::prefix_helper(Node<T>* node) {
    if (node == NULL) {
        return;
    }
    cout << node->data << " ";
    prefix_helper(node->left);
    prefix_helper(node->right);
}

template <typename T>
void Tree<T>::postfix_helper(Node<T>* node) {
    if (node == NULL) {
        return;
    }
    postfix_helper(node->left);
    postfix_helper(node->right);
    cout << node->data << " ";
}

template <typename T>
bool Tree<T>::inorder_search_helper(Node<T>* node, T target) {
    if (node == NULL) {
        return false;
    }
    if (inorder_search_helper(node->left, target)) {
        return true;
    }
    if (node->data == target) {
        return true;
    }
    return inorder_search_helper(node->right, target);
}

template <typename T>
void Tree<T>::infix() {
    if (root == NULL) {
        cout << "Tree is empty" << "\n";
        return;
    }
    cout << "Infix: ";
    infix_helper(root);
    cout << "\n";
}

template <typename T>
void Tree<T>::prefix() {
    if (root == NULL) {
        cout << "Tree is empty" << "\n";
        return;
    }
    cout << "Prefix: ";
    prefix_helper(root);
    cout << "\n";
}

template <typename T>
void Tree<T>::postfix() {
    if (root == NULL) {
        cout << "Tree is empty" << "\n";
        return;
    }
    cout << "Postfix: ";
    postfix_helper(root);
    cout << "\n";
}

template <typename T>
void Tree<T>::inorder_search(T target) {
    if (root == NULL) {
        cout << "Tree is empty, cannot search" << "\n";
        return;
    }
    bool found = inorder_search_helper(root, target);
    if (found) {
        cout << target << " found in tree" << "\n";
    } else {
        cout << target << " not found in tree" << "\n";
    }
}

template <typename T>
Tree<T> Tree<T>::operator+(const Tree<T>& other) const {
    Node<T>* op_node = new Node<T>();
    op_node->data = '+';
    op_node->left = copy_helper(root);
    op_node->right = copy_helper(other.root);
    return Tree<T>(op_node);
}

template <typename T>
Tree<T> Tree<T>::operator-(const Tree<T>& other) const {
    Node<T>* op_node = new Node<T>();
    op_node->data = '-';
    op_node->left = copy_helper(root);
    op_node->right = copy_helper(other.root);
    return Tree<T>(op_node);
}

#endif