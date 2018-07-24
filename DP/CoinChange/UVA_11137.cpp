#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[23][10002],a[23],ans,n;
ll rec(ll i,ll koto){
  if(i==22){
    if(!koto)return 1;
    else return 0;
  }
  ll res1=0,res2=0;
  if(dp[i][koto]!=-1)return dp[i][koto];
  if(koto-a[i]>=0)res1=rec(i,koto-a[i]);
  else res1=0;
  res2=rec(i+1,koto);
  return dp[i][koto]=res1+res2;

}
int main(int argc, char const *argv[]) {
  //freopen("0uput.txt","w",stdout);
  memset(dp,-1,sizeof(dp));
  for(int i=1;i<=21;i++)a[i]=(i*i*i);
  while(cin>>n){
    ans=rec(1,n);
    cout<<ans<<endl;
  }
  return 0;
}
