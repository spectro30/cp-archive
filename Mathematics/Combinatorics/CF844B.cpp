#include <bits/stdc++.h>
using namespace std;
typedef long long unsigned iu;
iu a[105][105];
iu nChoosek( iu n, iu k )
{
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

    iu result = n;
    for( iu i = 2; i <= k; ++i ) {
        result *= (n-i+1);
        result /= i;
    }
    return result;
}
int main(int argc, char const *argv[]) {
  iu n,m,ans=0,cnt,pnt;
  cin>>n>>m;
  ans+= (n*m);
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      cin>>a[i][j];
    }
  }
  for(int i=1;i<=n;i++){
    cnt=0;pnt=0;
    for(int j=1;j<=m;j++){
      if(a[i][j])cnt++;
      else pnt++;
    }
    for(int j=2;j<=cnt;j++){
      ans+=nChoosek(cnt,j);
    }
    for(int j=2;j<=pnt;j++){
      ans+=nChoosek(pnt,j);
    }

  }
  for(int i=1;i<=m;i++){
    cnt=0;pnt=0;
    for(int j=1;j<=n;j++){
      if(a[j][i])cnt++;
      else pnt++;
    }
    for(int j=2;j<=cnt;j++){
      ans+=nChoosek(cnt,j);
    }
    for(int j=2;j<=pnt;j++){
      ans+=nChoosek(pnt,j);
    }
  }
  cout<<ans<<endl;

  return 0;
}
