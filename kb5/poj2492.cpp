/*************************************************************************
    > File Name: poj2492.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月15日 星期五 10时53分39秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 2005;

int pre[maxn];
int w[maxn];
bool getans;

int getpre(int x){
    if(pre[x] == -1)
        return x;
    int tx = getpre(pre[x]);
    w[x] ^= w[pre[x]];
    return pre[x] = tx;
}

inline void init(){
    memset(pre, -1, sizeof(pre));
    memset(w, 0, sizeof(w));
    getans = false;
}

int main(){
    int t;
    int n, m, cu, cv;
    scanf("%d", &t);
    for(int caset = 1; caset <= t; caset++){
        init();
        scanf("%d%d", &n, &m);
        while(m--){
            scanf("%d%d", &cu, &cv);
            if(getans)
                continue;
            register int tu = getpre(cu);
            register int tv = getpre(cv);
            if(tu != tv){
                pre[tv] = tu;
                w[tv] = w[cu]^1^w[cv];
            }else if(w[cu] == w[cv])
                getans = true;
        }
        if(getans)
            printf("Scenario #%d:\nSuspicious bugs found!\n\n", caset);
        else
            printf("Scenario #%d:\nNo suspicious bugs found!\n\n", caset);
    }
    return 0;
}

