// Tags - Sorting , Greedy

/*
	Tutorial : 

Let's carefully look at the coefficients with which the elements of the array will be included in the answer.

If pair of adjacent elements ai
and ai+1 belong to different subarrays then element ai will be included in the answer with coefficient 1, and element ai+1 with coefficient −1. So they add value ai−ai+1

to the answer.

If element belongs to subarray with length 1
then it will be included in the sum with coefficient 0 (because it will be included with coefficient 1 and −1 simultaneously). Elements at positions 1 and n will be included with coefficients −1 and 1

respectively.

So initially our answer is an−a1
. All we have to do is consider n−1 values a1−a2,a2−a3,…,an−1−an and add up the k−1 minimal ones to the answer.
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
	ll n=0,k=0;
	cin>>n>>k;

	ll a[n];

	for(ll i=0;i<n;i++){
		cin>>a[i];
	}

	ll ans=a[n-1]-a[0];
	vector<ll> diff;

	for(ll i=0;i<n-1;i++){
		ll temp=a[i]-a[i+1];
		diff.push_back(temp);
	}
	sort(diff.begin(),diff.end());

	for(ll i=0;i<k-1;i++){
		ans+=(diff[i]);
	}

	cout<<ans<<"\n";
	return 0;
}