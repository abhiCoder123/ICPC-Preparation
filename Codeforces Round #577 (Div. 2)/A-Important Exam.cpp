#include<bits/stdc++.h>
using namespace std;
#define LL long long


int main () 
{

    LL n,m;

    cin>>n>>m;
    string answer[n];

    for(LL i=0;i<n;i++)
        cin>>answer[i];

    LL points[m];
    for(LL i=0;i<m;i++)
        cin>>points[i];

    LL table[m][5];
    LL correct_count[m];

    memset(table,0,sizeof(table));

    for(LL i=0;i<n;i++){
        string temp=answer[i];
        
        for(LL j=0;j<m;j++){

                LL idx=temp[j]-'A';
                table[j][idx]++;

        }
    }
    for(LL j=0;j<m;j++){
        LL winner_idx=-1;
        LL curr_max=LLONG_MIN , maxi=LLONG_MIN;
        for(LL k=0;k<5;k++){
            curr_max=table[j][k];
            if(curr_max>maxi){
                maxi=curr_max;
                winner_idx=k;
            }
        }
        correct_count[j]=maxi;

    }

    LL res=0;

    for(LL i=0;i<m;i++){
        res+=(correct_count[i] * points[i]);
    }
    cout<<res<<"\n";
    return 0;
}