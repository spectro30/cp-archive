#include <bits/stdc++.h>
using namespace std;
typedef long long unsigned ll;
ll lcm(ll x,ll y){
  return (x*y) /(__gcd(x,y));
}
int main(int argc, char const *argv[]) {
  int TC;
  scanf("%d",&TC);
  for(int ii=1;ii<=TC;ii++){
    ll n,ans=0;
    int p,arr[20];
    memset(arr,0,sizeof(arr));
    scanf("%llu%d",&n,&p);
    for(int i=0;i<p;i++)scanf("%d",&arr[i]);
    for(int i=1;i<(1<<p);i++){
      ll temp=1,cnt=0;
      for(int x=0;x<p;x++){
        if(i&(1<<x)){
          temp=lcm(arr[x],temp);
          cnt++;
        }
      }
      temp=n/temp;
      if(cnt&1)ans+=temp;
      else ans-=temp;
    }
    printf("Case %d: %llu\n",ii,n-ans);
  }
  return 0;
}
