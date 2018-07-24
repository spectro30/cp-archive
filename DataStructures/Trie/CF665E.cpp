#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
  ll child[2],value,prefix;
  node(){
    memset(child,-1,sizeof(child));
    value = prefix = 0;
  }
}tnode[6000006];
ll cnt,pre_xor,k;
string s;

void handao(ll idx,ll temp){
  if(idx== 32){
    tnode[temp].prefix++;
    return;
  }
  tnode[temp].prefix++;
  ll x = s[idx]-'0';
  if(tnode[temp].child[x]==-1){
    cnt++;
    tnode[cnt] = node();
    tnode[temp].child[x]= cnt;
  }
  handao(idx+1, tnode[temp].child[x]);
}

ll dekho(ll idx, ll temp){
  if(idx==32){
    return tnode[temp].prefix;
  }
  ll x = s[idx]-'0';
  ll kk= (31-idx)<<1;
  if(tnode[temp].child[1-x]!=-1){
    cout<<k<<" "<<kk<<" "<<idx<<" ";
    cout<<tnode[temp].prefix<<endl;
    if(kk >=k)return tnode[temp].prefix;
    //dekho(idx+1,tnode[temp].child[1-x]);
  }
  else {
    if(kk> )
    dekho(idx+1,tnode[temp].child[x]);
  }
}

int main() {
  //freopen("out.txt","w",stdout);
  tnode[0]=node();
  ll n,x,ans;
  cnt = ans = pre_xor = 0;
  bitset<32>b(pre_xor);
  s = b.to_string();
  handao(0,0);
  scanf("%lld%lld",&n,&k);
  for(int i=1;i<=n;i++){
    scanf("%lld",&x);
    pre_xor ^= x;

    bitset<32>b(pre_xor);
    s = b.to_string();
    handao(0,0);
    cout<<dekho(0,0)<<endl;
    ans += dekho(0,0);

  }
  printf("%d\n",ans);
  return 0;
}
