#include<bits/stdc++.h>
using namespace std;
int par[110];
int findd(int r){
    if (par[r]==r) return r;
    par[r]=findd(par[r]);
    return par[r];
}
void unionn(int a,int b){
    int u=findd(a);
    int v=findd(b);
    par[u]=v;
    return ;
}

int main(){
    int n,m,x,zero=0,cnt,one=0;
    vector<int>v[105];
    map<int,bool>mp;
    cin>>n>>m;
    for(int i=1;i<=n;i++)par[i]=i;
    for(int i=1;i<=n;i++){
      cin>>cnt;
      if(!cnt)zero++;
      if(cnt==1)one++;
      for(int j=1;j<=cnt;j++){
        cin>>x;
        v[i].push_back(x);
      }
    }
    for(int i=1;i<=n;i++){
      if(v[i].empty())continue;
      int temp, prev;
      prev= v[i][0];
      temp = v[i].size();
      for(int j=1;j<temp;j++){
        unionn(prev,v[i][j]);
        mp[prev]=true;
        mp[v[i][j]]=true;
        prev= v[i][j];
      }
    }
    int ans=0;
    set<int> st;
    for(int i=1;i<=n;i++){
      if(v[i].empty())continue;
      if(v[i].size()==1 && !mp[v[i][0]]){
        mp[v[i][0]]= true;
        //cout<<v[i][0]<<" ";
        ans++;
        continue;
      }
      int temp;
      temp = v[i].size();
      for(int j=1;j<temp;j++){
        st.insert(findd(v[i][j]));
      }
    }
    if(zero+one == n && one){
      cout<<n-1<<endl;
      return 0;
    }
    if(!st.empty())ans+=st.size()-1;
    cout<<ans+zero<<endl;
    return 0;
}
