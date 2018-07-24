#define MX 600005
#include<bits/stdc++.h>
using namespace std;

struct node{
  int child[26],isWord,prefix;
  node(){
    memset(child,-1,sizeof(child));
    isWord = prefix = 0;
  }
}tnode[MX];
int cnt=0;
char s[600006];
void handao( char *s, int temp){
  if(s[0]=='\0'){
    tnode[temp].isWord++;
    tnode[temp].prefix++;
    return ;
  }
  tnode[temp].prefix++;
  int x = s[0]-'a';
  if(tnode[temp].child[x]==-1){
    cnt++;
    tnode[cnt] = node();
    tnode[temp].child[x]= cnt;
  }
  handao(s+1, tnode[temp].child[x]);
}

bool wordcheck(char *s, int temp){
  if(s[0]=='\0'){
    if(tnode[temp].isWord)return true;
    else return false;
  }
  int x = s[0]-'a';
  if(tnode[temp].child[x]==-1){
    return false;
  }
  wordcheck(s+1,tnode[temp].child[x]);
}
int main(){
  int n,m;
  cin>>n>>m;
  tnode[0]=node();
  for(int i=1;i<=n;i++){
    cin>>s;
    handao(s,0);
  }
  for(int i=1;i<=m;i++){
    cin>>s;
    if(wordcheck(s,0))cout<<"Ase"<<endl;
    else cout<<"Nai"<<endl;
  }
  return 0;
}
