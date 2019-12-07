/*************************************************************************
    > File Name: poj1733hash.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月14日 星期四 15时29分23秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 10003;

int head[maxn];
int nxt[maxn];
int val[maxn];
int tot;
inline int push(int x){
    register int t = x%maxn;
    for(int i = head[t]; i != -1; i = nxt[i])
        if(val[i] == x)
            return i;
    val[tot] = x;
    nxt[tot] = head[t];
    return head[t] = tot++;
}

int pre[maxn], w[maxn];

inline void init(){
    memset(head, -1, sizeof(head));
    tot = 0;
    memset(pre, -1, sizeof(pre));
}
int getpre(int x){
    if(pre[x] == -1)
        return x;
    int tx = getpre(pre[x]);
    w[x] ^= w[pre[x]];
    return pre[x] = tx;
}

int main(){
    int n, m, cu, cv;
    char cs[16];
    init();
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++){
        scanf("%d%d%s", &cu, &cv, cs);
        cu = push(cu);
        cv = push(cv+1);
        register int tu = getpre(cu);
        register int tv = getpre(cv);
        register int tmp = (cs[0]=='o')^w[cu]^w[cv];
        if(tu != tv){
            pre[tu] = tv;
            w[tu] = tmp;
        }else if(tmp){
            printf("%d\n", i);
            return 0;
        }
    }
    printf("%d\n", m);
    return 0;
}

