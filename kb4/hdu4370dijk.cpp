/*************************************************************************
    > File Name: hdu4370dijk.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年10月25日 星期五 18时55分00秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

const int maxn = 305;

int dis[maxn][maxn];
int d[maxn];
bool book[maxn];

struct qnode{
    int v, cost;
    bool operator < (const qnode &a) const{
        return cost > a.cost;
    }
};

void dijkstra(int st, int ep, int n){
    memset(d, 0x3f, sizeof(d));
    memset(book, 0, sizeof(book));
    priority_queue<qnode> q;
    for(int i = 1; i <= n; i++)
        if(i != st)
            q.push({ i, d[i]=dis[st][i] });
    while(!q.empty()){
        register int u = q.top().v;
        q.pop();
        if(book[u])
            continue;
        if(u == ep)
            return;
        book[u] = true;
        for(int i = 1; i <= n; i++)
            if(!book[i] && d[i] > d[u]+dis[u][i]){
                d[i] = d[u]+dis[u][i];
                q.push({ i, d[i] });
            }
    }
}

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                scanf("%d", &dis[i][j]);
        dijkstra(1, n, n);
        int tloop = d[1];
        int tans = d[n];
        dijkstra(n, n, n);
        printf("%d\n", min(tans, tloop+d[n]));
    }
    return 0;
}

