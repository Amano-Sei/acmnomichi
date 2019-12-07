/*************************************************************************
    > File Name: poj1511.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年09月25日 星期三 11时02分35秒
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

const int maxn = 1000005;
const int inf = 0x3f3f3f3f;

struct edge{
    int v, w;
    int next;
    edge(){}
    edge(int v, int w, int next):v(v), w(w), next(next){}
}E[2][maxn];

struct cmp{
    bool operator () (const pair<int, int> &a, const pair<int, int> &b){
        return a.second > b.second;
    }
};

int head[2][maxn], tot;
int n;
int d[2][maxn];
bool book[maxn];

void init(){
    memset(head, -1, sizeof(head));
    tot = 0;
    memset(d, 0x3f, sizeof(d));
}

void dijkstra(){
    for(int t = 0; t < 2; t++){
        memset(book, 0, sizeof(book));
        priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> q;
        d[t][1] = 0;
        q.push({1, 0});
        while(!q.empty()){
            int u = q.top().first;
            q.pop();
            if(book[u])
                continue;
            book[u] = true;
            for(int i = head[t][u]; i != -1; i = E[t][i].next){
                int v = E[t][i].v;
                int w = E[t][i].w;
                if(d[t][v] > d[t][u]+w){
                    d[t][v] = d[t][u]+w;
                    q.push({v, d[t][v]});
                }
            }
        }
    }
}

void push_edge(int u, int v, int w){
    E[0][tot] = edge(v, w, head[0][u]);
    head[0][u] = tot;
    E[1][tot] = edge(u, w, head[1][v]);
    head[1][v] = tot++;
}

int main(){
    int t, m;
    int cu, cv, cw;
    long long ans;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        init();
        ans = 0;
        while(m--){
            scanf("%d%d%d", &cu, &cv, &cw);
            push_edge(cu, cv, cw);
        }
        dijkstra();
        for(int i = 1; i <= n; i++)
            ans += d[0][i]+d[1][i];
        printf("%lld\n", ans);
    }
    return 0;
}

