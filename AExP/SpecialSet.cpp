#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()
{

	fast_cin;
	
	ll T=0,A=0,B=0,C=0,K=0;

	cin>>T;

	while(T--){
		
		cin>>A>>B>>C>>K;

		ll left=1 , right=1e18;

		ll ans=0,mid=0;
		while(left<right){
			
			 mid=(left+right)/2;

			 ans= (mid/A) + (mid/B) + (mid/C) -(mid/((A*B)/(__gcd(A,B)))) - (mid/((B*C)/(__gcd(B,C)))) - (mid/((C*A)/(__gcd(C,A)))) + (mid/((A*B*C)/(__gcd(C,__gcd(A,B))))) ;

			
			if(ans<K)
				left=mid+1;
			else right=mid;


		}

		cout<<left<<"\n";

	}

	return 0;
}