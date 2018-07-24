#include <bits/stdc++.h>
using namespace std;
int nCr(int n,int r)
{
  if(r==1)return n;
  if(n==r)return 1;
  dp[n][r]=nCr(n-1,r-1)+nCr(n-1,r);
  return dp[n][r];
}
int main(int argc, char const *argv[]) {
  memset(dp,-1,sizeof(dp));
  for(int i=1;i<=15;i++){
    for(int j=i;j<=15;j++){
      cout<<j<<" - "<<i<<"==="<< nCr(j,i)<<endl;
    }
  }
  return 0;
}
