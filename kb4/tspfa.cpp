/*************************************************************************
    > File Name: spfa.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年09月18日 星期三 16时00分05秒
 ************************************************************************/

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int maxn = 10000010;
const int inf = 0x3f3f3f3f;
struct edge{
    int v, cost;
    edge(){}
    edge(int v, int cost):v(v), cost(cost){}
};

vector<edge> E[maxn];
//int n = 100000;
int rc, lc;
long long ccnt;
void init(){
    ccnt = 0;
    for(int i = 1; i <= lc*rc; i++)
        E[i].clear();
}
void addedge(int u, int v, int w){
    E[u].push_back(edge(v, w));
    E[v].push_back(edge(u, w));
}

bool vis[maxn];
int cnt[maxn];
long long dist[maxn];
int maxcnt;

bool SPFA(int start, int n){
    memset(vis, false, sizeof(vis));
    memset(dist, 0x3f, sizeof(dist));
    vis[start] = true;
    dist[start] = 0;
    queue<int> que;
    //whiel(!que.empty())
    //  que.pop();
    que.push(start);
    memset(cnt, 0, sizeof(cnt));
    cnt[start] = 1;
    while(!que.empty()){
        int u = que.front();
        que.pop();
        vis[u] = false;
        for(int i = 0; i < E[u].size(); i++){
            int v = E[u][i].v;
            if(dist[v] > dist[u]+E[u][i].cost){
                dist[v] = dist[u]+E[u][i].cost;
                if(!vis[v]){
                    vis[v] = true;
                    que.push(v);
                    if(cnt[v]+1 > maxcnt){
                        //printf("%d %d %d %d %d\n", rc, lc, n, v, maxcnt);
                        maxcnt = cnt[v]+1;
                    }
                    ++ccnt;
                    if(++cnt[v] > n)
                        return false;
                }
            }
        }
    }
    return true;
}

int main(){
    for(rc = 10, lc = 10000; rc*lc < maxn; lc *= 10){
        init();
        for(int i = 0; i < rc; i++)
            for(int j = 1; j < lc; j++)
                addedge(lc*i+j, lc*i+j+1, rand()%10000+10000);
        for(int i = 1; i <= lc; i++)
            for(int j = 0; j < rc-1; j++)
                addedge(i+j*lc, i+(j+1)*lc, rand()%10+1);
        SPFA(1, lc*rc);
        printf("%d %d %d %d %lld\n", rc, lc, lc*rc, maxcnt, ccnt);
    }
    for(rc = 100, lc = 100000; rc*lc < maxn; lc *= 10){
        init();
        for(int i = 0; i < rc; i++)
            for(int j = 1; j < lc; j++)
                addedge(lc*i+j, lc*i+j+1, rand()%10000+10000);
        for(int i = 1; i <= lc; i++)
            for(int j = 0; j < rc-1; j++)
                addedge(i+j*lc, i+(j+1)*lc, rand()%10+1);
        SPFA(1, lc*rc);
        printf("%d %d %d %d %lld\n", rc, lc, lc*rc, maxcnt, ccnt);
    }
	return 0;
}

