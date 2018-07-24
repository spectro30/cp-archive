#include<bits/stdc++.h>
using namespace std;
int a[1000006];
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
    //cout<<"B+G=="<<i+1<<endl;
    return i+1;

}
void quickSort(int low,int high)
{
    if(low<high){
        int p=parTion(low,high);
        quickSort(low,p-1);
        quickSort(p+1,high);
    }

}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    quickSort(0,n-1);
    for(int i=0;i<n;i++)cout<<a[i]<<" ";
    return 0;
}

