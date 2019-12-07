/*************************************************************************
    > File Name: bkb.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年09月08日 星期日 15时02分40秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int inf = 0x3f3f3f3f;
const int maxn = 1005;
struct qnode{
    int v;
    int c;
    qnode(){}
    qnode(int v, int c):v(v), c(c){}
    bool operator < (const qnode &r) const{
        return c > r.c;
    }
};
struct edge{
    int v, ccost;
    edge(){}
    edge(int v, int ccost):v(v), ccost(ccost){}
};
vector<edge> ed[maxn];
bool vis[maxn];
int dist[maxn];
int fa[maxn][maxn];
int allteam[maxn];

void djs(int n, int start){
    memset(vis, 0, sizeof(vis));
    memset(dist, 0x3f, sizeof(dist));
    priority_queue<qnode> que;
    while(!que.empty())
        que.pop();
    dist[start] = 0;
    que.push(qnode(start, 0));
    qnode tmp;
    while(!que.empty()){
        tmp = que.top();
        que.pop();
        int u = tmp.v;
        if(vis[u])
            continue;
        vis[u] = true;
        for(int i = 0; i < ed[u].size(); i++){
            int v = ed[u][i].v;
            int ccost = ed[u][i].ccost;
            if(!vis[v] && dist[v] > (dist[u] + ccost)){
                dist[v] = dist[u] + ccost;
                que.push(qnode(v, dist[v]));
            }
        }
    }
}

void addedge(int u, int v, int w){
    ed[u].push_back(edge(v, w));
}

int main(){
    int t, tt, tu, tv;
    int vv, ee, ss, kk, cc;
    int hs, ts;
    scanf("%d", &t);
    while(t--){
        memset(fa, 0x3f, sizeof(fa));
        scanf("%d%d%d%d%d", &vv, &ee, &ss, &kk, &cc);
        for(int i = 1; i <= vv; i++)
            ed[i].clear();
        for(int i = 0; i < kk; i++)
            scanf("%d", &allteam[i]);
        for(int i = 0; i < ee; i++){
            scanf("%d%d%d", &tu, &tv, &tt);
            fa[tu][tv] = fa[tv][tu] = min(fa[tu][tv], tt);
        }
        for(int i = 1; i <= vv; i++)
            for(int j = 1; j <= vv; j++)
                if(fa[i][j] < inf)
                    addedge(i, j, fa[i][j]);
        for(int i = 0; i < kk; i++)
            addedge(vv+1, allteam[i], 0);
        djs(vv, ss);
        hs = ts = 0;
        for(int i = 1; i <= vv; i++)
            hs = max(hs, dist[i]);
        djs(vv+1, vv+1);
        for(int i = 1; i <= vv; i++)
            ts = max(ts, dist[i]);
        if(hs <= ts*cc)
            printf("%d\n", hs);
        else
            printf("%d\n", ts);
    }
	return 0;
}

