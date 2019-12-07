/*************************************************************************
    > File Name: poj1062alter.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年09月29日 星期日 15时48分21秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 105;
const int inf = 0x3f3f3f3f;

int n;
int d[maxn];
int dis[maxn][maxn];
int lvl[maxn];
bool book[maxn];

void dijkstra(){
    memset(d, 0x3f, sizeof(d));
    d[0] = 0;
    for(int i = 0; i < n; i++){
        int u = -1;
        int mindis = inf;
        for(int j = 0; j <= n; j++)
            if(!book[j] && d[j] < mindis){
                u = j;
                mindis = d[j];
            }
        if(u == -1)
            return;
        if(u == 1)
            return;
        book[u] = true;
        for(int j = 1; j <= n; j++)
            if(!book[j] && d[j] > d[u]+dis[u][j])
                d[j] = d[u]+dis[u][j];
    }
}

int main(){
    memset(dis, 0x3f, sizeof(dis));
    int m, x, cu, cw;
    int minlvl = inf, maxlvl = -inf;
    scanf("%d%d", &m, &n);
    for(int i = 1; i <= n; i++){
        scanf("%d%d%d", &dis[0][i], &lvl[i], &x);
        minlvl = min(minlvl, lvl[i]);
        maxlvl = max(maxlvl, lvl[i]);
        while(x--){
            scanf("%d%d", &cu, &cw);
            dis[cu][i] = cw;
        }
    }
    int ans = inf;
    for(int cmin = minlvl, cmax = min(maxlvl, minlvl+m); cmax <= maxlvl; cmin++, cmax++) {
        book[0] = false;
        for(int i = 1; i <= n; i++)
            book[i] = (lvl[i] > cmax || lvl[i] < cmin);
        dijkstra();
        ans = min(ans, d[1]);
    }
    printf("%d\n", ans);
    return 0;
}


