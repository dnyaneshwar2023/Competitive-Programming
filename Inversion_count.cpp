#include<bits/stdc++.h>
using namespace std;
#define int long long

int arr[100005];
int fenwick[100005];
int N;

void update(int index,int x)
{
   for(int i=index;i<=N;i+=(i&-i))
   {
      fenwick[i]+=x;
   }
}
int sum(int index)
{
   int ans = 0;
   for(int i=index;i>0;i-=(i&-i))
   {
      ans+=fenwick[i];
   }
   return ans;
}
signed main()
{   
   #ifndef ONLINE_JUDGE
     freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);
   #endif   
   ios_base::sync_with_stdio(0);cin.tie(0);cin.tie(0);

   
   cin >> N;
   int inv = 0;
   memset(fenwick,0,sizeof fenwick);
   memset(arr,0,sizeof arr);
   map<int,int> mp;

   int c = 1;

   for(int i=0;i<N;i++)
   {
      cin >> arr[i];
      mp[arr[i]]++;
   }

   for(auto &it:mp)
   {
      it.second = c++;
   }

   for(int i=0;i<N;i++)arr[i] = mp[arr[i]];

   int left[N];
   int right[N];

   for(int i=0;i<N;i++)
   {
      left[i] = sum(N) - sum(arr[i]);
      update(arr[i],1);
   }

   memset(fenwick,0,sizeof fenwick);

   for(int i=N-1;i>=0;i--)
   {
      right[i] = sum(N) - sum(arr[i]);
      update(arr[i],1);
   }


   int min_index = -1;

   for(int i=0;i<N;i++)
   {
      if(left[i]>0 && right[i]>0 && left[i] == right[i])
      {
         min_index = i;
         break;
      }
   }

   cout << min_index << '\n';
      
}
