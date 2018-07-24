#include <bits/stdc++.h>
using namespace std;
int dp[105][105],a[105][105];
int main(int argc, char const *argv[]) {
  //freopen("0uput.txt","w",stdout);
  while(1){
    //memset(a,0,sizeof(a));
    //memset(dp,0,sizeof(a));
    int n,m,ans=0,temp;
    scanf("%d%d",&n,&m);
    if(!n&&!m)break;
    for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
        scanf("%d",&a[i][j]);
        a[i][j]!=a[i][j];
      }
    }
    for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
        dp[i][j]=a[i][j]+dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];

      }
    }
    for(int x1=1;x1<=n;x1++){
      for(int y1=1;y1<=m;y1++){
        for(int x2=1;x2<=n;x2++){
          for(int y2=1;y2<=m;y2++){
            if(x2>=x1 && y2>=y1){
              temp=dp[x2][y2]-dp[x1-1][y2]-dp[x2][y1-1]+dp[x1-1][y1-1];
              if(temp== ((x2-x1+1)*(y2-y1+1)) ){
                //cout<<temp<<" "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
                ans=max(ans,temp);
              }
            }
          }
        }
      }
    }
    printf("%d\n",ans);
  }
  return 0;
}
