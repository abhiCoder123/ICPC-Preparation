/*

Concept :

Since all planks have length at least 1 so we can take any n−2 planks as steps.
 So, all we need is to maximize the length of base planks. 
 We can take the first and second maximum as base, then the answer
  is minimum among second maximum - 1 and n−2.
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
	ll T=0,N=0;
	cin>>T;
	while(T--){
		cin>>N;

		ll a[N];
		for(ll i=0;i<N;i++)
			cin>>a[i];

		ll maxi=LLONG_MIN,second_maxi=(LLONG_MIN)+1;

		for(ll i=0;i<N;i++){
			if(a[i]>=maxi){
				second_maxi=maxi;
				maxi=a[i];
			}
			else if(a[i]>=second_maxi){
				second_maxi=a[i];
			}
		}

		cout<<min(second_maxi-1,N-2)<<"\n";
	}
	return 0;
}