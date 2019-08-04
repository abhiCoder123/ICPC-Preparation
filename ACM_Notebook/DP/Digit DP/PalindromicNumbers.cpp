/*
Given u and v , we have to find the number of palindrome numbers between them.
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
long long a,b;
int digit[20];   // The number (upper bound) stored in reverse order
int taken[20];   // The current number we are building
ll DP[20][20][3][3]; 

/*
DP[pos][len][f][st] = Number of valid numbers <= b from this state

pos= current position from left side

len= length state (length of number) , this state decreases in case of leading zeros

f= the number we are building has already become smaller than b ? [0= No , 1 = yes]

*/


ll call(int pos,int len,int st,int f){
	// Base Case (when we have scanned all digits successfully)
	if(pos==0)	return 1;

	if(DP[pos][len][f][st]!=-1) return DP[pos][len][f][st];

	int LMT;
	if(f==1){
		// If number has already become smaller than the upper bound
		LMT=9;
	}
	else{
		// If number has not become smaller than upper bound
		LMT=digit[pos];
	}

	ll res=0;  // to store count of palindromic numbers of current state

	for(int dgt=0;dgt<=LMT;dgt++){
		taken[pos]=dgt;
		ll nf=f; // New state for "dgt"
		if(f==0&&dgt<LMT) nf=1;   // if dgt is smaller , then nf=1
		if(st==0){
			// Handling leading Zeros

			// IF first digit is zero then it'll decrease the length
			if(dgt==0) res+=call(pos-1,len-1,st,nf);

			else res+=call(pos-1,len,1,nf);
		}else{

			// for handling palindrome
			int mid=(len+1)/2;

			// to check for "pos"(current) is in smaller half or not
			bool small=false;
			if(len%2==0){
				// Length is even then pos<=mid
				if(pos<=mid) small=true;
			}else{
				// Odd length pos< mid for small = true
				if(pos<mid) small=true;
			}

			if(small==true){
				// if currently in smaller half
				if(dgt==taken[len+1-pos]){
					// check for palindromic condition
					res+=call(pos-1,len,st,nf);
				}
			}else{
				// if not in smaller half just recur
					res+=call(pos-1,len,st,nf);
			}
		}
	}
	 return DP[pos][len][f][st]=res;
}

ll solve(ll val){
	int cnt=0;
	while(val){
		// storing upper bound in array (reversed order)
		digit[++cnt]=val%10;  
		val=val/10;
	}
	memset(DP,-1,sizeof(DP));
	return call(cnt,cnt,0,0);
}

int main()
{
	ll T=0;
	cin>>T;
	while(T--){
		cin>>a>>b;

		if(a>b){
			ll temp=a;
			a=b;
			b=temp;
		}
		cout<<solve(b)-solve(a-1)<<"\n";
	}
}