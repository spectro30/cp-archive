#define pb push_back
#define MX 1e18
#define mod 1000000009
#define ff first
#define ss second
#define MAX_N 15
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;

// Assign MAX_N(Max MAtrix Size)
// Declare:  Matrix MATRIX_NAME = Matrix(No_of_Row,No_of_Colum) //or Just Matrix
//Add mod value if needed MATMOD
//--------Matrix Structure-------------
ll MATMOD;
ll opt;
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
        for(int i=0;i<opt;i++)for(int j=0;j<opt;j++)mat[i][j] = 0;
    }
    void identity(){
        for(int i=0;i<opt;i++)mat[i][i] = 1;
    }

};
//------------Matrix Structure Ends------------

//------------Multiplication of Two Matrix------------
Matrix matMul(Matrix a, Matrix b){
    Matrix c ;
    for(int i=0;i<opt;i++){
        for(int j=0;j<opt;j++){
            for(int k=0;k<opt;k++){
                c.mat[i][j] = (c.mat[i][j] +  (a.mat[i][k] * b.mat[k][j])%MATMOD )%MATMOD; // Do MATMOD if needed
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
    ll n;
    int d;
    while(1){
        scanf("%d%lld%lld",&d,&n,&MATMOD);
        opt = d;
        if(!n && !d && !MATMOD)break;
        Matrix A;
        Matrix C;
        for(int i=d-1;i>=0;i--)scanf("%lld",&A.mat[d-1][i]);
        for(int i=0;i<d;i++)scanf("%lld",&C.mat[i][0]);
        for(int i=0;i<d-1;i++)A.mat[i][i+1] = 1;
        Matrix M;
        n-=d;
        M = matPow(A,n);
        M = matMul(M,C);
        printf("%lld\n", M.mat[d-1][0]);

    }
    return 0;
}
