/*

 Q: A number is a d-magic number if at all the even positions there's
 	d and not anywhere else. Find number of d-magic numbers b/w u and v.
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
// digit "D" should be a multiple of m
long long m,D; 
string a , b;  // Range [a,b]

long long dp[2005][2005][2];

/*
dp[pos][mod][f] = number of d-magic numbers for the current state

pos= current position (left , zero based)
mod= current remainder (% m)
f = if the number we are building has already become smaller than upper bound or not
    [1= yes , 0=no]
*/

long long g(string A){

	// function to check if the lower bound is "a" is a d-magic number or not

	ll temp,mod=0;
	for(ll i=0;i<A.length();i++){
		temp=A[i]-'0';
		mod=((10*mod)+temp)%m;
		if((i+1)%2==0){
			
		if(temp!=D){
			return 0;
		}
	}else{
		if(temp==D){
			return 0;
		}
	}
}
return (mod==0);
}

long long call(ll pos, ll mod , ll f,string A)
{
	if(pos==A.length()){

		// When we have scanned all the digits , if mod=0(final remainder) , return 1 else 0
		return (mod==0);
	}
	//When current state has already been visited
	if(dp[pos][mod][f]!=-1) return dp[pos][mod][f];

	ll res=0;
	ll LMT;
	if(f==0){
		// if the current number has not become smaller than upper bound
		LMT=A[pos]-'0';
	}
	else{
		// if current number has become smaller than upper bound
		LMT=9;
	}

	if((pos+1)%2==0){
		// If currently the position is even , we can only place "D"
		if(D<=LMT){
			ll new_mod=(mod*10+D)%m;
			ll nf=f;
			if(f==0&&D<LMT) nf=1;
			res+=(call(pos+1,new_mod,nf,A));
			res=res%M;
		}
	}
	else{

		//If current position is odd , we can't place "D" here
		for(ll dgt=0;dgt<=LMT;dgt++){
			if(dgt==D) continue;
			ll new_mod=(10*mod+dgt)%m;
			ll nf=f;
			if(f==0&&dgt<LMT) nf=1;
			res+=(call(pos+1,new_mod,nf,A));
			res=res%M;
		}
	}
	//cout<<res<<"\n";
	return dp[pos][mod][f]=res;

}

long long solve(string A)
{
	memset(dp,-1,sizeof(dp));
	ll res=call(0,0,0,A);



	return res;

}

int main()
{	
	cin>>m>>D;
	cin>>a;  // Storing Upper and Lower bounds as strings as numbers can be very large
	cin>>b;
    /*
		Note : We cannot take : solve(b) - solve(a-1) ,
		Since "b" and "a-1" might not have same number of digits (which is not guranteed)
		
    */
	cout<<solve(b)-solve(a)+g(a)<<"\n";
	
	return 0;
}