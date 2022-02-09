#include <bits/stdc++.h>
#include <vector>

using namespace std;
#define int long long
const int MAX_SIZE = 200005;
const int MAX_LEVELS = 30;

vector<vector<int>> graph;

int depth[MAX_SIZE];
int parents[MAX_SIZE][MAX_LEVELS];

void dfs(int node, int parent) { // dfs to assign depths in the tree
    parents[node][0] = parent;
    for (int i: graph[node]) {
        if (i != parent) {
            depth[i] = depth[node] + 1;
            dfs(i, node);
        }
    }
}
int lca(int u, int v) {
    if (depth[u] < depth[v]) {
        swap(u, v);
    }
    for (int i = MAX_LEVELS - 1; i >= 0; i --) {
        if (depth[u] >= depth[v] + (1 << i)) {
            u = parents[u][i];
        }
    }
    if (u == v) {
        return u;
    }
    for (int i = MAX_LEVELS - 1; i >= 0; i --) {
        if (parents[u][i] != 0 && parents[u][i] != parents[v][i]) {
            u = parents[u][i];
            v = parents[v][i];
        }
    }
    return parents[u][0];
}


int32_t main() {
   
   




    int t;
    cin >> t;
    while(t--)
    {
        int n,k,a;
        cin >> n >> k >> a;
        graph.clear();
        memset(depth,0,sizeof depth);
        memset(parents,0,sizeof parents);


        std::vector<int> s;
        for(int i=0;i<k;i++)
        {
            int x;cin >> x;
            s.push_back(x);
        }
        int N = n;
        graph.resize(N + 1);
        for (int i = 1; i < N; i ++) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        dfs(a, 0);
        for (int i = 1; i < MAX_LEVELS; i ++) {
            for (int j = 1; j <= N; j ++) {
                if (parents[j][i - 1] != 0) {
                    parents[j][i] = parents[parents[j][i - 1]][i - 1];
                }
            }
        }

        vector<int> ans;
        for(int i=1;i<=n;i++)
        {
            int mx = -10000000000000;
            int id;

            for(auto node:s)
            {
                int l = lca(i,node);

                int d = depth[i] + depth[node] - 2*depth[l];
                d = depth[node] - d;

                if(d>mx)
                {
                    mx = d;
                    id = node;
                }
            }
            cout << mx << ' ';
            ans.push_back(id);
        }
        cout << '\n';
        for(auto i:ans)cout << i << ' ';
            cout << '\n';
        
    }
    




    
    return 0;
}