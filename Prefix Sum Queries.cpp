#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
#define MAX 2001001
#define INF 0
 
 
struct node{
    int sum;
    int preffx;
};
 
int v[MAX];
node seg[4*MAX];
 
node combine(node a, node b){
    node r;
    r.sum = a.sum + b.sum;
    r.preffx = max(a.preffx, b.preffx + a.sum);
    
    return r;
}
 
node build(int p, int l, int r){
    if(l==r) return seg[p] = { v[l], v[l]};
    int m = (l+r)/2;
    return seg[p] = combine(build(2*p, l, m), build(2*p+1, m+1, r));
}
 
node query(int a, int b, int p, int l , int r){
    if(a>r || b<l) return {INF, INF};
    if(a<=l && b>=r) return seg[p];
    
    int m = (l+r)/2;
    return combine(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
}
 
node update(int i, int x, int p, int l, int r){
    if(i<l || i>r) return seg[p];
    if(l==r) return seg[p] = {x, x};
    int m = (l+r)/2;
    return seg[p] = combine(update(i, x, 2*p, l, m), update(i, x, 2*p+1, m+1, r));
}
 
void solve(){
    int n, c; cin>>n>>c;
    
    for(int i=0;i<n;i++)cin>>v[i];
    
    build(1, 0, n-1);
   
    while(c--){
        int t, a, b;
        cin>>t>>a>>b;
    a--;
        if(t==1)update(a, b, 1, 0, n-1);
        else { 
             b--;
            int resp = query(a, b, 1, 0, n-1).preffx;   
            if(resp>0)cout<<resp<<endl;
            else cout<<0<<endl;
        }
    }
    
}
 
signed main()
{
    solve();
}
