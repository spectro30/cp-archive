#include<bits/stdc++.h>
using namespace std;
int par[1000006];

//------------------DSU ------------//
void inint(int n){
  for(int i=1;i<=n;i++){
    par[i]=i;
  }
}

int rep(int n){
  if(par[n]==n)return n;
  return par[n] = rep(par[n]);
}
void join(int x,int y){
  int a = rep(x);
  int b  = rep(y);
  if(a!=b)par[a]=b;

}
///-----------------DSU ends-------------//

int main(){
  int n,q;
  cin>>n>>q;
  inint(n);
  int x,y;
  for(int i=1;i<=q;i++){
    cin>>x>>y;
    join(x,y);
  }
  for(int i=1;i<=n;i++){
    par[i]= rep(i);
    cout<<par[i]<<endl;
  }
}
