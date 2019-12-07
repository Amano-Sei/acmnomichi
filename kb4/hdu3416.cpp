/*************************************************************************
    > File Name: hdu3416.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年10月11日 星期日 9时19分59秒
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn = 1005;
const int maxm = 100005;
const int inf = 0x3f3f3f3f;

struct Edge{
    int u, v, w, bef, nxt;
}edge[maxm];

int head[maxn], tot;

void push(int u, int v, int w){
    if(u==v)
        return;
    if(head[u] != -1)
        edge[head[u]].bef = tot;
    edge[tot] = { u, v, w, -1, head[u] };
    head[u] = tot++;
}

void erase(int ct){
    if(edge[ct].bef == -1)
        head[edge[ct].u] = edge[ct].nxt;
    else
        edge[edge[ct].bef].nxt = edge[ct].nxt;
    if(edge[ct].nxt != -1)
        edge[edge[ct].nxt].bef = edge[ct].bef;
}

struct qnode{
    int v, cost;
    bool operator < (const qnode &a) const{
        return cost > a.cost;
    }
};

int a, b, n, cmind, cans;
int d[maxn];
int pre[maxn];
bool book[maxn];
void init(){
    memset(head, -1, sizeof(head));
    tot = cans = 0;
    cmind = inf;
}

void dijkstra(){
    memset(d, 0x3f, sizeof(d));
    memset(pre, -1, sizeof(pre));
    memset(book, 0, sizeof(book));
    d[a] = 0;
    priority_queue<qnode> q;
    q.push({a, 0});
    while(!q.empty()){
        int u = q.top().v;
        q.pop();
        if(book[u])
            continue;
        if(u == b)
            return;
        book[u] = true;
        for(int i = head[u]; i != -1; i = edge[i].nxt){
            int v = edge[i].v;
            int w = edge[i].w;
            if(!book[v] && d[v]>d[u]+w){
                d[v] = d[u]+w;
                pre[v] = i;
                q.push({v, d[v]});
            }
        }
    }
}

bool afterdijkstra(){
    if(d[b] != inf && d[b] <= cmind){
        for(int i = pre[b]; i != -1; i = pre[edge[i].u])
            erase(i);
        cmind = d[b];
        cans++;
        return true;
    }
    return false;
}

int main(){
    int t, m;
    int cu, cv, cw;
    scanf("%d", &t);
    while(t--){
        init();
        scanf("%d%d", &n, &m);
        while(m--){
            scanf("%d%d%d", &cu, &cv, &cw);
            push(cu, cv, cw);
        }
        scanf("%d%d", &a, &b);
        do
            dijkstra();
        while(afterdijkstra());
        printf("%d\n", cans);
    }

    return 0;
}

