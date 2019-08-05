/*

Sort the array in non-decreasing order. In the new array b1,b2,…,bn 
you can make binary search with the maximum median value. 
For a given median value (x), it is required to make ∑ni=(n+1)/2max(0,x−bi) operations. 
If this value is more than k, x can't be median, otherwise it can. 
Time complexity: O((n/2)⋅log(109))

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n,k;
ll x;
vector<ll> a;
bool check(ll x)
{
	ll moves=0;
	for(ll i=n/2;i<n;i++){
		if(x-a[i]>0) moves+=(x-a[i]);
		if(moves>k) return false;
	}
	if(moves<=k) return true;
	else return false;
}

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;

	for(int i=1;i<=n;i++){
		cin>>x;
		a.push_back(x);
	}
	sort(a.begin(),a.end());

	ll small=1;
	ll big=2e9+5;
	while(small!=big){
		ll mid = (small+big+1)/2;

		if(check(mid))
		{
			small=mid;
		}
		else{
			big=mid-1;
		}
	}
	cout<<small;
	return 0;
}