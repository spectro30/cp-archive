#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int par[MAX];
int find(int a)
{
    if(par[a]==a)
        return a;

    return par[a]=find(par[a]);;
}
void un(int a,int b)
{
    int u=find(a);
    int v=find(b);
    if(u!=v)
        par[v]=u;
}
int main()
{
    int n=100,e;
    cin>>e;
    for(int i=0;i<n;i++)
        par[i]=i;
    int a,b;
    for(int i=0;i<e;i++)
    {
        cin>>a>>b;
        un(a,b);
    }
    sort(par,par+n);
    int pal=1,sum=0;
    for(int i=1;i<n;i++){
        if(par[i]==par[i+1]){
            pal++;
        }
        else{
            if(pal%2==0 && pal!=1)sum+=pal/2;
            else if(pal%2==1 && pal!=1) sum+=(pal/2)+1;
            pal=1;
        }
    }
    cout<<sum;
}
