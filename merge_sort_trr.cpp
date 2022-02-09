#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 100000000000;
const int N = 300005;
int a[N];
int b[N];
vector<int> st[4*N];
void build(int index,int start,int end)
{
	if(start == end)
	{
		st[index].push_back(a[start]);
		return;
	}
 
	int mid = (start+end)/2;
 	build(2*index,start,mid);
 	build(2*index+1,mid+1,end);
	int i = 0;
	int j = 0;

	while(i<(int)st[2*index].size() &&  j<(int)st[2*index+1].size())
	{
		if(st[2*index][i]<=st[2*index+1][j]){
			st[index].push_back(st[2*index][i]);i++;
		}
		else{
			st[index].push_back(st[2*index+1][j]);j++;
		}
	}
	while(i<(int)st[2*index].size())
	{
		st[index].push_back(st[2*index][i]);i++;
	}
	while(j<(int)st[2*index+1].size())
	{
		st[index].push_back(st[2*index+1][j]);j++;
	}
}
int query(int index,int start,int end,int qs,int qe,int k)
{
	if(qs > end || qe < start)
		return 0;

	if(start>=qs && end<=qe){
		if(start == end)
		{
			return st[index][0]>=k;
		}

		int d = st[index].end() - lower_bound(st[index].begin(),st[index].end(),k);

		return d;
	}
 
	int mid = (start+end)/2;
	int l = query(2*index,start,mid,qs,qe,k);
	int r = query(2*index+1,mid+1,end,qs,qe,k);
 
	return l + r;
}
signed main()
{	
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
	#endif	
 
    int n;
    cin >> n;

    for(int i=1;i<=n;i++)cin >> a[i];
    for(int i=1;i<=n;i++)cin >> b[i];

    build(1,1,n);
	for(int i=1;i<=n;i++)
	{
		int k = a[i];

		int lo = i;
		int hi = n;
		int id = -1;
		while(lo<=hi)
		{
			int mid = (lo+hi)/2;
			//cout << mid << ' ';
			if(query(1,1,n,i,mid,k)>=b[i])
			{
				id = mid;
				hi = mid-1;
			}
			else
			{
				lo = mid + 1;
			}

		}
		if(id == -1)
		cout << id << ' ';
		else
			cout << (id-i+1) << ' ';
	}


}
