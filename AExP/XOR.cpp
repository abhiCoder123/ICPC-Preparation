#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()
{
	
	fast_cin;
	ll N,X;

	cin>>N>>X;

	if(N&1){

		for(ll i=0;i<N-1;i++)
			cout<<1<<" ";
		cout<<X<<"\n";
	}
	else{
		if(X==1){

			for(ll i=0;i<N-2;i++)
				cout<<1<<" ";
			cout<<2<<" "<<3<<"\n";
		}
		else if(X%2==0){
			for(ll i=0;i<N-1;i++)
				cout<<1<<" ";
			cout<<X+1<<"\n";
		}
		else{ // X is odd

			for(ll i=0;i<N-1;i++)
				cout<<1<<" ";
			cout<<X-1<<"\n";
		}
	}
	return 0;
}