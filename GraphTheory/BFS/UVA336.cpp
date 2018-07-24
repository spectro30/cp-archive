#include <bits/stdc++.h>
using namespace std;
#define MAX 205
int visited[205],color[205];
vector<int>v[MAX];
bool bfs(int s){
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
    int n,x,y;
    scanf("%d",&n);
    if(!n)break;
    for(int i=1;i<=n;i++){
      scanf("%d%d",&x,&y);
      v[x].push_back(y);
      v[y].push_back(x);
    }
    while(1){
      int s,d;
      scanf("%d%d",&s,&d);
      if(!s&&!d)break;
      bfs(s,d);
    }
    scanf("\n");
  }
  return 0;
}
