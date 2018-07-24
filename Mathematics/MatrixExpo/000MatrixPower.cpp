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
  Matrix(){};
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

//------------Multiplication of Two Matrix------------
Matrix matMul(Matrix a, Matrix b, int p, int q, int r){
  Matrix c = Matrix(p,r);
  for(int i=0;i<p;i++){
    for(int j=0;j<r;j++){
      for(int k=0;k<q;k++){
        c.mat[i][j] = (c.mat[i][j] +  (a.mat[i][k] * b.mat[k][j])%MATMOD)%MATMOD; // Do MATMOD if needed
      }
    }
  }
  return c;
}
//------------Multiplication of Two Matrix Ends------------


//----------Matrix Power-------------
Matrix matPow(Matrix A, ll p,int r){
  Matrix res = Matrix(r,r);
  res.identity();
  while(p){
    if(p & 1)res  = matMul(res,A,r,r,r);
    A = matMul(A, A,r,r,r);
    p >>= 1;
  }
  return res;
}
//-----------Matrix Power Ends---------


int main(int argc, char const *argv[]) {
  int r,c;
  ll p;
  cin>>r>>c>>p;
  if(r!=c){
    cout<<"Matrix Power Not Possible"<<endl;
    return 0;
  }
  Matrix a = Matrix(r,c);
  a.getMatrix();
  a = matPow(a,p,r);
  a.printMatrix();

  return 0;
}
