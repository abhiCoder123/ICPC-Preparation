#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL)

bool primes[10000005];
ll F[10000005];
ll ans[10000005];
int main()
{

	fast_cin;
	memset(primes,true,sizeof(primes));
	for(ll i=2;i*i<=10000005;i++){
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


	for(ll i=1;i<10000005;i++){
		for(ll j=i;j<10000005;j+=i)
			F[j]++;
	}

	for(ll i=1;i<10000005;i++){
		if(primes[F[i]])
			ans[i]=1;
		else ans[i]=0;
	}	

	ans[0]=0;
	for(ll i=1;i<10000005;i++)
		ans[i]=ans[i]+ans[i-1];
	ll T,L,R;
	cin>>T;

	while(T--){

		cin>>L>>R;
		cout<<ans[R]-ans[L-1]<<"\n";

	}

	return 0;
}