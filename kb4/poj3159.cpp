/*************************************************************************
    > File Name: poj3159.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年09月26日 星期四 11时11分07秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

//开始的时候理解成了两数之差（无序），wa了无数发，然而实际上是两数之差（有序）
//第一次见到卡queue的spfa←你见的太少了（我有思考过spfa判负环的问题，感觉cnt判负环不可靠，甚至stack实现的情况下我可以举出反例（
//在bellman_ford中，在第k轮更新后，确保了经过k条边的路径一定被加入了进来，所以，如果在第n轮中被松弛，必然是出现了一条>=n条边的存在有环的通路。
//但是事实上，每个节点并不一定只被松弛了n-1次，很容易就能想明白，源点到一个节点的路径本身就很可能不止n-1条，而我的反例也是基于这个去做的。
//在队列情况下的spfa判负环很难举出这样的反例（甚至有可能他会是正确的，但是栈的情况下就不一样了，尽量使得某一个节点在入栈后即刻出栈，然后这个节点就有可以被几乎所有可以到达他的路径进行松弛，这样的话n就很可能远远不够了，大概是一个O(n^2)
//关于spfa的判负环的思考最开始是因为看到bin巨的模板中的cnt是n而不是n-1，随后思考了一下发现没有问题那么简单，网上的dalao大多没有解释，或是给出了错误的证明

const int maxn = 30005;
const int maxm = 150005;
const int inf = 0x3f3f3f3f;

struct edge{
    int v, w;
    int next;
    edge(){}
    edge(int v, int w):v(v), w(w){}
}E[maxm];

//vector<edge> E[maxn];
int head[maxn], tot;

void addedge(int u, int v, int w){
    E[tot].next = head[u];
    E[tot].v = v;
    E[tot].w = w;
    head[u] = tot++;
}
int n;
int d[maxn];
bool book[maxn];

void spfa(int s){
    memset(d, 0x3f, sizeof(d));
    d[s] = 0;
    stack<int> q;
    q.push(s);
    book[s] = true;
    while(!q.empty()){
        int u = q.top();
        book[u] = false;
        q.pop();
        for(int i = head[u]; i != -1; i = E[i].next){
            int v = E[i].v;
            int w = E[i].w;
            if(d[u]+w < d[v]){
                d[v] = d[u]+w;
                if(!book[v]){
                    q.push(v);
                    book[v] = true;
                }
            }
        }
    }
}

int main(){
    memset(head, -1, sizeof(head));
    int m, cu, cv, cw;
    int ans = 0;
    scanf("%d%d", &n, &m);
    while(m--){
        scanf("%d%d%d", &cu, &cv, &cw);
        addedge(cu, cv, cw);
        //E[cu].push_back(edge(cv, cw));
    }
    spfa(1);
    ans = max(ans, d[n]);
    //spfa(n);
    //ans = max(ans, d[1]);
    printf("%d\n", ans);

    return 0;
}

