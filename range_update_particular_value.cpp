#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 100000000000;
const int N = 200005;
int a[N];
int st[4*N];
int lazy[4*N];
void build(int index,int start,int end)
{
	if(start == end)
	{
		st[index] = a[start];
		return;
	}

	int mid = (start+end)/2;

	build(2*index,start,mid);
	build(2*index+1,mid+1,end);

	//st[index] = st[2*index] + st[2*index+1]; 
}
int query(int index,int start,int end,int find_index)
{
	//cout << start << ' ' << end << '\n';
	if(lazy[index]!=0)
	{
		int dx = lazy[index];
		st[index] += dx;
		lazy[index] = 0;
		if(start!=end)
		{
			lazy[2*index]+=dx;
			lazy[2*index+1]+=dx;
		}
	}
	if(start == end)
	{
		return st[index];
	}

	int mid = (start+end)/2;
	if(mid < find_index)
	{
		return query(2*index+1,mid+1,end,find_index);
		
	}
	else
	{
		return query(2*index,start,mid,find_index);
	}
}
void update(int index,int start,int end,int q)
{
	if(start == end)
	{
		st[index] = a[start];
		return;
	}
	int mid = (start+end)/2;
	if(q<=mid)
		update(2*index,start,mid,q);
	else
		update(2*index+1,mid+1,end,q);
	st[index] = st[2*index] + st[2*index+1];
}

void lazy_update(int index,int start,int end,int us,int ue,int val)
{
	//cout << start << ' ' << end << '\n';
	if(lazy[index]!=0)
	{
		int dx = lazy[index];
		st[index] += dx;
		lazy[index] = 0;
		if(start!=end)
		{
			lazy[2*index]+=dx;
			lazy[2*index+1]+=dx;
		}
	}

	if(start>ue || end<us)
		return;

	if(start>=us && end <= ue)
	{
		st[index]+=val;

		if(start!=end){
			lazy[2*index]+=val;
			lazy[2*index+1]+=val;
		}
		return;
	}
	int mid = (start+end)/2;

	lazy_update(2*index,start,mid,us,ue,val);
	lazy_update(2*index+1,mid+1,end,us,ue,val);

	//st[index] = st[2*index] + st[2*index+1];
}
signed main()
{	
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
	#endif	

    int n;
    cin >> n;
    int q;
    cin >> q;
    for(int i=1;i<=n;i++)cin >> a[i];
   	build(1,1,n);
    while(q--)
    {
    	int t;
    	cin >> t;
    	if(t == 1)
    	{
    		int l,r,v;
    		cin >> l >> r >> v;
    		lazy_update(1,1,n,l,r,v);
    	}
    	else
    	{
    		int index;
    		cin >> index;
    		cout << query(1,1,n,index) << '\n';
    	}
    }
}




