#include <bits/stdc++.h>
using namespace std;
int n,cap,w[1000],c[1000];
int rec(int pos,int cost)
{
  int lav1,lav2;
  if(pos==n+1)return 0;
  if(w[pos]+cost<=cap){
    lav1=c[pos]+rec(pos+1,cost+w[pos]);
  }
  else lav1=0;
  lav2=rec(pos+1,cost);
  return max(lav1,lav2);
}
int main(int argc, char const *argv[]) {
  cin>>n>>cap;
  for(int i=1;i<=n;i++)cin>>w[i]>>c[i];
  cout<<rec(1,0)<<endl;
  return 0;
}
