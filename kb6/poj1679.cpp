/*************************************************************************
    > File Name: poj1679.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月22日 星期五 22时07分40秒
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 105;

struct edge{
    int u, v, w;
}edges[maxn*maxn/2];
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

int kruskal(int cnt){
    memset(pre, -1, sizeof(pre));
    int ans = 0;
    sort(edges, &edges[tot], cmp);
    int i = 0, j;
    int canin = 0;
    while(i < tot && cnt){
        for(j = i+1; j < tot && edges[j].w == edges[i].w; j++)
            if(getpre(edges[j].u) != getpre(edges[j].v))
                canin++;
        register int tu = getpre(edges[i].u);
        register int tv = getpre(edges[i].v);
        if(tu != tv){
            pre[tu] = tv;
            ans += edges[i].w;
            cnt--;
        }
        for(i = i+1; i < j; i++){
            register int tu = getpre(edges[i].u);
            register int tv = getpre(edges[i].v);
            if(tu != tv){
                pre[tu] = tv;
                ans += edges[i].w;
                canin--;
                cnt--;
            }
        }
        if(canin > 0)
            return -1;
        if(cnt == 0)
            break;
    }
    return cnt==0?ans:-1;
}

int main(){
    int t, n;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &tot);
        for(int i = 0; i < tot; i++)
            scanf("%d%d%d", &edges[i].u, &edges[i].v, &edges[i].w);
        register int tans = kruskal(n-1);
        if(tans == -1)
            puts("Not Unique!");
        else
            printf("%d\n", tans);
    }
    return 0;
}

