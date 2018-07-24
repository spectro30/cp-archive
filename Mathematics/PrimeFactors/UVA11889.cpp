#define ll long long
#define pb push_back
#define mpr make_pair
#define ff first
#define ss second
#include <bits/stdc++.h>
using namespace std;

//------- Prime Factorization--------
vector<ll> pf( ll n){
  vector<ll> v;
  ll temp = n,x;
  for(int i=2; i*i<=n;i++){
    if(temp%i == 0){
      x = 1;
      while(temp%i == 0){
        temp/=i;
        x*=i;
      }
      v.push_back(x);
    }
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

int main(int argc, char const *argv[]) {
  int TC;
  scanf("%d",&TC);
  while(TC--){
    ll A,C,D;
    scanf("%lld%lld",&A,&C);
    if(A>C){
      printf("NO SOLUTION\n");
      continue;
    }
    D = C;
    vector<ll>v;
    v = pf(C);
    for(int i=0;i<v.size();i++){
      if(A%v[i]==0)C/=v[i];
    }
    if(lcm(A,C) == D)printf("%lld\n",C);
    else printf("NO SOLUTION\n");
  }
  return 0;
}
