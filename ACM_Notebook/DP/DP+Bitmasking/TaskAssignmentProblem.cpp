/*
	There are N persons and N tasks, each task is to be alloted to a single person.
	We are also given a matrix cost of size NxN , where cost[i][j] denotes , how much person "i"
	is going to charge for task j. Now , we need to assign each task to a person in such
	a way that total cost is minimum. Note that each task is to be alloted to a single person, and
	each person will be alloted only one task.
*/



#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll cost[1000][1000];
const long long MAXN= 1e5+5;
ll dp[MAXN];

ll assign(ll N){
	dp[0]=0;

	for(ll mask=0;mask<((ll)pow(2,N));mask++){
		ll x= __builtin_popcount(mask);
		
		for(ll j=0;j<N;j++){
			if((mask&(1<<j))==0){
				dp[mask|(1<<j)]=min(dp[mask|(1<<j)],dp[mask]+cost[x][j]);
			}
		}	
	}
	return dp[(ll)pow(2,N)-1];
}

int main()
{
	ll N;
	cin>>N;

	for(ll i=0;i<MAXN;i++){
		dp[i]=LLONG_MAX;
	}

	for(ll i=0;i<N;i++){
		for(ll j=0;j<N;j++){
			cin>>cost[i][j];
		}
	}

	cout<<"Cost of (minimum) assignment is :"<<assign(N)<<"\n";



	return 0;
}