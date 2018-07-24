#define MX 10000000
#include<bits/stdc++.h>
using namespace std;
bool ans;
struct node{
  int child[10],prefix,isWord;
  node(){
    memset(child,-1,sizeof(child));
    isWord = prefix = 0;
  }
}tnode[MX];
int cnt=0;
string s;
void handao( int id, int temp){
  if(s[id]=='?'){
    if(tnode[temp].prefix)ans = false;
    tnode[temp].prefix++;
    tnode[temp].isWord++;
    //cout<<s<<" is ok"<<endl;
    return ;
  }
  tnode[temp].prefix++;
  int x = s[id]-'0';
  if(tnode[temp].child[x]==-1){
    if(tnode[temp].isWord)ans = false;
    cnt++;
    tnode[cnt] = node();
    tnode[temp].child[x]= cnt;
  }
  handao(id+1, tnode[temp].child[x]);
}

int main(){
  int TC;
  scanf("%d",&TC);
  while(TC--){
    //for(int i=0;i<=100000;i++)
    tnode[0]=node();
    int n;
    ans = true;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
      cin>>s;
      //scanf("%s\n",s);
      s+='?';
      handao(0,0);
    }
    if(ans)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
  return 0;
}
