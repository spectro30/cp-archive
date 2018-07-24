#include <bits/stdc++.h>
using namespace std;
#define MAX 205
int visited[205],color[205];
pair<int,int>p;
vector<int>v[MAX];
bool bfs(int s){
  bool ans=true;
  memset(visited,0,sizeof(visited));
  memset(color,-1,sizeof(color));
  queue<int>q;
  q.push(s);
  color[s]=0;
  while(!q.empty()){
    int temp=q.front();
    q.pop();
    visited[temp]=1;
    for(int i=0;i<v[temp].size();i++){
      if(!visited[v[temp][i]]){
        q.push(v[temp][i]);
        color[v[temp][i]]= ((color[temp]&1)+1)&1;
      }
      if(color[temp]==color[v[temp][i]])ans=false;
    }
  }
  return ans;
}
int main(int argc, char const *argv[]) {
  while(1){
    int n,e,x,y;
    scanf("%d",&n);
    if(!n)break;
    for(int i=0;i<n;i++)v[i].clear();
    scanf("%d",&e);
    for(int i=1;i<=e;i++){
      scanf("%d%d", &x,&y);
      v[x].push_back(y);
      v[y].push_back(x);
    }
    if(bfs(0))printf("BICOLORABLE.\n");
    else printf("NOT BICOLORABLE.\n");

  }
  return 0;
}
