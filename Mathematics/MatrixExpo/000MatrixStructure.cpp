#define pb push_back
#define ff first
#define ss second
#define MAX_N 10
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;

// Assign MAX_N(Max MAtrix Size)
// Declare:  Matrix MATRIX_NAME = Matrix(No_of_Row,No_of_Colum)
//Add mod value if needed MATMOD
//--------Matrix Structure-------------
#define MATMOD 1000000007
struct Matrix{
  ll mat[MAX_N][MAX_N];
  int row , col;
  Matrix(int r,int c){
    row = r;
    col = c;
    init();
  }
  void init(){
    memset(mat,0,sizeof mat);
  }
  void identity(){
    for(int i=0;i<row;i++)mat[i][i] = 1;
  }
  void printMatrix(){
    for(int i=0;i<row;i++){
      for(int j=0;j<col;j++){
        cout<<mat[i][j]<<" ";
      }cout<<endl;
    }
  }
  void getMatrix(){
    for(int i=0;i<row;i++){
      for(int j=0;j<col;j++){
        scanf("%d",&mat[i][j]);
      }
    }
  }
};
//------------Matrix Structure Ends------------

int main(int argc, char const *argv[]) {
  int r,c;
  cin>>r>>c;
  Matrix a = Matrix(r,c);
  a.identity();
  a.getMatrix();
  a.printMatrix();
  return 0;
}
