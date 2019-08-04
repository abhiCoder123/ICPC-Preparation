//Practice Problem for Sprague - Grundy Theorem (Codechef)

/*
Sprague Grundy Theorem States that Result of any state is the XOR of Grundy Numbers
of all possible transitions from the current state

ie., RESULT= XOR (G[State_1],G[State_2],...)
	
	Also Grundy numbers are calculated using MEX Operation (Minimum Excludant)

	MEX= The smallest possible move we cannot make from a set S

	eg S={0,1,3,4};
	MEX(S)=2;
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN=1e5 + 5;


int main()
{
    // Array to store the Grundy numbers of each state
	ll G[MAXN];
    
    // This vector contains the list of possible moves i.e,
    // number of stones that can be removed at once  (n^n) 
	vector<ll> remove;

	for(ll i=1;i<=7;i++){
		ll temp=(ll)(pow(i,i));
		remove.push_back(temp);
	}
    
    // Computing some initial Grundy Numbers using MEX operation
	G[0]=0;
	G[1]=1;
	G[2]=0;
	G[3]=1;
	G[4]=2;
	G[5]=0;
	G[6]=1;
	G[7]=0;
	G[8]=1;
	G[9]=2;
	G[10]=0;
    

    // Computing Grundy numbers using bottom up approach
	for(ll i=11;i<MAXN;i++){

		// For a given state "i" , states contains list of possible transition states
		vector<ll> states;
		for(ll j=0;j<remove.size();j++){
			ll next_state=i-remove[j];
			if(next_state>=0)
				states.push_back(next_state);
		}
        
        // grundy contains the grundy values of the list of possible transition states
		set<ll> grundy;
		ll grundy_max=-1;
		for(ll k=0;k<states.size();k++){
			ll curr_state=states[k];
			grundy.insert(G[curr_state]);
			if(G[curr_state]>=grundy_max)
				grundy_max=G[curr_state];
		}

		// Applying the MEX Operation to compute the value of Grundy number of current state
		ll MEX=-1;
		for(int g=0;g<=grundy_max;g++){
			if(grundy.find(g)==grundy.end()){
				MEX=g;
				break;
			}
		}
		if(MEX==-1)
			MEX=grundy_max+1;

		G[i]=MEX;

	}

	ll T=0,N=0;
	cin>>T;

	while(T--){
	cin>>N;

	ll A[N];
	for(ll i=0;i<N;i++)
		cin>>A[i];


	ll result=0;

	// Applying Sprague Grundy Theorem
	for(ll i=0;i<N;i++){
		result=result^(G[A[i]]);
	}
	if(result==0){
		cout<<"Head Chef\n";
	}
	else cout<<"Little Chef\n";
}


	return 0;
}