#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[1001][1001];
int cost[1001];
int n;

int solve(int i,int j)  
{
	if(i == j)
		return 0;
	if(dp[i][j] != -1)
		return dp[i][j];
	int mx = 0;
	dp[i][j] = cost[j-i];
	for(int k=i+1;k<=j;k++)
	{
		mx = max(mx,max(solve(i,k) + solve(k+1,j),cost[k-i] + cost[j-k]));
	}
	return dp[i][j] = mx;
}

signed main()
{ 
	

    memset(dp,-1,sizeof dp);
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> cost[i];
	}

	int ans = solve(0,n);

	cout << ans << '\n';


}