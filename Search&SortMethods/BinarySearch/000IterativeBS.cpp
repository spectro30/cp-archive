#include<bits/stdc++.h>
using namespace std;
int n,a[100006];
int binarySearch(int x)
{
    int high,low,mid;
    high=n-1;
    low=0;
    while(high>=low){
        mid= low+ (high-low)/2;
        if(x==a[mid])return mid;
        else if(x>a[mid])low=mid+1;
        else high=mid-1;
    }
    return -1;
}
int main()
{
    cin>>n;
    memset(a,0,sizeof(a));
    for(int i=0;i<n;i++)cin>>a[i];
    int x;
    cin>>x;
    cout<<binarySearch(x)<<endl;
}
