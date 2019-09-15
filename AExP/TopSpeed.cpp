#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<ll,ll> pll;

int main()
{

	ll T,N;
	cin>>T;

	while(T--)
	{
		cin>>N;

		pll arr[N];


		for(ll i=0;i<N;i++){
			cin>>arr[i].first;
			arr[i].second=i;
		}

		ll temp=-1;

		sort(arr,arr+N);

		pll ans[N];

		for(ll i=0;i<N;i++){

			if(arr[i].second>temp){
				//cout<<0<<" ";
				temp=arr[i].second;
			}
		
				//cout<<temp-arr[i].second<<" ";
				ans[i].first=arr[i].second;
				ans[i].second=temp-arr[i].second;
		}

		sort(ans,ans+N);

		for(ll i=0;i<N;i++)
			cout<<ans[i].second<<" ";
		cout<<"\n";
	}
	return 0;
}