#include <bits/stdc++.h>
using namespace std;

int main() {
    // your code goes here
    #ifndef ONLINE_JUDGE
            freopen("output.txt","r",stdin);
            freopen("input.txt","w",stdout);
    #endif    

    srand(time(0));
    int n = 1000;
    cout << n << '\n';
    string s;
    cin >> s;
    for(int i=0;i<n;i++)
    {
        int x = (rand())%2;
        s+=(char)('a'+x);
    }
    
    cout << s;
    
    return 0;
}


























/*
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{	
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
	#endif	

   int N;
   cin >> N;

   int dp[N+1][26];
   memset(dp,0,sizeof dp);

   string s;
   cin >> s;
   for(int i=1;i<=N;i++)	
   {
   		for(int j=0;j<26;j++)
   		{
   			dp[i][j] = dp[i-1][j] + ((s[i-1]-'a') == j);
   		}
   }

   int max_length = 0;
   for(int i=1;i<=N;i++)
   {
   		for(int j=i;j<=N;j++)
   		{
   			int odd = 0;
   			for(int k=0;k<26;k++)
   			{
   				int d = dp[j][k] - dp[i-1][k];
   				if(d%2==1)
   					odd++;
   			}
   			if(odd<=1)
   			{
   				max_length = max(max_length,j-i+1);
   			}
   		}
   }

   cout << max_length << '\n';


}
