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
  while(temp%2 == 0){
    v.push_back(2);
    temp/=2;
  }
  for(ll i=3; i*i<=n;i+=2){
    while(temp%i == 0){
      v.push_back(i);
      temp/=i;
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
    printf("%lld = ",n);
    if(n<0)printf("-1 x ");
    for(int i=0;i<v.size();i++){
      if(i)printf(" x ");
      printf("%lld",v[i]);
    }
    printf("\n");
  }

  return 0;
}
