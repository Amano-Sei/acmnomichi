/*************************************************************************
    > File Name: poj3169.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年10月25日 星期五 19时22分00秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 1005;
const int maxm = 30005;
const int inf = 0x3f3f3f3f;

struct Edge{
    int u, v, w;
}edge[maxm];

int tot;

inline void push_edge(int u, int v, int w){
    edge[tot++] = { u, v, w };
}

int d[maxn];

//还是那句话，拒绝用spfa判定负环
bool bellman_ford(int st, int n){
    memset(d, 0x3f, sizeof(d));
    d[st] = 0;
    for(int j = 1; j < n; j++){
        bool flag = true;
        for(int i = 0; i < tot; i++){
            int u = edge[i].u;
            int v = edge[i].v;
            int w = edge[i].w;
            if(d[u] != inf && d[u]+w < d[v]){
                d[v] = d[u]+w;
                flag = false;
            }
        }
        if(flag)
            return true;
    }
    for(int i = 0; i < tot; i++)
        if(d[edge[i].u] != inf && d[edge[i].u]+edge[i].w < d[edge[i].v])
            return false;
    return true;
}

int main(){
    int n, ml, md;
    int cu, cv, cw;
    scanf("%d%d%d", &n, &ml, &md);
    while(ml--){
        scanf("%d%d%d", &cu, &cv, &cw);
        push_edge(cu, cv, cw);
    }
    while(md--){
        scanf("%d%d%d", &cu, &cv, &cw);
        push_edge(cv, cu, -cw);
    }
    for(int i = 1; i < n; i++)
        push_edge(i+1, i, 0);
    if(bellman_ford(1, n)){
        if(d[n] == inf)
            printf("-2\n");
        else
            printf("%d\n", d[n]);
    }else
        printf("-1\n");

    return 0;
}

