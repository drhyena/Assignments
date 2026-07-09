#ifndef TREE_H
#define TREE_H

struct Node {
    char data;
    Node* left;
    Node* right;
};

class Tree {
private:
    Node* root;
    Node* new_node(char data);
    void infix_helper(Node* node);
    void prefix_helper(Node* node);
    void postfix_helper(Node* node);
    bool inorder_search_helper(Node* node, char target);

public:
    Tree();
    void create_tree(char postfix_expr[]);
    void infix();
    void prefix();
    void postfix();
    void inorder_search(char target);
};

#endif
