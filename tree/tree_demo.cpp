#include <iostream>
#include "tree.h"
using namespace std;

int main() {
    Tree<int> t;

    char postfix_expr[] = "AB+C*";
    t.create_tree(postfix_expr);

    t.infix();
    t.prefix();
    t.postfix();

    t.inorder_search('B');
    t.inorder_search('Z');

    return 0;
}
