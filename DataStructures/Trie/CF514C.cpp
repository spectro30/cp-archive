#define MX 600005
#include<bits/stdc++.h>
using namespace std;

bool ans;
struct node{
  int child[3],isWord,prefix;
  node(){
    memset(child,-1,sizeof(child));
    isWord = 0;
  }
}tnode[MX];
int cnt=0;
char s[MX];
void handao( char *s, int temp){
  if(s[0]=='\0'){
    tnode[temp].isWord++;
    return ;
  }
  int x = s[0]-'a';
  if(tnode[temp].child[x]==-1){
    cnt++;
    tnode[cnt] = node();
    tnode[temp].child[x]= cnt;
  }
  handao(s+1, tnode[temp].child[x]);
}

void wordcheck(char *s, int temp, int prb){
  if(s[0]=='\0'){
    if(tnode[temp].isWord && prb==1)ans = true;
    return ;
  }
  int x = s[0] - 'a';
  for(int i=0;i<3;i++){
    if(i==x && tnode[temp].child[i]!=-1) wordcheck(s+1,tnode[temp].child[i],prb);
    else if(i!=x && !prb && tnode[temp].child[i]!=-1) wordcheck(s+1,tnode[temp].child[i],prb+1);
  }
}
int main(){
  int n,m;
  cin>>n>>m;
  tnode[0]= node();
  for(int i=1;i<=n;i++){
    cin>>s;
    handao(s,0);
  }
  for(int i=1;i<=m;i++){
    ans = false;
    cin>>s;
    wordcheck(s,0,0);
    if(ans)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
  return 0;
}
