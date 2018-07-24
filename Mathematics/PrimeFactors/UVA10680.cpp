#include<bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
using namespace std;
#define M 100000000

//----------primne starts here-------------
bool marked[1000006];
vector<ll>v;
void sieve(ll n){
  for(int i=3;i*i<=n;i+=2){
    if(marked[i]==false){
      for(int j=i*i;j<=n;j+=i+i){
        marked[j]=true;
      }
    }
  }
}
bool isprime(ll n){
  if(n<2)return false;
  if(n==2)return true;
  if(n%2==0)return false;
  return marked[n]==false;
}

vector<ll> generatePrime(ll n){
  sieve(n);
  vector<ll>v;
  for(int i=1;i<=n;i++){
    if(isprime(i))v.push_back(i);
  }
  return v;
}

//-----------------prime end here-----------
int main(){
    //freopen("0uput.txt","w",stdout);
    vector<ll>v;
    v = generatePrime(1000000);
    ll n;
    while(cin>>n){
      if(!n)break;
      vector< pair<ll,ll> > pfs;
      for(int i=0;i<v.size();i++){
        if(v[i]>n)break;
        ll temp,p;
        temp = v[i]; p = 0;
        while(temp<=n){
          p++;
          temp*= v[i];
        }
        pfs.push_back(make_pair(v[i],p));
      }
      ll two_pnt = 0;
      for(int i=0;i<pfs.size();i++){
        if(pfs[i].ff == 2){
          two_pnt = i;
          break;
        }
      }
      for(int i=0;i<pfs.size();i++){
        if(pfs[i].ff == 5){
          ll x = min(pfs[i].ss,pfs[two_pnt].ss);
          pfs[i].ss -=  x;
          pfs[two_pnt].ss -= x;
          break;
        }
      }
      //int ans = 0;
      ll temp = 1;
      for(int i=0;i<pfs.size();i++){
        //cout<<pfs[i].ff<<" "<<pfs[i].ss<<endl;
        while(pfs[i].ss--){
          temp = ( temp * (pfs[i].ff%10))%10;
          temp%=10;
          //cout<<temp<<endl;
        }
      }
      cout<<temp<<endl;

    }
    return 0;
}
