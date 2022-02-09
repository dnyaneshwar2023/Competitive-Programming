#include<bits/stdc++.h>
using namespace std;
#define int long long 
vector<pair<int,char>> g[100005];
int vis[100005];

void dfs(int u)
{
    vis[u] = 1;
    for(auto e:g[u])
    {
        char type = e.second;
        if(type == 'F')
            continue;
        int v = e.first;
            
        if(!vis[v])
            dfs(v);
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
    int k;
    cin >> k;

    for(int i=0;i<m;i++)
    {
        int a,b;
        cin >> a >> b;
        char type;
        cin >> type;
        g[a].push_back({b,type});
        g[b].push_back({a,type});
    }

    int count = 0;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            count++;
            dfs(i);
        }
    }

    cout << k*(count-1) << '\n';
    return 0;
}