#define pb push_back
#define ff first
#define ss second
#define ll long long
#define MX 100005
#include <bits/stdc++.h>
using namespace std;

//Initilize the MX


int a[MX],sum[(MX*4)],lazy[(MX*4)];

void relax(int node, int start, int end){
    sum[node] += (end - start + 1) * lazy[node];
    if(start != end){
        lazy[2*node] += lazy[node];
        lazy[(2*node)+1] += lazy[node];
    }
    lazy[node] = 0;
}

void update(int node, int start, int end, int i, int j, int val){
    if(lazy[node])relax(node,start,end);
    if(start>j || end<i || start>end)return ;
    if(i<=start && end<=j){
        lazy[node] += val;//putting the flag
        relax(node,start,end);
        return;
    }
    int mid = (start + end) / 2;
    update(node*2, start, mid, i, j, val);
    update((node*2)+1, mid+1, end, i, j, val);
    sum[node] = sum[node*2] + sum[(node*2)+1];
}

int query(int node, int start, int end, int i, int j){
    if(lazy[node])relax(node,start,end);
    if(start>j || end<i || start>end)return 0;//return something avoidalbe
    if(i<=start && end<=j){
        return sum[node];
    }
    //cout<<start<<" "<<end<<endl;
    //get the answer for left and right child;
    int p,q;
    int mid = (start+end) / 2;
    p = query(node*2 ,start, mid, i, j);
    q = query((node*2)+1, mid+1, end, i, j);
    return p+q;
    //return the calculated value of childs
}

void build(int node,int start, int end){
    if(start == end){
        sum[node] = a[start];
        //leaf node value
        return;
    }
    int mid = (start + end) / 2;
    build(node*2, start, mid);
    build((node*2)+1 , mid+1, end);
    sum[node] = sum[node*2] + sum[(node*2)+1];
    // put the upper nodes calculated values here
}


int main(int argc, char const *argv[]) {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    build(1,1,n);


}
