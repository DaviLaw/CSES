#include <bits/stdc++.h>

using namespace std;

#define db cout<<"oi"<<endl;
#define int long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
int block;
int v[200200];
int freq[200200];
int dist = 1;

struct Query{
    int L;
    int R;
    int Index;
    int result;
};

bool compare(Query a, Query b)
{
    if(a.L/block != b.L/block) return a.L/block < b.L/block;

    return a.R < b.R;
}

void solve(vector<Query> &queries, int n)
{
    
}

signed main(){
    fast_io;
    int n, m; cin>>n>>m;

    map<int , int> compress;

    int num_compress = 1;

    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        if(compress.find(v[i])!=compress.end()){
            v[i] = compress[v[i]];
        }
        else{
             compress[v[i]] = num_compress;
            v[i] = num_compress++;
        }
    }
    vector<Query> q(m);
    for(int i=0;i<m;i++){
        int a, b; cin>>a>>b;
        a--; b--;
        q[i].L = a;
        q[i].R = b;
        q[i].Index = i;
    }

    block = (int)sqrt(n);
    vector<int> ans(q.size());
    sort(q.begin(), q.end(), compare);
    memset(freq, 0, sizeof(freq));

    int ponteiro_L = 0;
    int ponteiro_R = 0;
    
    freq[v[ponteiro_L]]++;
    
    for(auto &u: q)
    {
        while(ponteiro_L < u.L){
            int id = v[ponteiro_L];
            if(freq[id]==1) dist--; 
            freq[id]--;
            ponteiro_L++;
        }

        while(ponteiro_L > u.L){
            ponteiro_L--;
            int id = v[ponteiro_L];
            if(freq[id]==0) dist++; 
            freq[id]++;
        }

        while(ponteiro_R > u.R){
            int id = v[ponteiro_R];
            if(freq[id]==1) dist--; 
            freq[id]--;
            ponteiro_R--;
        }
        
        while(ponteiro_R < u.R){
            ponteiro_R++;
            int id = v[ponteiro_R];
            if(freq[id]==0) dist++; 
            freq[id]++;
        }

        ans[u.Index] = dist;
    }

    for(auto u : ans){
        cout<<u<<endl;
    }
}
