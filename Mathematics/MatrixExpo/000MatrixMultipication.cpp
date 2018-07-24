#define pb push_back
#define MX 1e18
#define mod 1000000009
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

// p = r1 , q = c1 = r2, r = c2;
//------------Multiplication of Two Matrix------------
Matrix matMul(Matrix a, Matrix b, int p, int q, int r){
  Matrix c = Matrix(p,r);
  for(int i=0;i<p;i++){
    for(int j=0;j<r;j++){
      for(int k=0;k<q;k++){
        c.mat[i][j] += a.mat[i][k] * b.mat[k][j]; // Do MATMOD if needed
      }
    }
  }
  return c;
}
//------------Multiplication of Two Matrix Ends------------

int main(int argc, char const *argv[]) {
  int r1,c1,r2,c2;
  cin>>r1>>c1>>r2>>c2;
  if(c1!=r2){
    cout<<"Multiplication Not Posssilbe"<<endl;
    return 0;
  }
  Matrix a = Matrix(r1,c1);
  Matrix b = Matrix(r2,c2);
  Matrix c = Matrix(r1,c2);
  a.getMatrix();
  b.getMatrix();
  c = matMul(a,b,r1,c1,c2);
  c.printMatrix();

  return 0;
}
