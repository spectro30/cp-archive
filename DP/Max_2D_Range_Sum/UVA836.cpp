#include <bits/stdc++.h>
using namespace std;
int dp[30][30],a[30][30];
int main(int argc, char const *argv[]) {
  //freopen("0uput.txt","w",stdout);
  int TC;
  scanf("%d",&TC);
  getchar();
  while(TC--){
    int n,ans=0,temp;
    string s;
    getline(cin,s);
    getline(cin,s);
    n=s.size();
    for(int i=0;i<n;i++)a[1][i+1]=s[i]-'0';
    for(int i=2;i<=n;i++){
      getline(cin,s);
      for(int j=0;j<n;j++)a[i][j+1]=s[j]-'0';
    }
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        dp[i][j]=a[i][j]+dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];

      }
    }
    for(int x1=1;x1<=n;x1++){
      for(int y1=1;y1<=n;y1++){
        for(int x2=1;x2<=n;x2++){
          for(int y2=1;y2<=n;y2++){
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
    if(TC)printf("\n");

  }
  return 0;
}
