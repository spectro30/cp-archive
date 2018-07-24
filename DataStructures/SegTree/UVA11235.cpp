#define MX 100005
#define set0(x) memset(x,0,sizeof x)
#include<bits/stdc++.h>
using namespace std;

struct data{
    int leftmost, rightmost, ans, lf, rf;
};

int a[MX],  arr[MX];
data sum[MX*4];

data make_data(int val, int ok){
    data res;
    if(!ok){
        res.leftmost = res.rightmost = val;
        res.ans = res.lf = res.rf = 0;
        return res;
    }
    res.leftmost = res.rightmost = val;
    res.ans = res.lf = res.rf = 1;
    return res;
}

data combine(data l, data r){
    data res;
    if(l.rightmost == r.leftmost) res.ans = max(max(l.ans,r.ans), (l.rf+r.lf) );
    else res.ans = max(l.ans,r.ans);
    res.leftmost = l.leftmost;
    res.rightmost = r.rightmost;
    if(l.leftmost == r.leftmost)res.lf = l.lf + r.lf;
    else res. lf = l.lf;
    if(l.rightmost == r.rightmost) res.rf = l.rf + r.rf;
    else res.rf = r.rf;

    return res;
}

data query(int node, int start, int end, int i, int j){
    if(start > j || end<i || start > end)return make_data(0,0);
    if(i<=start && end<=j){
        return sum[node];
    }
    data p,q;
    int mid = (start + end) / 2;
    p = query(node*2, start, mid, i, j);
    q = query(node*2 + 1, mid+1, end, i, j);
    return combine(p,q);


}

void build(int node, int start, int end){
    if(start == end){
        sum[node] = make_data(arr[start],1);
        return;
    }
    int mid = (start + end) / 2;
    build(node*2, start, mid);
    build(node*2 + 1, mid+1, end);
    sum[node] = combine(sum[node*2],sum[node*2+1]);
}


int main(){

    while(1){
        set0(a); set0(sum); set0(arr);
        int n,q;
        scanf("%d", &n);
        if(!n)break;
        scanf("%d", &q);
        for(int i=1;i<=n;i++){
            scanf("%d", &arr[i]);
        }
        build(1, 1, n);
        for(int i=1;i<=q;i++){
            int l,r;
            data f;
            scanf("%d%d", &l, &r);
            f = query(1, 1, n, l, r);
            printf("%d\n",f.ans);
        }
    }
    return 0;
}
