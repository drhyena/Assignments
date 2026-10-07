#include <iostream>
#include <vector>
using namespace std;

void prim(vector<vector<int>>& edges, vector<bool>& visited, int& total){
    int best = -1;

    for(int i=0;i<edges.size();i++){
        int a = edges[i][0];
        int b = edges[i][1];
        int w = edges[i][2];

        if(visited[a] != visited[b]){
            if(best == -1 || w < edges[best][2]){
                best = i;
            }
        }
    }

    if(best == -1){
        return;
    }

    int a = edges[best][0];
    int b = edges[best][1];
    int w = edges[best][2];

    visited[a] = true;
    visited[b] = true;
    total += w;

    cout << a << "\t" << b << "\t" << w << endl;

    prim(edges, visited, total);
}



int main(){
    int n;

    cout <<"enter no: of nodes: ";
    cin >> n;
    vector<vector<int>> lis;

    cout << "Now, enter the relations"<< endl;

    while(true){
        int x,y,w;
        cout << "Enter first element: ";
        cin >> x;
        cout << "Enter second: ";
        cin>> y;
        cout << "Enter weight: ";
        cin>> w;
        lis.push_back({x,y,w});
        cout << "are you done? 1/0 : ";
        int a;
        cin >> a;
        if(a){
            break;
        }
        
    }

    int start;
    cout << "Enter starting node: ";
    cin >> start;

    vector<bool> visited(n,false);
    visited[start] = true;
    int total = 0;

    cout << "Minimum spanning tree (node, node, weight): " << endl;
    prim(lis, visited, total);

    for(int i=0;i<n;i++){
        if(!visited[i]){
            cout << "Graph is not connected, no spanning tree exists" << endl;
            return 0;
        }
    }

    cout << "Total weight: " << total << endl;
}