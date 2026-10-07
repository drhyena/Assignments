#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void dijkstra(vector<vector<int>>& edges, vector<int>& dist, vector<bool>& visited){
    int node = -1;

    for(int i=0;i<dist.size();i++){
        if(!visited[i] && dist[i] != INT_MAX && (node == -1 || dist[i] < dist[node])){
            node = i;
        }
    }

    if(node == -1){
        return;
    }

    visited[node] = true;

    for( const auto& row : edges){
        int a = row[0];
        int b = row[1];
        int w = row[2];

        if(a == node && dist[node] + w < dist[b]){
            dist[b] = dist[node] + w;
        }
    }

    dijkstra(edges, dist, visited);
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

    vector<int> dist(n,INT_MAX);
    vector<bool> visited(n,false);
    dist[start] = 0;

    dijkstra(lis, dist, visited);

    cout << "Shortest distance from " << start << ": " << endl;
    for(int i=0;i<n;i++){
        cout << i << "\t";
        if(dist[i] == INT_MAX){
            cout << "INF" << endl;
        }
        else{
            cout << dist[i] << endl;
        }
    }
}