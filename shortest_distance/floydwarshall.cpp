#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void floyd_warshall(vector<vector<int>>& dist, int n){
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
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

    vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
    for(int i=0;i<n;i++){
        dist[i][i] = 0;
    }

    for( const auto& row : lis){
        if(row[2] < dist[row[0]][row[1]]){
            dist[row[0]][row[1]] = row[2];
        }
    }

    floyd_warshall(dist, n);

    for(int i=0;i<n;i++){
        if(dist[i][i] < 0){
            cout << "Negative cycle found, shortest distances don't exist" << endl;
            return 0;
        }
    }

    cout << "Shortest distance between every pair: " << endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(dist[i][j] == INT_MAX){
                cout << "INF" << "\t";
            }
            else{
                cout << dist[i][j] << "\t";
            }
        }
        cout << endl;
    }
}