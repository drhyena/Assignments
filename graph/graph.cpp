#include <iostream>
#include "graph.h"
using namespace std;

Graph::Graph(int max_n) {
    max_nodes = max_n;
    num_nodes = 0;
    for (int i = 0; i < max_nodes; i++) {
        exists[i] = false;
        visited[i] = false;
        for (int j = 0; j < max_nodes; j++) {
            adj[i][j] = 0;
        }
    }
}

void Graph::insert_node() {
    if (num_nodes == max_nodes) {
        cout << "Overflow! Cannot insert more nodes" << "\n";
        return;
    }
    exists[num_nodes] = true;
    cout << "Inserted node " << num_nodes << "\n";
    num_nodes++;
}

void Graph::insert_edge(int u, int v) {
    if (u < 0 || u >= max_nodes || v < 0 || v >= max_nodes || !exists[u] || !exists[v]) {
        cout << "Error: invalid nodes, cannot insert edge" << "\n";
        return;
    }
    adj[u][v] = 1;
    adj[v][u] = 1;
}

void Graph::delete_node(int value) {
    if (value < 0 || value >= max_nodes || !exists[value]) {
        cout << "Underflow! Node " << value << " does not exist, cannot delete" << "\n";
        return;
    }
    exists[value] = false;
    for (int i = 0; i < max_nodes; i++) {
        adj[value][i] = 0;
        adj[i][value] = 0;
    }
    cout << "Deleted node " << value << "\n";
}

void Graph::dfs_helper(int node) {
    visited[node] = true;
    cout << node << " ";
    for (int i = 0; i < max_nodes; i++) {
        if (exists[i] && adj[node][i] == 1 && !visited[i]) {
            dfs_helper(i);
        }
    }
}

void Graph::dfs_search(int start) {
    if (start < 0 || start >= max_nodes || !exists[start]) {
        cout << "Error: node " << start << " does not exist" << "\n";
        return;
    }
    for (int i = 0; i < max_nodes; i++) {
        visited[i] = false;
    }
    cout << "DFS from node " << start << ": ";
    dfs_helper(start);
    cout << "\n";
}

void Graph::bfs_search(int start) {
    if (start < 0 || start >= max_nodes || !exists[start]) {
        cout << "Error: node " << start << " does not exist" << "\n";
        return;
    }
    bool visited_bfs[100];
    for (int i = 0; i < max_nodes; i++) {
        visited_bfs[i] = false;
    }

    int queue_arr[100];
    int front = 0;
    int rear = 0;

    queue_arr[rear] = start;
    rear++;
    visited_bfs[start] = true;

    cout << "BFS from node " << start << ": ";
    while (front < rear) {
        int current = queue_arr[front];
        front++;
        cout << current << " ";
        for (int i = 0; i < max_nodes; i++) {
            if (exists[i] && adj[current][i] == 1 && !visited_bfs[i]) {
                queue_arr[rear] = i;
                rear++;
                visited_bfs[i] = true;
            }
        }
    }
    cout << "\n";
}

void Graph::print_graph() {
    cout << "Graph edges:" << "\n";
    for (int i = 0; i < max_nodes; i++) {
        if (!exists[i]) {
            continue;
        }
        cout << i << " -> ";
        for (int j = 0; j < max_nodes; j++) {
            if (exists[j] && adj[i][j] == 1) {
                cout << j << " ";
            }
        }
        cout << "\n";
    }
}
