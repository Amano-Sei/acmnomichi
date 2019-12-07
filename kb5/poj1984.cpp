/*************************************************************************
    > File Name: poj1984.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月15日 星期五 10时05分45秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

const int maxn = 40005;
const int maxk = 10005;

int pre[maxn], dx[maxn], dy[maxn];

int getpre(int x){
    if(pre[x] == -1)
        return x;
    int tx = getpre(pre[x]);
    dx[x] += dx[pre[x]];
    dy[x] += dy[pre[x]];
    return pre[x] = tx;
}

int ans[maxk];
int st[maxk], ep[maxk], ct[maxk];
int tos[maxk];
int cu[maxn], cv[maxn], cdx[maxn], cdy[maxn];

bool cmp(int a, int b){
    return ct[a] < ct[b];
}

inline void init(){
    memset(pre, -1, sizeof(pre));
    memset(dx, 0, sizeof(dx));
    memset(dy, 0, sizeof(dy));
}

int main(){
    int n, m, cw;
    char cdir[4];
    scanf("%d%d", &n, &m);
    init();
    for(int i = 0; i < m; i++){
        scanf("%d%d%d%s", &cu[i], &cv[i], &cw, cdir);
        switch(cdir[0]){
            case 'N':
                cdx[i] = 0;
                cdy[i] = cw;
                break;
            case 'E':
                cdx[i] = cw;
                cdy[i] = 0;
                break;
            case 'S':
                cdx[i] = 0;
                cdy[i] = -cw;
                break;
            case 'W':
                cdx[i] = -cw;
                cdy[i] = 0;
                break;
        }
    }
    scanf("%d", &m);
    for(int i = 1; i <= m; i++){
        scanf("%d%d%d", &st[i], &ep[i], &ct[i]);
        tos[i] = i;
    }
    sort(&tos[1], &tos[m+1], cmp);
    for(int i = 1; i <= m; i++){
        for(int j = ct[tos[i-1]]; j < ct[tos[i]]; j++){
            register int tu = getpre(cu[j]);
            register int tv = getpre(cv[j]);
            if(tu != tv){
                pre[tv] = tu;
                dx[tv] = dx[cu[j]]-dx[cv[j]]+cdx[j];
                dy[tv] = dy[cu[j]]-dy[cv[j]]+cdy[j];
            }
        }
        register int tu = getpre(st[i]);
        register int tv = getpre(ep[i]);
        if(tu == tv)
            printf("%d\n", abs(dx[st[i]]-dx[ep[i]])+abs(dy[st[i]]-dy[ep[i]]));
        else
            puts("-1");
    }
    return 0;
}

