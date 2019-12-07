/*************************************************************************
    > File Name: hdu1233kruskal.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月23日 星期六 16时37分56秒
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 100;
const int maxm = maxn*(maxn-1)/2;

struct edge{
    int u, v, w;
}edges[maxm];
int tot;

bool cmp(const edge &a, const edge &b){
    return a.w < b.w;
}

int pre[maxn];
int getpre(int x){
    if(pre[x] == -1)
        return x;
    return pre[x] = getpre(pre[x]);
}

int kruskal(int n){
    int cnt = 1;
    int ans = 0;
    memset(pre, -1, sizeof(pre));
    sort(edges, &edges[tot], cmp);
    for(int i = 0; i < tot; i++){
        register int tu = getpre(edges[i].u);
        register int tv = getpre(edges[i].v);
        if(tu != tv){
            pre[tu] = tv;
            ans += edges[i].w;
            if(++cnt == n)
                break;
        }
    }
    return cnt==n?ans:-1;
}

int main(){
    int n;
    while(scanf("%d", &n) != EOF && n){
        tot = n*(n-1)/2;
        for(int i = 0; i < tot; i++)
            scanf("%d%d%d", &edges[i].u, &edges[i].v, &edges[i].w);
        printf("%d\n", kruskal(n));
    }
    return 0;
}

