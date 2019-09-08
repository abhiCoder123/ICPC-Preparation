#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL)

ll T=0,N,K;
ll dp[100005][26];
bool vis[26];


int main()
{

	fast_cin;


	cin>>T;

	while(T--)
	{
		
		cin>>N>>K;

		memset(dp,0,sizeof(dp));
		memset(vis,false,sizeof(vis));
		
		for(ll i=0;i<K;i++){
			char c;
			cin>>c;
			vis[c-'a']=true;
		}

		ll sum[N]={0};

		sum[0]=K;
		for(ll i=0;i<26;i++){
			if(vis[i])
				dp[0][i]=1;
			else dp[0][i]=0;
		}
		for(ll i=1;i<N;i++){
			for(ll j=0;j<26;j++){
				if(i%2){
					dp[i][j]=(M+sum[i-1]-dp[i-1][j])%M;
				}
				else{
					if(vis[j])
						dp[i][j]=(sum[i-1]-dp[i-1][j]+M)%M;
				}
				sum[i]=(sum[i]+dp[i][j])%M;
			}
		}
		cout<<sum[N-1]<<"\n";

	}
	return 0;
}