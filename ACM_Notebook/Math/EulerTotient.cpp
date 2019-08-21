#include<bits/stdc++.h>
using namespace std;

map<int,int> factors(int n){
	map<int,int> m;

	for(int x=2;x*x<=n;x++){
		while(n%x==0){
			m[x]++;
			n/=x;
		}
	}

	if(n>1) m[n]++;
	return m;
}

int main()
{
	int n=0;
	cin>>n;
	map<int,int> fact =factors(n);

	int ans=1;
	for(auto it=fact.begin();it!=fact.end();++it){
		int p=it->first;
		int alpha=it->second;

		ans=ans*((p-1)*(int)(pow(p,alpha-1)));
	}
	cout<<ans<<"\n";
}