#include<bits/stdc++.h>
using namespace std;
#define int long long 
vector<int> g[100005];
int in[100005];
int low[100005];
int vis[100005];
int timer;
map<pair<int,int>,int> mp;
void dfs(int u,int par = -1)
{
    vis[u] = 1;
    in[u] = low[u] = timer++;

    for(auto v:g[u])
    {
        if(v == par)
            continue;
        if(vis[v])
        {
            low[u] = min(low[u],in[v]);

        }
        else
        {
            dfs(v,u);
            if(low[v]  > in[u])
                mp[{u,v}]=1;
            low[u] = min(low[u],low[v]);
        }
    }

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
        g[b].push_back(a);
        e.push_back({a,b});
    }

    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
            dfs(i);
    }

    vector<pair<int,int>> ans;
    for(auto edge:e)
    {
        if(mp.find({edge.first,edge.second})!=mp.end())
            ans.push_back(edge);
    }

    cout << ans.size() << '\n';

    for(auto it:ans)
    {
        cout << it.first << ' ' << it.second << '\n';
    }
    return 0;
    
}