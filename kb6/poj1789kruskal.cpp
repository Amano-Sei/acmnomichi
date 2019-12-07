/*************************************************************************
    > File Name: poj1789.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月21日 星期四 16时36分10秒
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 2005;
const int inf = 0x3f3f3f3f;

char tcode[maxn][8];

struct Edge{
    int u, v, w;
}edge[maxn*maxn/2];
int tot = 0;

int pre[maxn];

inline void init(){
    memset(pre, -1, sizeof(pre));
    tot = 0;
}

inline void pushedge(int u, int v, int w){
    edge[tot].u = u;
    edge[tot].v = v;
    edge[tot++].w = w;
}

bool cmp(const Edge &a, const Edge &b){
    return a.w < b.w;
}

int getpre(int x){
    if(pre[x] == -1)
        return x;
    return getpre(pre[x]);
}

int kruskal(int n){
    //同前，数据要求n>=2...
    sort(edge, &edge[tot], cmp);
    int ans = 0;
    for(int i = 0; i < tot; i++){
        int tu = getpre(edge[i].u);
        int tv = getpre(edge[i].v);
        if(tu != tv){
            pre[tu] = tv;
            ans += edge[i].w;
            if(--n == 1)
                return ans;
        }
    }
}

int main(){
    int n;
    while(scanf("%d", &n) != EOF && n){
        init();
        for(int i = 0; i < n; i++){
            scanf("%s", tcode[i]);
            for(int j = 0; j < i; j++){
                int tcnt = 0;
                for(int k = 0; k < 7; k++)
                    if(tcode[i][k] != tcode[j][k])
                        tcnt++;
                //edge[tot++] = { i, j, tcnt };
                pushedge(i, j, tcnt);
            }
        }
        printf("The highest possible quality is 1/%d.\n", kruskal(n));
    }
    return 0;
}

