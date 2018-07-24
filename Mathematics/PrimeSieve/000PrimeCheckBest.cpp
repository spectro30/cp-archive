#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000006

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



}
