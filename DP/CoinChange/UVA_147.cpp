#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[12][30002],a[]={5,10,20,50,100,200,500,1000,2000,5000,10000},ans;
double n;
ll rec(ll i,ll koto){
  if(i==11){
    if(!koto)return 1;
    else return 0;
  }
  ll res1=0,res2=0;
  if(dp[i][koto]!=-1)return dp[i][koto];
  if(koto-a[i]>=0)res1=rec(i,koto-a[i]);
  else res1=0;
  res2=rec(i+1,koto);
  return dp[i][koto]=res1+res2;

}
int main(int argc, char const *argv[]) {
  ////5freopen("0uput.txt","w",stdout);
  memset(dp,-1,sizeof(dp));
  while(1){
    scanf("%lf",&n);
    if(n==0.0)break;
    double kk= n * 10000.0;
    int k= kk/100;
    ans=rec(0,k);
    int temp=(int)log10(ans)+1;
    if(n>=10.0 && n<100.0)cout<<" ";
    else if(n>=0.0 && n<100.0)cout<<"  ";
    printf("%.2lf",n);
    for(int i=0;i<17-temp;i++)cout<<" ";
    cout<<ans<<endl;
  }
  return 0;
}
