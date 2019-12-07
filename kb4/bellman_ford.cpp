/*************************************************************************
    > File Name: bellman_ford.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年09月18日 星期三 15时21分40秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int inf = 0x3f3f3f3f;
const int maxn = 550;
int dist[maxn];
struct edge{
    int u, v;
    int cost;
    edge(){}
    edge(int u, int v, int cost):u(u), v(v), cost(cost){}
};

vector<edge> E;

bool bellman_ford(int start, int n){
    memset(dist, 0x3f, sizeof(dist));
    dist[start] = 0;
    for(int i = 1; i < n; i++){
        bool flag = false;
        for(int j = 0; j < E.size(); j++){
            int u = E[j].u;
            int v = E[j].v;
            int cost = E[j].cost;
            if(dist[v] > dist[u]+cost){
                dist[v] = dist[u]+cost;
                flag = true;
            }
        }
        if(!flag)
            return true;
    }
    for(int j = 0; j < E.size(); j++)
        if(dist[E[j].v] > dist[E[j].u] + E[j].cost)
            return false;
    return true;
}

int main(){
	return 0;
}

