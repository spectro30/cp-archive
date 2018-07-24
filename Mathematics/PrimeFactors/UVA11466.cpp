#define pb push_back
#define ll long long
#define ff first
#define ss second
#include <bits/stdc++.h>
using namespace std;

//------- Prime Factorization--------
vector<ll> pf( ll n){
  vector<ll> v;
  ll temp = n,x;
  for(ll i=2; i*i<=n;i++){
    if(temp%i==0){
      v.push_back(i);
      while(temp%i == 0)temp/=i;
    }

  }
  if(temp>1)v.push_back(temp);
  return v;
}
//-------prime Factorization ends----------

int main(int argc, char const *argv[]) {
  ll n;
  while(1){
    scanf("%lld",&n);
    if(!n)break;
    vector<ll>v;
    v = pf(abs(n));
    int sz = v.size();
    if(sz <= 1)printf("-1\n");
    else{
      printf("%lld\n",v[sz-1]);
    }
  }

  return 0;
}
