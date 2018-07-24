#define pb push_back
#define MX 1e18
#define mod 1000000009
#define ff first
#define ss second
#define MAX_N 3
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;

// Assign MAX_N(Max MAtrix Size)
// Declare:  Matrix MATRIX_NAME = Matrix(No_of_Row,No_of_Colum)
//Add mod value if needed MATMOD
//--------Matrix Structure-------------
ll MATMOD = 1000000009;
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
    for(int i=0;i<MAX_N;i++){
        for(int j=0;j<MAX_N;j++){
            for(int k=0;k<MAX_N;k++){
                c.mat[i][j] = (c.mat[i][j] +  (a.mat[i][k] * b.mat[k][j])%MATMOD )%MATMOD;
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
    Matrix A,C;
    A.mat[0][0] = 0; A.mat[0][1] = 1; A.mat[0][2] = 0;
    A.mat[1][0] = 0; A.mat[1][1] = 0; A.mat[1][2] = 1;
    A.mat[2][0] = 1; A.mat[2][1] = 1; A.mat[2][2] = 1;

    C.mat[0][0] = 0; C.mat[1][0] = 1; C.mat[2][0] = 2;
    ll n;
    while(1){
        scanf("%lld",&n);
        if(!n)break;
        if(n<=2){
            printf("%lld\n",C.mat[n-1][0]);
        }
        else{
            Matrix M;
            M = matPow(A,n-1);
            M = matMul(M,C);
            printf("%lld\n",M.mat[0][0] );
        }

    }
    return 0;
}
