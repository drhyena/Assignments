#include <iostream>
#include <vector>
#include <climits>
using namespace std;

bool bellman_ford(vector<vector<int>>& edges, vector<int>& dist, int n){
    for(int i=0;i<n-1;i++){
        for( const auto& row : edges){
            int a = row[0];
            int b = row[1];
            int w = row[2];

            if(dist[a] != INT_MAX && dist[a] + w < dist[b]){
                dist[b] = dist[a] + w;
            }
        }
    }

    for( const auto& row : edges){
        int a = row[0];
        int b = row[1];
        int w = row[2];

        if(dist[a] != INT_MAX && dist[a] + w < dist[b]){
            return false;
        }
    }

    return true;
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
    dist[start] = 0;

    if(!bellman_ford(lis, dist, n)){
        cout << "Negative cycle found, shortest distances don't exist" << endl;
        return 0;
    }

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