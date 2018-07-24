#include <bits/stdc++.h>
using namespace std;
int dp[6][8000],a[]={1,5,10,25,50},n;
int rec(int i,int koto){
  if(i==5){
    if(!koto)return 1;
    else return 0;
  }
  int res1=0,res2=0;
  if(dp[i][koto]!=-1)return dp[i][koto];
  if(koto-a[i]>=0)res1=rec(i,koto-a[i]);
  else res1=0;
  res2=rec(i+1,koto);
  return dp[i][koto]=res1+res2;

}
int main(int argc, char const *argv[]) {
  memset(dp,-1,sizeof(dp));
  while(cin>>n){
    cout<<rec(0,n)<<endl;
  }
  return 0;
}
