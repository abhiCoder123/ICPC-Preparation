#include <bits/stdc++.h>
using namespace std;
#define LL long long



int main () {
  


    LL N;
    cin>>N;

    LL sum=0,maxi=LLONG_MIN;
    LL temp;
    for(LL i=0;i<N;i++){
        cin>>temp;
        sum+=temp;
        maxi=max(maxi,temp);
    }

    if(sum%2==0&&maxi<=(sum/2)){
        cout<<"YES\n";
    }
    else cout<<"NO\n";


    return 0;
}