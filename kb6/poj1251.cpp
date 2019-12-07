/*************************************************************************
    > File Name: poj1251.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月18日 星期一 12时50分19秒
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 27;

struct Edge{
    int u, v, w;
}edge[maxn*maxn];
int tot;
int pre[maxn];

int getpre(int x){
    if(pre[x] == -1)
        return x;
    return getpre(pre[x]);
}

inline void init(){
    memset(pre, -1, sizeof(pre));
    tot = 0;
}

bool cmp(const Edge &a, const Edge &b){
    return a.w < b.w;
}

int main(){
    int n, cu, cv, cw, cc, ans;
    char s[16];
    while(scanf("%d", &n) != EOF && n){
        init();
        ans = 0;
        for(int i = 0; i < n-1; i++){
            scanf("%s%d", s, &cc);
            cu = s[0]-'A';
            while(cc--){
                scanf("%s%d", s, &cw);
                cv = s[0]-'A';
                edge[tot++] = { cu, cv, cw };
            }
        }
        sort(edge, &edge[tot], cmp);
        for(int i = 0; i < tot && n > 1; i++){
            register int tu = getpre(edge[i].u);
            register int tv = getpre(edge[i].v);
            if(tu != tv){
                pre[tu] = tv;
                ans += edge[i].w;
                n--;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

