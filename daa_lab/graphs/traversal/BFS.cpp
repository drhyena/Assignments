#include <iostream>
#include <vector>
#include <queue>
#include "matrix.h"
using namespace std;

void bfs(Matrix& g, int start, vector<bool>& visited){
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout << node << "\t";

        for(int next=0; next<g.size; next++){
            if(g.matrix[node][next] == 1 && !visited[next]){
                visited[next] = true;
                q.push(next);
            }
        }
    }
}



int main(){
    int n;
    int edges =0;

    cout <<"enter no: of nodes: ";
    cin >> n;
    vector<vector<int>> lis;

    cout << "Now, enter the relations"<< endl;

    while(true){
        int x,y;
        cout << "Enter first element: ";
        cin >> x;
        cout << "Enter second: ";
        cin>> y;
        lis.push_back({x,y});
        edges++;
        cout << "are you done? 1/0 : ";
        int a;
        cin >> a;
        if(a){
            break;
        }
        
    }

    Matrix matrix(n,edges,lis);
    matrix.print_matrix();

    int start;
    cout << "Enter starting node: ";
    cin >> start;

    vector<bool> visited(n,false);

    cout << "BFS traversal: " << endl;
    bfs(matrix, start, visited);

    for(int i=0;i<n;i++){
        if(!visited[i]){
            bfs(matrix, i, visited);
        }
    }
    cout << endl;
}
