#define pb push_back
#define ll long long
#define ff first
#define ss second
#define mod 100000007
#include <bits/stdc++.h>
using namespace std;
//-----------Catalan Number----------
ll catalan(ll n){
  bool carked[50];
  memset(carked,0,sizeof carked);
  ll res = 1;
  for(int i=n+2;i<=n+n;i++){
    res *= i;
    for(int j=1;j<=n;j++)if(res%j==0 && !carked[j]){
      res/=j;
      carked[j] = true;
    }
  }
  return res;
}

//-----------Catalan Number Ends---------

int main(int argc, char const *argv[]) {
  ll n;
  vector<ll>v;
  for(int i=1;i<=30;i++)v.pb(catalan(i));
  while(cin>>n){
    for(int i=0;i<30;i++)if(n==v[i]){
      cout<<i+1<<endl;
      break;
    }
  }

  return 0;
}
