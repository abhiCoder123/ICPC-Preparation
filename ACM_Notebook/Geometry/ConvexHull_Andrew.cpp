#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct Point
{
	double x,y;
};

bool compare(Point a,Point b){
	return a.x<b.x || (a.x==b.x && a.y<b.y) ;
}

// Returns positive value if B lies to the left of OA , 
// Negative if B lies to the right of OA
// 0 if collinear


double cross(const Point &O,const Point &A,const Point &B){
	return (A.x-O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x) ;
}

// Returns a list of points on the convex hull

vector<Point> convex_hull(vector<Point> P){
	int n=P.size(),k=0;
	vector<Point> H(2*n);
	sort(P.begin(),P.end(),compare);

	// Build lower hull

	for(int i=0;i<n;++i) {

		while(k>=2 && cross(H[k-2],H[k-1],P[i])<=0) k--;

		H[k++]= P[i];
	}

	// Build Upper hull
	// i starts from n-2 because n-1 is the point which both hulls will have in common
	// t=k+1 so that the upper hull has at least two points to begin with

	for(int i=n-2, t=k+1;i>=0; i--){
		while(k>=t && cross(H[k-2], H[k-1],P[i])<=0) k--;
		H[k++]=P[i];
	}
	//the last point of upper hull is same with the fist point of the lower hull
	H.resize(k-1);
	
	return H;
}

int main()
{
	ll N;
	cout<<"Enter the number of points\n";
	cin>>N;
	vector<Point> P(N);

	cout<<"Enter the N points ( x and y coordinates)\n";

	for(ll i=0;i<N;i++){
		cin>>P[i].x>>P[i].y;
	}

	vector<Point> ans=convex_hull(P);

	cout<<"The points on the convex hull are\n";

	for(ll i=0;i<ans.size();i++){
		cout<<ans[i].x<<" "<<ans[i].y<<"\n";
	}

	return 0;
}