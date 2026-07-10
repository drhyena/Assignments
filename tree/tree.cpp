#include <iostream>
#include <cstring>
#include "tree.h"
using namespace std;

Tree::Tree() {
    root = NULL;
}

Node* Tree::new_node(char data) {
    Node* n = new Node();
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void Tree::create_tree(char postfix_expr[]) {
    Node* node_stack[100];
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
            Node* right_node = node_stack[top];
            top--;
            Node* left_node = node_stack[top];
            top--;

            Node* op_node = new_node(ch);
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

void Tree::infix_helper(Node* node) {
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

void Tree::prefix_helper(Node* node) {
    if (node == NULL) {
        return;
    }
    cout << node->data << " ";
    prefix_helper(node->left);
    prefix_helper(node->right);
}

void Tree::postfix_helper(Node* node) {
    if (node == NULL) {
        return;
    }
    postfix_helper(node->left);
    postfix_helper(node->right);
    cout << node->data << " ";
}

bool Tree::inorder_search_helper(Node* node, char target) {
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

void Tree::infix() {
    if (root == NULL) {
        cout << "Tree is empty" << "\n";
        return;
    }
    cout << "Infix: ";
    infix_helper(root);
    cout << "\n";
}

void Tree::prefix() {
    if (root == NULL) {
        cout << "Tree is empty" << "\n";
        return;
    }
    cout << "Prefix: ";
    prefix_helper(root);
    cout << "\n";
}

void Tree::postfix() {
    if (root == NULL) {
        cout << "Tree is empty" << "\n";
        return;
    }
    cout << "Postfix: ";
    postfix_helper(root);
    cout << "\n";
}

void Tree::inorder_search(char target) {
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
