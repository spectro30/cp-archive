#define ll long long
#define pb push_back
#define mpr make_pair
#define ff first
#define ss second
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
  int  TC;
  scanf("%d",&TC);
   for(int ii=1;ii<=TC;ii++){
     ll n,a[100],ans = 0,temp;
     bool marked[100];
     scanf("%lld",&n);
     for(int i=1;i<=n;i++)marked[i]=false;
     for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
     //cout<<"OK"<<endl;

     for(int ik=1;ik<=n/2;ik++){
       if(ik%2==1){
         ll mx_xor = 0;
         for(int i=1;i<=n;i++){
           for(int j=1;j<=n;j++){
             if(!marked[i] && !marked[j]){
               mx_xor = max(mx_xor,a[i]^a[j]);
             }
           }
         }
         for(int i=1;i<=n;i++){
           for(int j=1;j<=n;j++){
             if(!marked[i] && !marked[j] && (a[i]^a[j])==mx_xor){
               marked[i] = true;
               marked[j] = true;
             }
           }
         }
         ans += mx_xor;
       }
       else{
         ll min_xor = 1000000000000;
         for(int is=1;is<=n;is++){
           for(int js=1;js<=n;js++){
             if(!marked[js] && !marked[is]){
               marked[js] = marked[is] = true;
               ll mx_xor = 0;
               for(int i=1;i<=n;i++){
                 for(int j=1;j<=n;j++){
                   if(!marked[i] && !marked[j]){
                     mx_xor = max(mx_xor,a[i]^a[j]);
                   }
                 }
               }
               min_xor = min(min_xor,mx_xor);
               marked[js] = marked[is] = false;
             }
           }
         }
         bool paisi = false;
         for(int is=1;is<=n;is++){
           for(int js=1;js<=n;js++){
             if(!marked[js] && !marked[is]){
               marked[js] = marked[is] = true;
               ll mx_xor = 0;
               for(int i=1;i<=n;i++){
                 for(int j=1;j<=n;j++){
                   if(!marked[i] && !marked[j]){
                     mx_xor = max(mx_xor,a[i]^a[j]);
                   }
                 }
               }
               if(mx_xor = min_xor){
                 paisi = true;
                 break;
               }
               else marked[js] = marked[is] = false;
             }
             if(paisi)break;
           }
         }

       }
     }
     printf("%lld\n",ans);
   }
  return 0;
}
