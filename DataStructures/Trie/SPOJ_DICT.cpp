#define MX 1000000
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
ll ans,cnt,n;
struct node{
  int child[130];
  node(){
    memset(child,-1,sizeof(child));
  }
}tnode[MX];

void handao( int idx, int temp){
  if(idx==n){
    return ;
  }
  int x = s[idx];
  if(tnode[temp].child[x]==-1){
    ans++;
    cnt++;
    tnode[cnt] = node();
    tnode[temp].child[x]= cnt;
  }
  handao(idx+1, tnode[temp].child[x]);
}


int main(){
  int TC;
  scanf("%d",&TC);
  while(TC){
    ans = 0;
    tnode[0]= node();
    cnt = 0;
    cin>>s;
    n=s.size();
    for(int i=0;i<n;i++){
      handao(i,0);
    }
    printf("%lld\n",ans);
  }
  return 0;
}
