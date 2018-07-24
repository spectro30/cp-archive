//Problem: Given an array of n distinct numbers and an integer k, return the k-th highest number in O(n) time.
#include<bits/stdc++.h>
using namespace std;
int a[1000006],n,k;
int parTion ( int low, int high)
{
    int pivot=a[high];
    int i=low-1;
    for(int j=low ; j<=high-1 ;j++){
        if(a[j]<=pivot){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[high]);
    cout<<a[i+1]<<"=="<<a[high]<<endl;
    return i+1;

}
void quickSort(int low,int high)
{
    if(low<high){
        int p=parTion(low,high);
        cout<<"Pivot = "<<p<<endl;
        if(p==n-k+1){
            cout<<a[p]<<endl;
            return;
        }

        quickSort(low,p-1);
        quickSort(p+1,high);
    }

}

int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    quickSort(1,n);
    //for(int i=0;i<n;i++)cout<<a[i]<<" ";
    return 0;
}
