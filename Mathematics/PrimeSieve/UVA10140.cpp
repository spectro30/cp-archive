#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 46345

//----------primne starts here-------------
bool marked[M+6];
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

vector<ll>v;
void generatePrime(ll n){
  sieve(n);
  for(ll i=1;i<=n;i++){
    if(isprime(i))v.push_back(i);
  }
}

//-----------------prime end here-----------

//----------Efficient Prime Check------------

bool isPrimeEfficient(ll n){
  if(n <= M) return isprime(n);
  for(int i=0; i<v.size();i++)if(n%v[i]==0)return false;
  return true;
}

//-----------Efficient Prime Check Ends-------
int main(){
    generatePrime(M);
    ll x,y;
    while(cin>>x>>y){
      vector<ll>p;
      if(x<=2)p.push_back(2);
      if(x%2==0)x++;
      for(int i=x;i<=y;i+=2){
        if(isPrimeEfficient(i))p.push_back(i);
      }
      if(p.size()<=1){
        printf("There are no adjacent primes.\n");
        continue;
      }
      ll mx = 0, mn = 1e12;
      for(int i=1;i<p.size();i++){
        mx = max(mx,p[i]-p[i-1]);
        mn = min(mn,p[i]-p[i-1]);
      }
      for(int i=1;i<p.size();i++){
        if(mn == p[i]-p[i-1]){
          printf("%lld,%lld are closest, ", p[i-1],p[i]);
          break;
        }
      }
      for(int i=1;i<p.size();i++){
        if(mx == p[i]-p[i-1]){
          printf("%lld,%lld are most distant.\n",p[i-1],p[i]);
          break;
        }
      }
      //cout<<mn<<" "<<mx<<endl;

    }
    return 0;
}
