
/* Given a directed graph with n nodes and m edges.You are required to find
   the maximum number of nodes you can visit starting from any node.You may visit
   several nodes any number of times.(Starting node is also counted)
   There may or may  not be cycles in graph

   test:
    6 7
    1 2
    2 3
    3 1
    2 4
    4 5
    5 6
    6 4

    answer: 6

    1 -- 2 -- 3 -- 4 -- 5 -- 6

*/

#include<bits/stdc++.h>
using namespace std;
#define int long long 
vector<int> g[100005];
vector<int> g2[100005];
int vis[100005];
int dp[100005];
set<int> gg[100005];
vector<int> order;
int scc[100005];
int sz[100005];
void dfs(int u)
{
    vis[u] = 1;

    for(auto v:g[u])
    {
        if(!vis[v])
        dfs(v);
    }
    order.push_back(u);
}

void dfs2(int u,int id,int& count)
{
    vis[u] = 1;
    count++;
    scc[u]=id;
    for(auto v:g2[u])
    {
        if(!vis[v])
        dfs2(v,id,count);
    }
}

void dfs3(int u)
{
    vis[u]=1;
    for(auto v:gg[u])
    {
        if(!vis[v]){
            dfs3(v);
        }
        dp[u] = max(dp[u],dp[v]);
    }
    dp[u]+=sz[u];
}


signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>> e;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g2[b].push_back(a);
        e.push_back({a,b});
    }

    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
            dfs(i);
    }

    memset(vis,0,sizeof vis);
    reverse(order.begin(),order.end());
    int c = 1;

    for(int i=0;i<order.size();i++)
    {
        if(!vis[order[i]])
        {
            int count = 0;
            dfs2(order[i],c,count);
            sz[c] = count;
            c++;
        }
    }

    for(int i=0;i<m;i++)
    {
        int from = e[i].first;
        int to = e[i].second;

        if(scc[from]!=scc[to])
        {
            gg[scc[from]].insert(scc[to]);
        }
    }

    int maxi = 0;

    memset(vis,0,sizeof vis);
    memset(dp,0,sizeof dp);

    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
            dfs3(i);
    }

    for(int i=1;i<=n;i++)
    {
        maxi = max(maxi,dp[i]);
    }


    cout << maxi << '\n';

    return 0;
    
} 