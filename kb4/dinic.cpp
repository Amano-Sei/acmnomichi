/*************************************************************************
    > File Name: dinic.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年10月16日 星期三 14时37分04秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

const int maxn = 2010;
const int maxm = 120010;
const int inf = 0x3f3f3f3f;

struct Edge{
    int to, cap, next, flow;
}edge[maxm];
int tol;
int head[maxn];

void init(){
    tol = 2;
    memset(head, -1,  sizeof(head));
}
void addedge(int u, int v, int w, int rw = 0){
    edge[tol] = { v, w, head[u], 0 };
    head[u] = tol++;
    edge[tol] = { u, rw, head[v], 0 };
    head[v] = tol++;
}

int dep[maxn], cur[maxn], sta[maxn];
bool bfs(int s, int t, int n){
    queue<int> q;
    memset(dep, -1, sizeof(dep)*(n+1));
    dep[s] = 0;
    q.push(s);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i = head[u]; i != -1; i = edge[i].next){
            int v = edge[i].to;
            if(edge[i].cap > edge[i].flow && dep[v] == -1){
                dep[v] = dep[u]+1;
                if(v==t)
                    return true;
                q.push(v);
            }
        }
    }
    return false;
}

int dinic(int s, int t, int n){
    int maxflow = 0;
    while(bfs(s, t, n)){
        for(int i = 0; i < n; i++)
            cur[i] = head[i];
        int u = s, tail = 0;
        while(cur[s] != -1){
            if(u == t){
                int tp = inf;
                for(int i = tail-1; i >= 0;  i--)

