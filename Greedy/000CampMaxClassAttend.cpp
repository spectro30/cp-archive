#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

#define F first
#define S second
#define PB push_back
#define MP make_pair
int n,x[100006],y[100005];
int main(int argc, char const *argv[]) {
  int n;
  vector<pii> v;
  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>x[i]>>y[i];
    v.PB(MP(y[i],x[i]));
  }
  sort(v.begin(),v.end());
  int cnt=0,h=1,t=0;
  for(int i=0;i<n;i++){
    if(v[i].S < t ) continue;
    else{
      cnt++;
      t=v[i].F;
      //cout<<v[i].S<<" "<<v[i].F<<endl;
    }
  }
  cout<<cnt<<endl;
  return 0;
}
