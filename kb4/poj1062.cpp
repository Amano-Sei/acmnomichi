/*************************************************************************
    > File Name: poj1062.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019/9/27 15:32:47
 ************************************************************************/

//这道题的话，用到了dijkstra的基本原理和状态的表示，虽然等级没有说明范围很头疼...
//到这一步差不多也明白了最短路本身没有什么复杂的，复杂的是把他转化成图，或者说建图，我对于图的理解有没有更进一步呢（

#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>

using namespace std;

const int maxn = 105;
const int inf = 0x3f3f3f3f;

struct qnode{
    int u, mini, maxi, cost;
    bool operator < (const qnode &a) const{
        return cost > a.cost;
    }
};

struct edge{
    int v, w;
};

int n, m;
bool book[maxn][maxn][maxn];
int d[maxn][maxn][maxn];
int level[maxn], id[maxn];
int val[maxn];
vector<edge> E[maxn];

void dijkstra(){
    memset(d, 0x3f, sizeof(d));
    priority_queue<qnode> q;
    for(int i = 1; i <= n; i++){
        d[level[i]][level[i]][i] = val[i];
        q.push({i,level[i],level[i],val[i]});
    }
    while(!q.empty()){
        qnode cur = q.top();
        q.pop();
        int u = cur.u;
        //printf("%d\n", u);
        int mini = cur.mini;
        int maxi = cur.maxi;
        if(book[mini][maxi][u])
            continue;
        book[mini][maxi][u] = true;
        for(int i = 0; i < E[u].size(); i++){
            int v = E[u][i].v;
            int w = E[u][i].w;
            int nlevel = level[v];
            if(abs(nlevel-mini) <= m && abs(nlevel-maxi) <= m){
                int nmini = min(mini, nlevel);
                int nmaxi = max(maxi, nlevel);
                if(!book[nmini][nmaxi][v] && d[nmini][nmaxi][v] > w+d[mini][maxi][u]){
                    d[nmini][nmaxi][v] = d[mini][maxi][u]+w;
                    q.push({v, nmini, nmaxi, d[nmini][nmaxi][v]});
                }
            }
        }
    }
}

int main(){
    int cx, cv, cw;
    scanf("%d%d", &m, &n);
    for(int i = 1; i <= n; i++){
        scanf("%d%d%d", &val[i], &level[i], &cx);
        while(cx--){
            scanf("%d%d", &cv, &cw);
            E[cv].push_back({i, cw});
        }
    }
    dijkstra();
    int ans = inf;
    for(int i = 0; i < maxn; i++)
        for(int j = 0; j < maxn; j++)
            ans = min(ans, d[i][j][1]);
    printf("%d\n", ans);
    return 0;
}

