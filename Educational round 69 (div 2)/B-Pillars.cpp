/*

Suppose we have a disk that is smaller than both of its neighbours. Then it's impossible to collect all the disks on the same pillar: eventually we will put this disk on the same pillar with one of its neighbours, and then we can't put the other neighbouring disk on the same pillar since it is greater than the middle disk.

Okay, and what if there is no disk that is strictly smaller than both of its neighbours? Let k
be the index of the largest disk. ak−1<ak, that implies ak−2<ak−1, and so on. ak+1<ak, ak+2<ak+1, and so on. It means that the array a is sorted in ascending until the index k, and after that it is sorted in descending order. If this condition is met, then we can collect all the disks on the pillar k one by one, starting with the disk having radius n−1 and ending with the disk having radius 1

.

So the only thing that we need to check is the following condition: array a
is sorted in ascending order until ak=n, and then it is sorted in descending order.
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
	ll n=0;
	cin>>n;

	ll a[n];

	for(ll i=0;i<n;i++){
		cin>>a[i];
	}

	ll max_idx=-1,maxi=LLONG_MIN;

	for(ll i=0;i<n;i++){
		if(a[i]>=maxi){
			max_idx=i;
			maxi=a[i];
		}
	}
	ll left_check=1;
	for(ll i=0;i<max_idx;i++){
		if(a[i]<a[i+1]){

		}
		else{
			left_check=-1;
			break;
		}
	}
	ll right_check=1;
	for(ll i=n-1;i>max_idx;i--){
		if(a[i]<a[i-1]){

		}
		else{
			right_check=-1;
			break;
		}
	}

	if(left_check==1&&right_check==1)
		cout<<"YES\n";
	else cout<<"NO\n";

	return 0;
}