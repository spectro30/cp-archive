#include<bits/stdc++.h>
using namespace std;
struct node{
  int child[3];int flag;
  node(){
    memset(child,-1,sizeof(child));
    flag = 0;
  }
}tnode[600006];
char s[200006];
int cnt=0;
void tinsert(char *s, int cur){
  //cout<<s<<" "<<cur<<endl;
  if(s[0]=='\0'){
    tnode[cur].flag=1;
    return;
  }
  int x=s[0]-'a';
  if(tnode[cur].child[x]==-1){
    cnt++;
    tnode[cnt] = node();
    tnode[cur].child[x]=cnt;
  }
  tinsert(s+1,tnode[cur].child[x]);
}
bool tquery(char *s, int cur, int skip){
  cout<<s[0]<<" "<<cur<<" "<<skip<<endl;
  if(s[0]=='\0'){
    cout<<"hi"<<endl;
    if(tnode[cur].flag && skip)return true;
    return false;
  }
  int x=s[0]-'a';
  if(skip){
    if(tnode[cur].child[x]==-1)return false;
    return tquery(s+1,tnode[cur].child[x],skip);
  }
  else{
    for(int i=0;i<3;i++){
      if(tnode[cur].child[x]==-1)continue;
      int ts=0;
      if(x!=i)ts=1;
      bool z= tquery(s+1,tnode[cur].child[i],ts);
      if(z)return true;

    }

  }
  return false;

}
int main(int argc, char const *argv[]) {
  int n,q;
  cin>>n>>q;
  for(int i=0;i<n;i++){
    cin>>s;
    tinsert(s,0);
  }
  for(int i=0;i<q;i++){
    cin>>s;
    if(tquery(s,0,0))cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
  // for(int i=0;i<cnt;i++){
  //   for(int j=0;j<3;j++){
  //     cout<<tnode[i].child[j]<<" ";
  //   }
  //   cout<<endl;
  // }
  return 0;
}
