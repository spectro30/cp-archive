#include <bits/stdc++.h>
using namespace std;
int dp[105][105];
int main(int argc, char const *argv[]) {
  int TC;
  cin>>TC;
  while(TC--){
    int n,x1,x2,y1,y2,q,temp,ans=0;
    cin>>n>>q;
    for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)dp[i][j]=1;
    for(int i=1;i<=q;i++){
      cin>>x1>>y1>>x2>>y2;
      for(int j=x1;j<=x2;j++){
        for(int k=y1;k<=y2;k++){
          dp[j][k]=0;
        }
      }
    }
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dp[i][j]+=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
    for(int x1=1;x1<=n;x1++){
      for(int y1=1;y1<=n;y1++){
        for(int x2=1;x2<=n;x2++){
          for(int y2=1;y2<=n;y2++){
            if(x2>=x1 && y2>=y1){
              temp=dp[x2][y2]-dp[x1-1][y2]-dp[x2][y1-1]+dp[x1-1][y1-1];
              if(temp== ((x2-x1+1)*(y2-y1+1)) ){
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
