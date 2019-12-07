/*************************************************************************
    > File Name: hdu3416rans.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年10月25日 星期五 15时03分22秒
 ************************************************************************/

#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1005;
const int maxm = 100005;
const int inf = 0x3f3f3f3f;

//最短路里面混了道最大流...一口老血喷出，不过借这个机会成功把dinic和ek过掉了（
//虽然进度慢了好多好多...
//bin巨的dinic模板已经是相当优化的版本，现在只感觉之前不明白最短路和最大流的自己蠢爆了（
//话说这个题，一直没抓住机会吐槽，终于在自己机子上补档了（

struct Edge{
    int v, w, next;
}edge[maxm];

int head[maxn], tot;

inline void push_edge(int u, int v, int w){
    edge[tot] = { v, w, head[u] };
    head[u] = tot++;
}

struct Arc{
    int v, cap, flow, next;
}arc[maxm*2];

int archead[maxn], arctot;

inline void push_arc(int u, int v, int cap){
    arc[arctot] = { v, cap, 0, archead[u] };
    archead[u] = arctot++;
    arc[arctot] = { u, 0, 0, archead[v] };
    archead[v] = arctot++;
}

inline void init(){
    arctot = tot = 0;
    memset(head, -1, sizeof(head));
    memset(archead, -1, sizeof(archead));
}

int d[maxn];
bool book[maxn];

struct qnode{
    int v, cost;
    bool operator < (const qnode &a) const{
        return cost > a.cost;
    }
};

void dijkstra(int st, int ep){
    memset(d, 0x3f, sizeof(d));
    memset(book, 0, sizeof(book));
    d[st] = 0;
    priority_queue<qnode> q;
    q.push({ st, 0 });
    while(!q.empty()){
        int u = q.top().v;
        q.pop();
        if(book[u])
            continue;
        if(u == ep)
            return;
        book[u] = true;
        for(int i = head[u]; i != -1; i = edge[i].next){
            int v = edge[i].v;
            int w = edge[i].w;
            if(!book[v] && d[v] > d[u]+w){
                d[v] = d[u]+w;
                q.push({ v, d[v] });
            }
        }
    }
}

int dep[maxn], cur[maxn];
int que[maxn], stk[maxn];

bool bfs(int st, int ep){
    memset(dep, -1, sizeof(dep));
    dep[st] = 0;
    int front = 0, tail = 0;
    que[tail++] = st;
    while(front < tail){
        int u = que[front++];
        for(int i = archead[u]; i != -1; i = arc[i].next){
            int v = arc[i].v;
            if(dep[v] == -1 && arc[i].cap > arc[i].flow){
                dep[v] = dep[u]+1;
                if(v == ep)
                    return true;
                que[tail++] = v;
            }
        }
    }
    return false;
}

int dinic(int st, int ep){
    int maxflow = 0;
    while(bfs(st, ep)){
        memcpy(cur, archead, sizeof(cur));
        int tail = 0, u = st;
        while(cur[st] != -1){
            if(u == ep){
                int tp = inf;
                for(int i = tail-1; i >= 0; i--)
                    tp = min(tp, arc[stk[i]].cap-arc[stk[i]].flow);
                maxflow += tp;
                for(int i = tail-1; i >= 0; i--){
                    arc[stk[i]].flow += tp;
                    arc[stk[i]^1].flow -= tp;
                    if(arc[stk[i]].flow == arc[stk[i]].cap)
                        tail = i;
                }
                u = arc[stk[tail]^1].v;
                cur[u] = arc[cur[u]].next;
            }else if(cur[u] != -1 && dep[arc[cur[u]].v] == dep[u]+1 && arc[cur[u]].cap > arc[cur[u]].flow){
                stk[tail++] = cur[u];
                u = arc[cur[u]].v;
            }else{
                while(u != st && cur[u] == -1)
                    u = arc[stk[--tail]^1].v;
                cur[u] = arc[cur[u]].next;
            }
        }
    }
    return maxflow;
}

int main(){
    int t, n, m, cu, cv, cw;
    scanf("%d", &t);
    while(t--){
        init();
        scanf("%d%d", &n, &m);
        while(m--){
            scanf("%d%d%d", &cu, &cv, &cw);
            push_edge(cu, cv, cw);
        }
        scanf("%d%d", &cu, &cv);
        dijkstra(cu, cv);
        for(int i = 1; i <= n; i++)
            for(int j = head[i]; j != -1; j = edge[j].next){
                int v = edge[j].v;
                int w = edge[j].w;
                if(d[v] == d[i]+w)
                    push_arc(i, v, 1);
            }
        printf("%d\n", dinic(cu, cv));
    }
    return 0;
}

