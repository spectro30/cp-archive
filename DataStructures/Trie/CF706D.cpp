#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
  ll child[2],value,prefix;
  node(){
    memset(child,-1,sizeof(child));
    prefix = value = 0;
  }
}tnode[6000006];
ll cnt,xx,n;
string s;

void handao(ll idx,ll temp){
  if(idx== 32){
    //tnode[temp].prefix++;
    tnode[temp].value = xx;
  }
  if(idx== 33){
    //tnode[temp].prefix++;
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

void mucho(ll idx, ll temp){
  if(idx==33){
    tnode[temp].value = 0;
    return;
  }
  ll x = s[idx]-'0';
  tnode[temp].prefix--;
  if(tnode[temp].child[x]!=-1)mucho(idx+1, tnode[temp].child[x]);

}

ll dekho(ll idx, ll temp){
  if(idx==32){
    //cout<<tnode[temp].value<<endl;
    cout<<idx<<" "<<tnode[temp].prefix<<endl;
    return ((tnode[temp].value)^xx);
  }
  ll x = s[idx]-'0';
  cout<<idx<<" "<<tnode[temp].prefix<<endl;
  if(tnode[temp].child[1-x]!=-1 && tnode[temp].prefix){
    //cout<<'0'<<endl;
    dekho(idx+1,tnode[temp].child[1-x]);
  }
  else dekho(idx+1,tnode[temp].child[x]);
}

int main() {
  tnode[0]=node();
  char c;
  cin>>n;
  bitset<32>b(0);
  s = b.to_string();
  s+='?';
  handao(0,0);
  while(n--){
    cin>>c>>xx;
    bitset<32>b(xx);
    s = b.to_string();
    s+='?';
    //cout<<s<<endl;
    if(c=='?')cout<<dekho(0,0)<<endl;
    else if(c=='-')mucho(0,0);
    else handao(0,0);

  }
  return 0;
}
