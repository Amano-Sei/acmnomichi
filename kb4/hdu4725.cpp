/*************************************************************************
    > File Name: hdu4725.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年10月09日 星期三 10时13分11秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

//这道题对于建图的理解有重要意义，很庆幸自己没有在ac之后就扔一边
//自己起初建图的时候，让层节点和各个节点连了双向边，不仔细思考的话是想不到错误点的
//因为这样建图后，层内节点之间距离就都是0了，即到达任意一层任意节点就代表以同样的距离到达了同层内的所有节点，从层之间传递的角度思考自然不会发觉错误。
//但是每个点的到达方式还有直接的通路，如果从直接通路到达的话，这条通路和距离是这个点独有的。
//虽然现在来看这个问题，之前没有意识到问题所在的自己是多么得蠢（
//貌似网络流中这种建图会再次出现？这里搞明白为什么不能那样建我相信一定有其意义所在

const int maxn = 100005;
const int inf = 0x3f3f3f3f;

struct Edge{
    int v, w, next;
}edge[maxn*6];

struct qnode{
    int v, cost;
    bool operator < (const qnode &a) const{
        return cost > a.cost;
    }
};

struct point{
    int v, next;
}allp[maxn];

int head[2*maxn], tail;
int n;
int lhead[maxn], ltail;

void init(){
    memset(head, -1, sizeof(head));
    memset(lhead, -1, sizeof(lhead));
    tail = ltail = 0;
}

void push(int u, int v, int w){
    edge[tail].v = v;
    edge[tail].w = w;
    edge[tail].next = head[u];
    head[u] = tail++;
}

int d[maxn*2];
bool book[maxn*2];

void dijkstra(){
    memset(d, 0x3f, sizeof(d));
    memset(book, 0, sizeof(book));
    d[1] = 0;
    priority_queue<qnode> q;
    q.push({1, 0});
    while(!q.empty()){
        int u = q.top().v;
        q.pop();
        if(book[u])
            continue;
        if(u == n)
            return;
        book[u] = true;
        for(int i = head[u]; i != -1; i = edge[i].next){
            int v = edge[i].v;
            int w = edge[i].w;
            if(!book[v] && d[v] > d[u]+w){
                d[v] = d[u]+w;
                q.push({v, d[v]});
            }
        }
    }
}

int main(){
    int t;
    int m, c, cu, cv, cw;
    scanf("%d", &t);
    for(int caset = 1; caset <= t; caset++){
        init();
        scanf("%d%d%d", &n, &m, &c);
        for(int i = 1; i <= n; i++){
            scanf("%d", &cu);
            allp[ltail] = { i, lhead[cu] };
            lhead[cu] = ltail++;
        }
        while(m--){
            scanf("%d%d%d", &cu, &cv, &cw);
            push(cu, cv, cw);
            push(cv, cu, cw);
        }
        for(int i = 1; i <= n; i++){
            for(int j = lhead[i]; j != -1; j = allp[j].next){
                push(allp[j].v, maxn+i-1, c);
                push(allp[j].v, maxn+i+1, c);
                push(maxn+i, allp[j].v, 0);
            }
        }
        dijkstra();
        printf("Case #%d: %d\n", caset, d[n]==inf?-1:d[n]);
    }
    
    return 0;
}

