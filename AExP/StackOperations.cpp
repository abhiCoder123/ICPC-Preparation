#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{

	ll N,K,temp,ans,next;

	ans=LLONG_MIN;

	cin>>N>>K;
	for(ll i=0;i<N;i++){
		cin>>temp;
		if(i<K-1){
			ans=max(ans,temp);
		}

		else if(i==K){
			ans=max(ans,temp);
		}
	}

	cout<<ans<<"\n";
	return 0;
}