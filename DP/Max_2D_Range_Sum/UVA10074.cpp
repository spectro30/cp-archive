#include <bits/stdc++.h>
using namespace std;
int dp[1005][3][1005],a[1005],b[1005],n;
bool dir[1005][3][1005];
int rec(int pos,int kar, int temp){
  int res1,res2;
  //cout<<pos<<" "<<kar<<" "<<temp<<endl;
  if(pos==n && temp==n){
    return 1;
  }
  if(dp[pos][kar][temp]!=-1)return dp[pos][kar][temp];
  if(kar==1){
    if(a[pos]!=a[pos+1])res1=rec(pos+1,kar,temp);
    if(a[pos]!=b[temp])res2=rec(temp,2,pos+1);
  }
  else{
    if(b[pos]!=b[pos+1])res1=rec(pos+1,kar,temp);
    if(b[pos]!=a[temp])res2=rec(temp,1,pos+1);
  }
  if(res1 or res2)dir[pos][kar][temp]=true;
  return dp[pos][kar][temp]=res1 or res2;
}
int main(int argc, char const *argv[]) {
  memset(dp,-1,sizeof(dp));
  cin>>n;
  string s;
  cin>>s;
  for(int i=0;i<n;i++)a[i+1]=s[i]-'0';
  cin>>s;
  for(int i=0;i<n;i++)b[i+1]=s[i]-'0';
  int N=1,M=1;
  if(rec(1,2,1) || rec(1,1,1)){
    if(rec(1,1,1)){
      int temp=1;
      while(N!=n || M!=n){
        if(dir[N][temp][M]){
          if(dir[N+1][temp][M]){
            N++;
            cout<<temp<<" ";
          }
          else{
            M++;
            temp=0;
          }
        }
      }
    }
    else{

    }
  }
  return 0;
}
