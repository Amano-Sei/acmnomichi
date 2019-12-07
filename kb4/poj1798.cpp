/*************************************************************************
    > File Name: poj1798.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年09月17日 星期二 19时23分15秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1005;
const int inf = 1000005;

struct edge{
    int v, w;
    int next;
}E[maxn*maxn];
int tail, head[maxn];

void init(){
    tail = 0;
    memset(head, -1, sizeof(head));
}

void push(int u, int v, int w){
    E[tail].v = v;
    E[tail].w = w;
    E[tail].next = head[u];
    head[u] = tail++;
}

int d[maxn];
bool vis[maxn];
int n;

void dijkstra(int s, int e){
    memset(d, 0, sizeof(d));
    memset(vis, 0, sizeof(vis));
    d[s] = inf;
    for(int i = 0; i < n; i++){
        int k = -1;
        int maxw = 0;
        for(int j = 0; j < n; j++)
            if(!vis[j] && d[j] > maxw){
                k = j;
                maxw = d[j];
            }
        if(k == -1)
            return;
        vis[k] = true;
        if(k == e)
            return;
        for(int j = head[k]; j != -1; j = E[j].next){
            int v = E[j].v;
            int w = E[j].w;
            if(!vis[v] && d[v] < min(d[k], w))
                d[v] = min(d[k], w);
        }
    }
}

int main(){
    int t, m, cu, cv, cw;
    scanf("%d", &t);
    for(int caset = 1; caset <= t; caset++){
        init();
        scanf("%d%d", &n, &m);
        while(m--){
            scanf("%d%d%d", &cu, &cv, &cw);
            cu--;
            cv--;
            push(cu, cv, cw);
            push(cv, cu, cw);
        }
        dijkstra(0, n-1);
        printf("Scenario #%d:\n%d\n\n", caset, d[n-1]);
    }
	return 0;
}

