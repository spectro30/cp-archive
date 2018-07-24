#include <bits/stdc++.h>
using namespace std;
#define MP(x, y) make_pair(x, y)
#define ff first
#define ss second
#define ll long long
#define ld long double
#define pii pair<ll,ll>
ll triArea(pii p1,pii p2,pii p3){
    return (p1.ff*p2.ss + p2.ff*p3.ss + p3.ff*p1.ss - p2.ff*p1.ss - p3.ff*p2.ss - p1.ff*p3.ss) ;//not divided by two, because i just need the sign;
}
int main()
{
  pii p1,p2,p3,p4;
  int x[4],y[4];
  for(int i=0;i<4;i++){
    cin>>x[i]>>y[i];
  }
  p1=MP(x[0],y[0]);
  p2=MP(x[1],y[1]);
  p3=MP(x[2],y[2]);
  p4=MP(x[3],y[3]);
  if (segmentIntersection(p1,p2,p3,p4))cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
  return 0;
}
