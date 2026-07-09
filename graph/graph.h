#ifndef GRAPH_H
#define GRAPH_H

class Graph {
private:
    int adj[100][100];
    bool exists[100];
    bool visited[100];
    int num_nodes;
    int max_nodes;
    void dfs_helper(int node);

public:
    Graph(int max_n);
    void insert_node();
    void insert_edge(int u, int v);
    void delete_node(int value);
    void dfs_search(int start);
    void bfs_search(int start);
    void print_graph();
};

#endif
