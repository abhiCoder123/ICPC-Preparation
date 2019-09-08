#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL)
#define MAX 5000005
bool primes[MAX];
int F[MAX];
int ans[MAX];
int main()
{

	fast_cin;
	memset(primes,true,sizeof(primes));
	primes[0]=primes[1]=false;
	for(ll i=2;i*i<=MAX;i++){
		if(primes[i]){
		for(ll p=i*i;p<10000005;p+=i){
			primes[p]=false;
		}
	}
	}
/*	unordered_set<ll> prime;

	for(ll i=2;i<10000005;i++)
		if(primes[i])
			prime.insert(i);*/


	for(ll i=1;i<MAX;i++){
		for(ll j=i;j<MAX;j+=i)
			F[j]++;
	}

	for(ll i=1;i<MAX;i++){
		if(primes[F[i]])
			ans[i]=1;
		else ans[i]=0;
	}	

	ans[0]=0;
	for(ll i=1;i<MAX;i++)
		ans[i]=ans[i]+ans[i-1];
	ll T,L,R;
	cin>>T;

	while(T--){

		cin>>L>>R;
		cout<<ans[R]-ans[L-1]<<"\n";

	}

	return 0;
}