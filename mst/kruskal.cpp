#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int find(vector<int>& parent, int node){
    if(parent[node] == node){
        return node;
    }

    parent[node] = find(parent, parent[node]);
    return parent[node];
}

void kruskal(vector<vector<int>>& edges, vector<int>& parent, int& total, int& count){
    sort(edges.begin(), edges.end(), [](const vector<int>& p, const vector<int>& q){
        return p[2] < q[2];
    });

    for( const auto& row : edges){
        int a = find(parent, row[0]);
        int b = find(parent, row[1]);

        if(a != b){
            parent[a] = b;
            total += row[2];
            count++;

            cout << row[0] << "\t" << row[1] << "\t" << row[2] << endl;
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

    vector<int> parent(n);
    for(int i=0;i<n;i++){
        parent[i] = i;
    }
    int total = 0;
    int count = 0;

    cout << "Minimum spanning tree (node, node, weight): " << endl;
    kruskal(lis, parent, total, count);

    if(count != n-1){
        cout << "Graph is not connected, no spanning tree exists" << endl;
        return 0;
    }

    cout << "Total weight: " << total << endl;
}