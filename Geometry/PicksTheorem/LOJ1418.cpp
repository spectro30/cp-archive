////PICKS THEOREM
// FORMULA A= i+(b/2)-1; where(A=area of Polygon; i=strictly inside polygon points;b=onLinePoints)
#include <bits/stdc++.h>
using namespace std;
#define MP(x, y) make_pair(x, y)
#define PB(x) push_back(x)
#define SZ(c) (int)c.size()
#define ff first
#define ss second
#define ll long long
#define ld long double
#define pii pair<ll,ll>
int main()
{
  int TC;
  scanf("%d",&TC);
  for(int ii=1;ii<=TC;ii++){
    int n,a[10005],b[10005],lat=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
      scanf("%d%d",&a[i],&b[i]);
    }
    a[n+1]=a[1];b[n+1]=b[1];
    for(int i=1;i<=n;i++){
      if(a[i]==a[i+1]){
        lat+=abs(b[i]-b[i+1]);
      }
      else if(b[i]==b[i+1]){
        lat+= abs(a[i]-a[i+1]);
      }
      else{
        lat+= __gcd(abs(a[i]-a[i+1]), abs(b[i]-b[i+1]));
      }
    }
    ll sum=0,temp;
    for(int i=1;i<=n;i++){
      sum-= a[i]*b[i+1];
      sum+= b[i]*a[i+1];
    }
    sum= abs(sum);
    temp= sum-lat;
    temp/=2;
    cout<<sum<<endl;
    printf("Case %d: %d\n",ii,temp);
  }
  return 0;
}
