#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

const int MAXN = 100;

template <typename T = int>
class Graph {
private:
    int max_nodes;
    int num_nodes;
    bool exists[MAXN];
    bool visited[MAXN];
    int adj[MAXN][MAXN];
    T data[MAXN];

    void dfs_helper(int node);

public:
    Graph(int max_n = MAXN);

    int get_max_nodes() const;
    bool node_exists(int i) const;
    int get_adj(int u, int v) const;
    T get_data(int i) const;

    void insert_node(T value = T());
    void insert_edge(int u, int v);
    void delete_node(int value);
    void dfs_search(int start);
    void bfs_search(int start);
    void print_graph();

    Graph<T> operator+(const Graph<T>& other) const;
    Graph<T> operator-(const Graph<T>& other) const;
};

template <typename T>
Graph<T>::Graph(int max_n) {
    max_nodes = (max_n > MAXN) ? MAXN : max_n;
    num_nodes = 0;
    for (int i = 0; i < MAXN; i++) {
        exists[i] = false;
        visited[i] = false;
        for (int j = 0; j < MAXN; j++) {
            adj[i][j] = 0;
        }
    }
}

template <typename T>
int Graph<T>::get_max_nodes() const {
    return max_nodes;
}

template <typename T>
bool Graph<T>::node_exists(int i) const {
    return i >= 0 && i < MAXN && exists[i];
}

template <typename T>
int Graph<T>::get_adj(int u, int v) const {
    return adj[u][v];
}

template <typename T>
T Graph<T>::get_data(int i) const {
    return data[i];
}

template <typename T>
void Graph<T>::insert_node(T value) {
    if (num_nodes == max_nodes) {
        cout << "Overflow! Cannot insert more nodes" << "\n";
        return;
    }
    exists[num_nodes] = true;
    data[num_nodes] = value;
    cout << "Inserted node " << num_nodes << "\n";
    num_nodes++;
}

template <typename T>
void Graph<T>::insert_edge(int u, int v) {
    if (u < 0 || u >= max_nodes || v < 0 || v >= max_nodes || !exists[u] || !exists[v]) {
        cout << "Error: invalid nodes, cannot insert edge" << "\n";
        return;
    }
    adj[u][v] = 1;
    adj[v][u] = 1;
}

template <typename T>
void Graph<T>::delete_node(int value) {
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

template <typename T>
void Graph<T>::dfs_helper(int node) {
    visited[node] = true;
    cout << node << " ";
    for (int i = 0; i < max_nodes; i++) {
        if (exists[i] && adj[node][i] == 1 && !visited[i]) {
            dfs_helper(i);
        }
    }
}

template <typename T>
void Graph<T>::dfs_search(int start) {
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

template <typename T>
void Graph<T>::bfs_search(int start) {
    if (start < 0 || start >= max_nodes || !exists[start]) {
        cout << "Error: node " << start << " does not exist" << "\n";
        return;
    }
    bool visited_bfs[MAXN];
    for (int i = 0; i < max_nodes; i++) {
        visited_bfs[i] = false;
    }

    int queue_arr[MAXN];
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

template <typename T>
void Graph<T>::print_graph() {
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


template <typename T>
Graph<T> Graph<T>::operator+(const Graph<T>& other) const {
    int new_max = (max_nodes > other.max_nodes) ? max_nodes : other.max_nodes;
    Graph<T> result(new_max);

    for (int i = 0; i < new_max; i++) {
        bool in_this = (i < max_nodes) && exists[i];
        bool in_other = (i < other.max_nodes) && other.exists[i];
        if (in_this || in_other) {
            result.exists[i] = true;
            result.data[i] = in_this ? data[i] : other.data[i];
            if (i >= result.num_nodes) {
                result.num_nodes = i + 1;
            }
        }
    }

    for (int i = 0; i < new_max; i++) {
        if (!result.exists[i]) continue;
        for (int j = 0; j < new_max; j++) {
            if (!result.exists[j]) continue;
            bool edge_this = (i < max_nodes && j < max_nodes && adj[i][j] == 1);
            bool edge_other = (i < other.max_nodes && j < other.max_nodes && other.adj[i][j] == 1);
            if (edge_this || edge_other) {
                result.adj[i][j] = 1;
            }
        }
    }

    return result;
}


template <typename T>
Graph<T> Graph<T>::operator-(const Graph<T>& other) const {
    Graph<T> result(max_nodes);

    for (int i = 0; i < max_nodes; i++) {
        if (exists[i]) {
            result.exists[i] = true;
            result.data[i] = data[i];
            if (i >= result.num_nodes) {
                result.num_nodes = i + 1;
            }
        }
    }

    for (int i = 0; i < max_nodes; i++) {
        if (!exists[i]) continue;
        for (int j = 0; j < max_nodes; j++) {
            if (!exists[j] || adj[i][j] != 1) continue;
            bool edge_other = (i < other.max_nodes && j < other.max_nodes &&
                                other.exists[i] && other.exists[j] && other.adj[i][j] == 1);
            if (!edge_other) {
                result.adj[i][j] = 1;
            }
        }
    }

    return result;
}

#endif