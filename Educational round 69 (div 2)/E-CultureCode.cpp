/*
E- Culture Code  : Tags { dp , sorting , binary search , combinatorics , data structures}
*/

#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define debug(x) cerr<<#x<<":"<<x<<endl
#define pb push_back

typedef long long ll;
typedef pair<int,int> pi;
const int MAXN = (int)1e6+7;
const int MOD = (int)1e9+7;

pi a[MAXN];
int val[MAXN];
int cnt[MAXN];

/*
	1) Variables Explanation :

	i) N --> The number of matryoshkas
	ii) Array a --> where a[i].first --> inner volume , a[i].second --> outer volume
	iii) val[MAXN] --> where val[i] is the minimum extra space among all nested subsets
	      where ith doll is minimum

	iv) cnt[MAXN] ---> where cnt[i] --> Number of such subsequences among all nested 
		subsets where the ith doll is minimal
*/
int main()
{
	ios::sync_with_stdio(false);         // For Fast I/O
	cin.tie(0);
	cout.tie(0);

	int N;
	cin>>N;

	rep(i,1,N)	cin>> a[i].second>>a[i].first;

	sort(a+1,a+1+N);    //Sorted array in increasing order of inner volume and then increasing order of outer volume
	val[N+1]=1e9+7;                // Purposely set to a large value


	for(int i=N;i>=1;i--){     //Iterating the sorted array backwards

		//To check for the first doll id such that a[i].second could fit into a[id]
		// ie., outer volume of i <= inner volume of id
		int id= lower_bound(a+i+1,a+N+1,make_pair(a[i].second,1))-a;
		//cout<<id<<"\n";

		if(id==N+1){                 // if id is not found
			val[i] = a[i].first;
			cnt[i] = 1;
		}else{

			// Update extra space
			val[i]=val[id]-a[i].second+a[i].first;
			cnt[i]=cnt[id];
		}

		if(val[i]==val[i+1]){
			cnt[i]=(cnt[i]+cnt[i+1])%MOD;
		}else if (val[i]>val[i+1]){
			val[i]=val[i+1];
			cnt[i]=cnt[i+1];
		}
	}


	cout<<cnt[1]<<endl;
}