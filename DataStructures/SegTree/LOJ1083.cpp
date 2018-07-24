//Unsolved
#define pb push_back
#define ff first
#define ss second
#define ll long long
#define MX 100005
#include <bits/stdc++.h>
using namespace std;

int a[MX];
int main(int argc, char const *argv[]) {
    //freopen("0uput.txt","w",stdout);
    int TC;
    scanf("%d", &TC);
    for(int ii=1;ii<=TC;ii++){
        int n,mx=0;
        scanf("%d", &n);
        for(int i=1;i<=n;i++)scanf("%d", &a[i]);
        stack<int>st;
        for(int i=1;i<=n;i++){
            if(st.empty())st.push(a[i]);
            else{
                int cnt = 0;
                while(!st.empty()){
                    int temp = st.top();
                    if(a[i]>=temp)break;
                    cnt++;
                    mx = max(mx, temp*cnt);
                    st.pop();
                }
                st.push(a[i]);
            }
        }
        printf("Case %d: %d\n", ii, mx);
    }


}
