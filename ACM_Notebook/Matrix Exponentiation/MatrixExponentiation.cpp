#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007

//Matrix Multiplication Modulo 'M'

// mat1[m][n] ,mat2[n][p] , res[m][p]

// res is the result matrix
ll A[1000][1000],res[1000][1000];
void matmul(ll mat1[][1000],ll mat2[][1000] , ll res[][1000], int m, int n,int p){
	for(int i=0;i<m;i++){
		for(int j=0;j<p;j++){
			ll num=0;

			for(int k=0;k<n;k++){
				num+=((mat1[i][k]%M)*(mat2[k][j]%M))%M;
			}
			res[i][j]=num%M;
		}
	}
}
void matrix_exponentiation(ll A[][1000],ll N,ll x){
	

	for(ll i=0;i<N;i++){
		res[i][i]=1;
	}
	while(x>0){
		if(x%2==1)
			matmul(A,A,res,N,N,N);
		matmul(A,A,A,N,N,N);
		x=x/2;
	}
}


int main()
{

	ll N=0,x=0;
	cin>>N>>x;

	for(ll i=0;i<N;i++){
		for(ll j=0;j<N;j++){
			cin>>A[i][j];
		}
	}

	memset(res,0,sizeof(res));
	matrix_exponentiation(A,N,x);

	for(ll i=0;i<N;i++){
		for(ll j=0;j<N;j++){
			cout<<res[i][j]<<" ";
		}
		cout<<"\n";
	}
	

	return 0;
}