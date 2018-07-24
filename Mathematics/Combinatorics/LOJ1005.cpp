#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool visited[100];
int main(){
  int TC;
  scanf("%d", &TC);
  for(int ii=1;ii<=TC;ii++){
    memset(visited,0,sizeof(visited));
    ll n,r,ans=1;
    scanf("%lld%lld",&n,&r);
    if(r>n){
      printf("Case %d: %lld\n",ii,0);
      continue;
    }
    for(int i=n;i>=n-r+1;i--){
      ans*=i*i;
      for(int j=1;j<=r;j++){
        if(ans%j==0 && !visited[j]){
          ans/=j;
          visited[j]++;
        }
      }
    }
    printf("Case %d: %lld\n",ii,ans);

  }
  return 0;
}
