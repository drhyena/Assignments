#ifndef MATRIX_H
#define MATRIX_H

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

#endif