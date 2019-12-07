/*************************************************************************
    > File Name: poj3264rmq.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月29日 星期五 18时13分18秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 50005;

int mm[maxn];
int dpm[maxn][16];
int dpM[maxn][16];

inline void init(int n){
    register int pt = -1;
    for(int i = 1; i <= n; i++){
        pt += ((i&(i-1))?0:1);
        mm[i] = pt;
        scanf("%d", &dpm[i][0]);
        dpM[i][0] = dpm[i][0];
    }
    register int ct;
    for(int j = 1; j <= mm[n]; j++){
        ct = 1<<(j-1);
        pt = n-(1<<j)+1;
        for(int i = 1; i <= pt; i++)
            dpm[i][j] = min(dpm[i][j-1], dpm[i+ct][j-1]), dpM[i][j] = max(dpM[i][j-1], dpM[i+ct][j-1]);
    }
}

inline int getans(int l, int r){
    register int tm = mm[r-l+1];
    r -= (1<<tm)-1;
    return max(dpM[l][tm], dpM[r][tm])-min(dpm[l][tm], dpm[r][tm]);
}

int main(){
    int n, q;
    scanf("%d%d", &n, &q);
    init(n);
    while(q--){
        register int cl, cr;
        scanf("%d%d", &cl, &cr);
        printf("%d\n", getans(cl, cr));
    }
    return 0;
}

