#define pb push_back
#define ll long long
#define ff first
#define ss second
#include <bits/stdc++.h>
using namespace std;
ll visited[1000006],a[10006];
//------- Prime Factorization--------
vector<ll> pf( ll n){
  vector<ll> v;
  ll temp = n;
  for(int i=2; i*i<=n;i++){
    if(temp%i == 0)v.push_back(i);
    while(temp%i == 0)temp/=i;
  }
  if(temp>1)v.push_back(temp);
  return v;
}
//-------prime Factorization ends----------

//-------------LCM-------------
ll lcm(ll a,ll b){
  return (a*b)/(__gcd(a,b));
}
//-----------LCM ends----------

//----------Generating Subsets---------
void allPossibleSubset(ll x){
  vector<ll>v;
  v = pf(x);
  ll n = v.size();
  for(int i=1;i<(1<<n);i++){
    ll res = 1;
    for(int j=0;j<n;j++){
      if(i&(1<<j))res = lcm(res,v[j]);
    }
    visited[res]++;
  }
}
//---------------Generating Subset ends----------

//-------------- nC4-------------
ll nc4(int n){
  if(n<4)return 0;
  ll temp = 1;
  for(int i=n;i>=n-3;i--)temp *= i;
  temp /= 24;
  return temp;
}
//----------nC4 ends---------------



int main(int argc, char const *argv[]) {
  //freopen("0uput.txt","w",stdout);
  int TC;
  scanf("%d",&TC);
  for(int ii=1;ii<=TC;ii++){
    memset(visited,0,sizeof(visited));
    ll n;
    scanf("%lld",&n);
    ll ans ;
    ans = nc4(n);
    //cout<<ans<<endl;
    for(int i=1;i<=n;i++){
      scanf("%lld",&a[i]);
      allPossibleSubset(a[i]);
    }
    for(int i=1;i<=n;i++){
      vector<ll>pre_v,v;ll sz;
      pre_v = pf(a[i]);
      for(int j=0;j<pre_v.size();j++)if(visited[pre_v[j]])v.pb(pre_v[j]);
      if(v.empty())continue;
      sz = v.size();
      for(int j=1;j<(1<<sz);j++){
        ll res = 1,cnt = 0;
        for(int k=0;k<sz;k++){
          if(j&(1<<k)){
            cnt ++;
            res = lcm(res,v[k]);
          }
        }
        if(cnt%2)ans -= nc4(visited[res]);
        else ans += nc4(visited[res]);
        visited[res] = 1;
      }
    }
    printf("Case %d: %lld\n",ii,ans);


  }



  // while(1){
  //   int n;
  //   cin>>n;
  //   vector<int>v,subset;
  //   v = pf(n);
  //   subset = allPossibleSubsets(v);
  //   for(int i=0;i<v.size();i++){
  //     cout<<v[i]<<" ";
  //   }
  //   cout<<endl;
  //   for(int i=0;i<subset.size();i++){
  //     cout<<subset[i]<<" ";
  //   }
  //   cout<<endl;
  //
  // }
  return 0;
}
