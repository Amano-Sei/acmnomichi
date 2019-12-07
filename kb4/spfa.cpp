/*************************************************************************
    > File Name: spfa.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年09月18日 星期三 16时00分05秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
//经历了这么久，终于看spfa了...
//原来就是bellman_ford的队列优化（
//如果自己是一开始就自己摸进acm就好了
//这样或许就不会被他们带的那么急躁了
//不过现在终于平静下来了
//虽然他们似乎已经全部放弃了（
//嘛，我还有明年最后一次机会！
//现在开始努力的话或许挺晚的，但是一定会比不努力的自己要强！

const int maxn = 1010;
const int inf = 0x3f3f3f3f;
struct edge{
    int v, cost;
    edge(){}
    edge(int v, int cost):v(v), cost(cost){}
};

vector<edge> E[maxn];
void addedge(int u, int v, int w){
    E[u].push_back(edge(v, w));
}

bool vis[maxn];
int cnt[maxn];
int dist[maxn];

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
                    if(++cnt[v] > n)
                        return false;
                }
            }
        }
    }
    return true;
}

int main(){
	return 0;
}

