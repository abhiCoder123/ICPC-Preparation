#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll randomPartition(vector<ll> &arr, ll l, ll r); 
  
ll kthLargest(vector<ll> &arr, ll l, ll r, ll k) 
{ 
    
    if (k > 0 && k <= r - l + 1) 
    { 
        ll pos = randomPartition(arr, l, r); 

        if (pos-l == k-1) 
            return arr[pos]; 
        if (pos-l > k-1)  
            return kthLargest(arr, l, pos-1, k); 

        return kthLargest(arr, pos+1, r, k-pos+l-1); 
    } 
  
   return LLONG_MAX; 
} 
  
void swap(ll *a, ll *b){ 
    
    	ll temp = *a; 
    	*a = *b; 
    	*b = temp; 

    } 
  
ll partition(vector<ll> &arr, ll l, ll r) 
{ 
    ll x = arr[r], i = l; 
    for (ll j = l; j <= r - 1; j++) 
    { 
        if (arr[j] >= x) 
        { 
            swap(&arr[i], &arr[j]); 
            i++; 
        } 
    } 
    
    swap(&arr[i], &arr[r]); 
    
    return i; 
} 
  

ll randomPartition(vector<ll> &arr, ll l, ll r) 
{ 
    ll n = r-l+1; 
    ll pivot = rand() % n; 
    swap(&arr[l + pivot], &arr[r]); 
    return partition(arr, l, r); 
} 

int main()
{

	ll T,Q,X;
	cin>>T;

	while(T--)
	{

		cin>>Q;
		vector<ll> V;
		while(Q--)
		{
			
			char c;
			cin>>c>>X;

			if(c=='A'){
				V.push_back(X);
			}
			else if(c=='I'){

				for(ll i=0;i<V.size();i++){
					V[i]=V[i]+X;				
				}

			}
			else if(c=='D'){

				for(ll i=0;i<V.size();i++){
					V[i]=V[i]-X;
				}
			}
			else{

				if(X>V.size())
					cout<<-1<<"\n";
				else{
					cout<<kthLargest(V,0,V.size()-1,X)<<"\n";
				}

			}

		}


	}
	return 0;
}