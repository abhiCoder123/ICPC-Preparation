#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define px second
#define py first
const int MAXN=1e5+5;
typedef pair<ll,ll> pairll;
pairll pnts[MAXN];

int compare(pairll a, pairll b){
	return a.px<b.px;
}

double closest_pair(pairll pnts[],int n){
	sort(pnts,pnts+n,compare);
	double best=(double)LLONG_MAX;
	//cout<<best<<"\n";
	set<pairll> box;
	box.insert(pnts[0]);
	int left=0;

	for(int i=1;i<n;i++){
		while((left<i)&&((pnts[i].px-pnts[left].px)>best))
			box.erase(pnts[left++]);

		for(auto it=box.lower_bound(make_pair(pnts[i].py-best,pnts[i].px-best));it!=box.end()&&pnts[i].py+best>=it->py;it++)
			best=min(best,sqrt(pow(pnts[i].py - it->py,2.0) + pow(pnts[i].px - it->px,2.0)));

		box.insert(pnts[i]);
	}
	return best;
}
int main()
{	
	int N;
	cout<<"Enter the number of points\n";
	cin>>N;
	cout<<"Enter x and y coordinates of points \n";
	for(ll i=0;i<N;i++){
		cin>>pnts[i].px>>pnts[i].py;
	}
	cout<<"The closest pair of points has distance = "<<closest_pair(pnts,N)<<"\n";
	return 0;
}