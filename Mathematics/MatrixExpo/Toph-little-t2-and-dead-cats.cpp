#define pb push_back
#define MX 1e18
#define MATMOD 1000000007
#define ff first
#define ss second
#define MAX_N 10
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;

ll k,n;
int TC;
// Assign MAX_N(Max MAtrix Size)
// Declare:  Matrix MATRIX_NAME = Matrix(No_of_Row,No_of_Colum) //or Just Matrix
//Add mod value if needed MATMOD
//--------Matrix Structure-------------
struct Matrix{
    ll mat[MAX_N][MAX_N];
    int row , col;
    Matrix(){
        row = MAX_N;
        col = MAX_N;
        init();
    };
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
Matrix matMul(Matrix a, Matrix b){
    Matrix c ;
    for(int i=0;i<k;i++){
        for(int j=0;j<k;j++){
            for(int l=0;l<k;l++){
                c.mat[i][j] = (c.mat[i][j] +  (a.mat[i][l] * b.mat[l][j])%MATMOD )%MATMOD; // Do MATMOD if needed
            }
        }
    }
    return c;
}
//------------Multiplication of Two Matrix Ends------------


//----------Matrix Power-------------
Matrix matPow(Matrix A, ll p){
    Matrix res;
    res.identity();
    while(p){
        if(p & 1)res  = matMul(res,A);
        A = matMul(A, A);
        p >>= 1;
    }
    return res;
}
//-----------Matrix Power Ends---------

int main(int argc, char const *argv[]) {
    //freopen("0uput.txt","w",stdout);
    //----------PreCalculating Matrices-----------------
    Matrix A[12],C[12];
    for(int kk=2;kk<=10;kk++){
        for(int i=0;i<kk-1;i++) A[kk].mat[i][i+1] = 1;
        A[kk].mat[kk-1][kk-1] = 1;
        A[kk].mat[kk-1][0] = 1;
        for(int i=0;i<kk;i++)C[kk].mat[i][0] = 1;

    }
    //----------PreCalculating Matrices Ends-----------------
    scanf("%d",&TC);
    for(int ii=1;ii<=TC;ii++){
        scanf("%lld%lld",&k,&n);
        Matrix x;
        x = matPow(A[k],n);
        x = matMul(x,C[k]);
        printf("Case %d: %lld\n",ii, x.mat[0][0]);
    }
    return 0;
}
