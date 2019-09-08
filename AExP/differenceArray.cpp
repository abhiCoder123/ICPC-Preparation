#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<ll,ll> pll;
const long long MAX=1e18;
#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()
{
	
	fast_cin;
	
	ll T=0,N=0;
	cin>>T;

	while(T--){
		cin>>N;

		ll A[N];

		vector<ll> v;
		for(ll i=0;i<N;i++){
			cin>>A[i];
			ll num=A[i];

			while(num%2==0)
				num/=2;
			v.push_back(num);
		}

		vector<pll> diff;

		for(ll i=0;i<v.size();i++){

			ll base=i,temp=v[i];
			while(temp<MAX){
				diff.push_back(make_pair(temp,base));
				temp=temp*2;
			}
		}

		ll length=diff.size();
		sort(diff.begin(),diff.end());

		ll ans=LLONG_MAX;

		for(ll i=0;i<length-1;i++){
			if(diff[i+1].second!=diff[i].second){
				if(diff[i+1].first-diff[i].first<ans)
					ans=diff[i+1].first-diff[i].first;
			}
		}
		cout<<ans<<"\n";

		

	}
	return 0;
}