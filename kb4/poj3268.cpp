/*************************************************************************
    > File Name: poj3268.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年09月18日 星期三 14时45分49秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int maxn = 1005;
const int inf = 0x3f3f3f3f;

struct qnode{
    int v, w;
    qnode(){}
    qnode(int v, int w):v(v), w(w){}
    bool operator < (const qnode &r) const{
        return w > r.w;
    }
};
struct edge{
    int v, w;
    edge(){}
    edge(int v, int w):v(v), w(w){}
};

int n;
vector<edge> E[2][maxn];
int d[2][maxn];
bool vis[2][maxn];

void dijkstra(int i, int x){
    d[i][x] = 0;
    priority_queue<qnode> q;
    q.push(qnode(x, 0));
    while(!q.empty()){
        qnode tmp = q.top();
        q.pop();
        int u = tmp.v;
        if(vis[i][u])
            continue;
        vis[i][u] = true;
        for(int j = 0; j < E[i][u].size(); j++){
            int v = E[i][u][j].v;
            int w = E[i][u][j].w;
            if(!vis[i][v] && d[i][v] > d[i][u]+w){
                d[i][v] = d[i][u]+w;
                q.push(qnode(v, d[i][v]));
            }
        }
    }
}

int main(){
    memset(d, 0x3f, sizeof(d));
    int m, x, cu, cv, cw, ans = 0;
    scanf("%d%d%d", &n, &m, &x);
    while(m--){
        scanf("%d%d%d", &cu, &cv, &cw);
        E[0][cu].push_back(edge(cv, cw));
        E[1][cv].push_back(edge(cu, cw));
    }
    dijkstra(0, x);
    dijkstra(1, x);
    for(int i = 1; i <= n; i++)
        ans = max(ans, d[0][i]+d[1][i]);
    printf("%d\n", ans);
	return 0;
}

