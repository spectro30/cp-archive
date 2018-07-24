#include<bits/stdc++.h>
using namespace std;
int n,a[100006];
int binarySearch(int x,int high, int low)
{
    if(high<low)return -1;//base case
    int mid= low+ (high-low)/2;
    if(x==a[mid])return mid;// base case
    else if(x>a[mid])return binarySearch(x,mid-1,low);
    else return binarySearch(x,high,mid+1);
}
int main()
{
    cin>>n;
    memset(a,0,sizeof(a));
    for(int i=0;i<n;i++)cin>>a[i];
    int x;
    cin>>x;
    cout<<binarySearch(x,n-1,0)<<endl;
}
