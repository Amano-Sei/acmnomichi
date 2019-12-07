/*************************************************************************
    > File Name: hdu1301.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月23日 星期六 19时11分51秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 27;

struct Edge{
    int u, v, w;
    bool operator < (const Edge &a) const{
        return w < a.w;
    }
}edge[maxn*(maxn-1)/2];
int tot;

int pre[maxn];
int getpre(int x){
    if(pre[x] == -1)
        return x;
    return pre[x] =getpre(pre[x]);
}

inline int kruskal(int n){
    int ans = 0;
    int cnt = 1;
    sort(edge, &edge[tot]);
    memset(pre, -1, sizeof(pre));
    for(int i = 0; i < tot; i++){
        register int tu = getpre(edge[i].u);
        register int tv = getpre(edge[i].v);
        if(tu != tv){
            pre[tu] = tv;
            ans += edge[i].w;
            if(++cnt == n)
                break;
        }
    }
    return cnt==n?ans:-1;
}

int main(){
    int n, cu, cv, cw, cm;
    char cs[12];
    while(scanf("%d", &n) != EOF && n){
        tot = 0;
        for(int i = 1; i < n; i++){
            scanf("%s%d", cs, &cm);
            cu = cs[0]-'A';
            while(cm--){
                scanf("%s%d", cs, &cw);
                cv = cs[0]-'A';
                edge[tot++] = { cu, cv, cw };
            }
        }
        printf("%d\n", kruskal(n));
    }
    return 0;
}

