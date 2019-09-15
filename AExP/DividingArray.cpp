#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<ll,ll> pll;

int main()
{

	ll N;
	cin>>N;

	ll arr[N];
	unordered_map<ll ,ll > mp;

	for(ll i=0;i<N;i++){
		cin >> arr[i];
		mp[arr[i]]++;
	}

	vector<pll> V;

	for(auto it=mp.begin();it!=mp.end();++it){

		ll f = it->first;
		ll s = it->second;

		V.push_back(make_pair(f,s));
	}

	sort(V.begin(),V.end());

/*	for(ll i=0;i<V.size();i++){
		cout<<V[i].first<<" "<<V[i].second<<"\n";
	}
*/
	vector<ll> A;
	vector<ll> B;

	for(ll i=0;i<V.size() && i<(N/2);i++){
		A.push_back(V[i].first);
		V[i].second = V[i].second-1;
	}

/*	for(ll i=0;i<A.size();i++){
		cout<<A[i]<<"\n";
	}*/
	ll count=0;
	ll i=0;
	while(count<(N/2))
	{	
		if(V[i].second>0){
			B.push_back(V[i].first);
			V[i].second--;
			count++;

		}
		else i++;
	}

/*	for(ll i=0;i<B.size();i++){
		cout<<B[i]<<"\n";
	}*/
	ll size= A.size();

	ll gap= (N/2)-A.size();

	// cout<<gap<<"\n";

	ll fill =0;
	ll index=0;

	vector<ll> a_new;
	while(gap&&(index<A.size()))
	{
		if(fill<A[index]){
			a_new.push_back(fill);
			fill++;
			gap--;
		}
		else{
			a_new.push_back(A[index]);
			fill=A[index]+1;
			index++;
		}
	}

	while(index<A.size()){
		a_new.push_back(A[index]);
		index++;
	}

	while(gap){
		a_new.push_back(fill);
		fill++;
		gap--;
	}

	for(ll i=0;i<a_new.size();i++)
		cout<<a_new[i]<<" ";

	for(ll i=0;i<N/2;i++)
		cout<<B[i]<<" ";
	return 0;
}