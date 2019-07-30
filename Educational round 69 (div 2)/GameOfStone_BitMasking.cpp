#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

map<pair<int, ll>, int> grundy;
map<pair<int, ll>, bool> mp;

int retgrundy(int ps, ll bm, int prev = 63){
    for(int i=ps ; i<prev ; ++i){
        if(((bm>>i)&1LL) == 1LL)
            bm ^= (1LL<<i);
    }
    if(mp[{ps, bm}])
        return grundy[{ps, bm}];
    vector<bool> marked(63, false);
    for(int k=0 ; k<ps ; ++k){
        if(((bm>>k)&1LL) == 0)
            continue;
        marked[retgrundy(ps-k-1LL, (bm^(1LL<<k)), ps)] = true;
    }
    int ret;
    for(int i=0 ; i<63 ; ++i){
        if(marked[i])
            continue;
        grundy[{ps, bm}] = i;
        ret = i;
        break;
    }
    mp[{ps, bm}] = true;
    return ret;
}

int main(){
    int n, in, x=0;
    scanf("%d", &n);

    grundy[{0, 0}] = 0;
    mp[{0, 0}] = true;
    vector<int> gr(70, 0);

    for(int i=0 ; i<=60 ; ++i)
        gr[i] = retgrundy(i, (1LL<<i)-1LL);

    while(n--){
        scanf("%d", &in);
        x ^= gr[in];
    }

    if(x == 0)
        printf("YES");
    else
        printf("NO");

}