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
    long long c;
    qnode(){}
    qnode(int v, long long c):v(v), c(c){}
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
long long dist[maxn][maxn];
int fa[maxn][maxn];
int allteam[maxn];
bool book[maxn];

void djs(int n, int start){
    if(book[start])
        return;
    book[start] = true;
    memset(vis, 0, sizeof(vis));
    priority_queue<qnode> que;
    while(!que.empty())
        que.pop();
    dist[start][start] = 0;
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
            if(!vis[v] && dist[start][v] > (dist[start][u] + ccost)){
                dist[start][v] = dist[start][u] + ccost;
                que.push(qnode(v, dist[start][v]));
                //cout << start << "->" << v << "=" << dist[start][v] << endl;
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
    long long hs, ts;
    scanf("%d", &t);
    while(t--){
        memset(book, 0, sizeof(book));
        memset(fa, 0x3f, sizeof(fa));
        memset(dist, 0x3f, sizeof(dist));
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
        
        djs(vv, ss);
        hs = ts = 0;
        for(int i = 1; i <= vv; i++)
            hs = max(hs, dist[ss][i]);
        for(int i = 0; i < kk; i++){
            djs(vv, allteam[i]);
            for(int j = 1; j <= vv; j++)
                ts = max(ts, dist[allteam[i]][j]);
        }
        if(hs <= ts*cc)
            printf("%lld\n", hs);
        else
            printf("%lld\n", ts);
    }
	return 0;
}

