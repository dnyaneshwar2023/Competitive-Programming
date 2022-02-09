#include <bits/stdc++.h>
#include <vector>
 
using namespace std;
 
#define int long long
const int MAX_SIZE = 200005;
const int MAX_LEVELS = 18;
 
vector<pair<int,int>> graph[200005];
 
int depth[MAX_SIZE];
int parents[MAX_SIZE][MAX_LEVELS];
int maximum[MAX_SIZE][MAX_LEVELS];
int vis[200005];
 
void dfs(int node, int parent,int weight) { // dfs to assign depths in the tree
    parents[node][0] = parent;
    vis[node] = 1;
    maximum[node][0] = max(weight,0LL);
    
    for (auto e : graph[node]) {
        int i = e.first;
        int cost = e.second;
        if (i != parent) {
            depth[i] = depth[node] + 1;
            dfs(i, node, cost);
        }
    }
}
int lca(int u, int v) {
    if (depth[u] < depth[v]) {
        swap(u, v);
    }
    int ans = 0;
 
    for (int i = MAX_LEVELS - 1; i >= 0; i --) {
        if (depth[u] >= depth[v] + (1 << i)) {
            ans = max(ans,maximum[u][i]);
            u = parents[u][i];
            
        }
    }
    if (u == v) {
        return ans;
    }
    for (int i = MAX_LEVELS - 1; i >= 0; i --) {
        if (parents[u][i] != 0 && parents[u][i] != parents[v][i]) {
            ans = max({ans,maximum[u][i],maximum[v][i]});
            u = parents[u][i];
            
            v = parents[v][i];
            
        }
    }
    ans = max(ans, max(maximum[v][0], maximum[u][0]));
 
    return ans;
}
 
 
int par[200005];
int find(int i)
{
    if(par[i] == i)return i;
    return par[i] = find(par[i]);
 
}
void merge(int a,int b)
{
    a = find(a);
    b = find(b);
    par[a] = b;
}
 
int32_t main() {
   
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n,m,k;
        cin >> n >> m >> k;
        memset(depth,0,sizeof depth);
        memset(parents,0,sizeof parents);
 
        for(int i=1;i<=n;i++)par[i] = i;
 
        int d = 0;
        int in[200005];
        memset(in,0,sizeof in);
        for(int i=0;i<m;i++)
        {
            d++;
            int u,v;
            cin >> u >> v;
            
            if(find(u) == find(v))continue;
            
            merge(u,v);
            
            graph[u].push_back({v,d});
             graph[v].push_back({u,d});
           
        }
 
        for(int i=1;i<=n;i++)
        {
            if(vis[i] == 0)
                dfs(i,0,0);
            
        }
        
    
        for (int i = 1; i < MAX_LEVELS; i ++) {
            for (int j = 1; j <= n; j ++) {
                if (parents[j][i - 1] != 0) {
                    parents[j][i] = parents[parents[j][i - 1]][i - 1];
                    maximum[j][i] = max(maximum[j][i-1],maximum[parents[j][i-1]][i-1]);
                }
            }
        }
 
 
        for(int i=0;i<k;i++)
        {
            int u,v;
            cin >> u >> v;
 
            if(find(u) !=find(v))
            {
                cout << -1 << '\n';
                continue;
            }
 
            int ans;
            ans = lca(u,v);
 
            cout << ans << '\n';
        }
 
     
 
 
 
 
    
    return 0;
}