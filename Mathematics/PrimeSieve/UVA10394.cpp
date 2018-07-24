#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

//----------primne starts here-------------
bool marked[20000006];
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

vector<int> generatePrime(int n){
  sieve(n);
  vector<int>v;
  for(int i=1;i<=n;i++){
    if(isprime(i) && isprime(i+2))v.push_back(i);
  }
  return v;
}

//-----------------prime end here-----------
int main(){
    vector<int>v;
    v = generatePrime(20000000);
    int n;
    while(scanf("%d",&n)!=EOF){
      printf("(%d, %d)\n",v[n-1],v[n-1]+2);
    }


}
