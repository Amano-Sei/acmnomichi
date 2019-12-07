/*************************************************************************
    > File Name: kruskal.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月21日 星期四 19时04分04秒
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1005;

struct Edge{
    int u, v, w;
}edge[maxn*maxn];
int tot;

bool cmp(const Edge &a, const Edge &b){
    return a.w < b.w;
}

int pre[maxn];
int getpre(int x){
    if(pre[x] == -1)
        return x;
    return getpre(pre[x]);
}

int kruskal(int n){
    int cnt = 1;
    int ans = 0;
    memset(pre, -1, sizeof(pre));
    sort(edge, &edge[tot], cmp);
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

