#include <iostream>
#include "graph.h"
using namespace std;

int main() {
    Graph g(6);

    g.insert_node();
    g.insert_node();
    g.insert_node();
    g.insert_node();
    g.insert_node();

    g.insert_edge(0, 1);
    g.insert_edge(0, 2);
    g.insert_edge(1, 3);
    g.insert_edge(2, 4);

    g.print_graph();

    g.dfs_search(0);
    g.bfs_search(0);

    g.delete_node(2);
    g.print_graph();

    g.dfs_search(0);

    g.delete_node(10);
    g.insert_edge(0, 10);

    return 0;
}
