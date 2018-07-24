#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[1000],a[1000],n,k;
int main(int argc, char const *argv[]) {
  cin>>n>>k;
  for(int i=1;i<=k;i++)cin>>a[i];
  dp[0]=1;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=k;j++){
      if(i>=a[j])dp[i]+=dp[i-a[j]];
    }
  }
  for(int i=0;i<=10;i++)cout<<dp[i]<<" ";
  return 0;
}
