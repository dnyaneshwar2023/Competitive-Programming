

#include <bits/stdc++.h>
using namespace std;
#define int long 

vector<int> g[100005];
vector<int> gr[100005];
vector<int> G[100005];


int vis[100005];
int scc[100005];
const int maxN = 5e4+1;

bitset<maxN> ans[maxN];


vector<int> order;

void dfs(int u)
{
    vis[u] = 1;
    for(auto v:g[u])
    {
        if(!vis[v])dfs(v);
    }
    order.push_back(u);
}

void dfs2(int u,vector<int>& member){
    vis[u] = 1;
    member.push_back(u);
    for(auto v:gr[u])
    {
        if(!vis[v])dfs2(v,member);
    }
}

void dfs3(int u){
    vis[u] = 1;
    ans[u].set(u);
    for(auto v:G[u])
    {
        if(!vis[v])dfs3(v);
        ans[u]|=ans[v];

    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int n,m;
    cin >> n >> m;
    int k;
    cin >> k;

    for(int i=0;i<m;i++)
    {
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        gr[v].push_back(u);
    }

    for(int i=1;i<=n;i++){if(!vis[i]) dfs(i);}

    reverse(order.begin(),order.end());

    int sc = 1;
    memset(vis,0,sizeof vis);
    for(int i=0;i<order.size();i++)
    {
        int x = order[i];
        if(!vis[x])
        {
            vector<int> member;
            dfs2(x,member);

            for(int mm:member)
            {
                scc[mm] = sc;
            }
            sc++;
        }
    }

    memset(vis,0,sizeof vis);
    for(int i=1;i<=n;i++)
    {
        for(auto v:g[i])
        {
            G[scc[i]].push_back(scc[v]);
        }
    }

    for(int i=1;i<=n;i++)
    {
        if(!vis[scc[i]]) dfs3(scc[i]);
    }

    for(int i=0;i<k;i++)
    {
        int u,v;cin >> u >> v;
        u = scc[u];
        v = scc[v];
        if(ans[u][v])cout << "YES\n";
        else cout << "NO\n";
    }





    


    

    return 0;
}