#include<bits/stdc++.h>
using namespace std;
#define MX 600005
struct node{
  int child[26];//all possible childs
  int isWord;
  int prefix;
  node(){//method overloading
    memset(child,-1,sizeof(child));
    isWord=0;
    prefix=0;
  }
}tnode[MX];
char s[1000006];
int cnt=0;
void handao(char *s,int temp){
  if(s[0]=='\0'){
    tnode[temp].isWord++;//pura ekta word
    tnode[temp].prefix++;
    return;
  }
  tnode[temp].prefix++;
  int x= s[0]-'a';// character to int convert
  if(tnode[temp].child[x]==-1){//ei letter er child nai
    cnt++;//notun node er jnno cnt
    tnode[cnt]=node();// cnt er node ke init kora
    tnode[temp].child[x]=cnt;// notun node ke current node er child banano
  }
  handao(s+1,tnode[temp].child[x]);// next char and child node call.
}
int soln(char *s,int temp){
  cout<<tnode[temp].prefix<<endl;
  int x=s[0]-'a';
  //if(!temp) return (soln(s+1,tnode[temp].child[x]));
  tnode[tnode[temp].child[x]].prefix--;
  if(tnode[temp].child[x]==-1 || tnode[tnode[temp].child[x]].prefix<=0 || s[0]=='\0'  ){
    return 0;
  }
  return 1+(soln(s+1,tnode[temp].child[x]));

}
int main(int argc, char const *argv[]) {
  int n,sum=0;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>s;
    handao(s,0);
  }
  for(int i=0;i<n;i++){
    cin>>s;
    sum+=soln(s,0);
  }
  cout<<sum<<endl;
  return 0;
}
