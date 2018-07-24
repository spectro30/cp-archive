#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005],c[100005];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n/2;i++){
        cin>>a[i];
    }
    for(int i=0;i<n/2;i++){
        cin>>b[i];
    }
    int x,y;
    x=0,y=0;
    for(int i=0;i<n;i++){
        if(a[x]>b[y]){
            c[i]=b[y];
            y++;
        }
        else if(a[x]<b[y]){
            c[i]=a[x];
            x++;
        }
        if(y==n/2){
            c[i]=a[x];
            x++;
        }
        if(x==n/2){
            c[i]=b[y];
            y++;
        }
        cout<<x<<" "<<y<<endl;
    }

    for(int i=0;i<n;i++){
        cout<<c[i]<<" ";
    }

    return 0;
}
