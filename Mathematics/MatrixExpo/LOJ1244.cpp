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
// Declare:  Matrix MATRIX_NAME = Matrix(No_of_Row,No_of_Colum) //or Just Matrix
//Add mod value if needed MATMOD
//--------Matrix Structure-------------
ll MATMOD = 10007;
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

int TC;
ll n,ans;
int main(int argc, char const *argv[]) {
    //freopen("0uput.txt","w",stdout);
    Matrix A,C;
    A.mat[0][0] = 0; A.mat[0][1] = 1; A.mat[0][2] = 0;
    A.mat[1][0] = 1; A.mat[1][1] = 1; A.mat[1][2] = 2;
    A.mat[2][0] = 1; A.mat[2][1] = 0; A.mat[2][2] = 1;


    C.mat[0][0] = 0; C.mat[1][0] = 1; C.mat[2][0] = 0;

    scanf("%d",&TC);
    for(int ii=1;ii<=TC;ii++){
        ll n;
        scanf("%lld",&n);

        Matrix x;
        x = matPow(A,n);
        x = matMul(x,C);
        //x.printMatrix();
        printf("Case %d: %lld\n",ii, x.mat[1][0]);
    }
    return 0;
}
