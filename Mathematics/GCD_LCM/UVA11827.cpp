#define ll long long
#define pb push_back
#define mpr make_pair
#define ff first
#define ss second
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
  string s;
  int TC;
  cin>>TC;
  getline(cin,s);
  while(TC--){
    int x,ans=0,v[1000],cnt;

    getline(cin,s);
    istringstream is(s);
    cnt=0;
    while(is>>v[cnt])cnt++;
    for(int i=0;i<cnt;i++){
      for(int j=i+1;j<cnt;j++){
        ans = max(ans,__gcd(v[i],v[j]));
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}
