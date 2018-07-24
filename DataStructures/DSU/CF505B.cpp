#include<bits/stdc++.h>
using namespace std;
int par[110][110];
int findd(int r, int col){
    if (par[col][r]==r) return r;

    return par[col][r]=findd(par[col][r],col);

}
void unionn(int a,int b,int color){
    int u=findd(a,color);
    int v=findd(b,color);
    par[color][u]=v;
    return ;
}
int edge[105][105][105];
int main(){

    for(int i=1;i<=102;i++){
      for(int j=1;j<=102;j++){
        par[i][j]=j;//i color
      }
    }
    int n,m,x,y,z;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
      cin>>x>>y>>z;
      unionn(x,y,z);
    }
    int q,ans;
    cin>>q;
    for(int i=1;i<=q;i++){
      ans=0;
      cin>>x>>y;
      for(int j=1;j<=100;j++){
        if(findd(x,j)==findd(y,j))ans++;
      }
      cout<<ans<<endl;
    }
    return 0;
}
