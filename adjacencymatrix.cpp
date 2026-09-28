#include <iostream>
#include <vector>
using namespace std;

class Matrix {
    public:
    vector<vector<int>> matrix;
    vector<vector<int>> edges;
    int size;
    int edges_size;
    
    Matrix(int size,int edges_size, vector<vector<int>> edge):
                            size(size) ,
                            edges_size(edges_size),
                            edges(edge),
                            matrix(size,vector<int>(size))
                                  /* default initialization to 0*/
    {

        

        for( const auto& row : edges){
                
                int a = row[0];
                int b = row[1] ;

                matrix[a][b] = 1;
                matrix[b][a] = 1;       
        }


    }
 
    void print_matrix(){
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                cout << matrix[i][j] << "\t";

            }
            cout << endl;
        }
            
        

    }

    
};




int main(){
    int n;
    int edges =0;

    cout <<"enter no: of nodes: ";
    cin >> n;
    vector<vector<int>> lis;
    int i =0;
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

    for ( const auto& row: lis){
        for(int x : row){
            cout << x << "\t";
        }
        cout << endl;
    }
    
    Matrix matrix(n,edges,lis);
    matrix.print_matrix();
}