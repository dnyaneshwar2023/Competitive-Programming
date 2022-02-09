#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1000000007;
int par[100005];
int find(int i)
{
	if(par[i] == i)return i;
	return par[i] = find(par[i]);
}
void union_(int a,int b)
{
	a = find(a);
	b = find(b);
	if(a==b)
		return;
	par[b]=a;

}

signed main()
{
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif  
 
 	int t;
 	cin >> t;

 	while(t--)
 	{
 		int n,k;
 		
 		cin >> n >> k;
 		for(int i=1;i<=n;i++)par[i] = i;
 		int f = 0;
 		for(int i=0;i<k;i++)
 		{
 			int t,x,y;
 			cin >> t >> x >> y;
 			if(x>n || y>n){
 				f++;
 				continue;
 			}
 			if(t==1)
 			{	
 				union_(x,y);
 			}
 			else {

 				if(find(x) == find(y))
 				{
 					f++;
 					continue;
 				}
 			}
 		}
 		cout << f << '\n';
 	}
}
