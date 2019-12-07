/*************************************************************************
    > File Name: 1004.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年08月23日 星期五 15时44分15秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int maxn = 5e4+1;

int fromhead[maxn], fromtail;
int tohead[maxn], totail;

struct edge{
    int u;
    int v;
    int w;
    int nxt;
    edge(){}
    edge(int u, int v, int w, int nxt):u(u), v(v), w(w), nxt(nxt){}
} toedge[maxn], fromedge[maxn];
struct ansedge{
    int u, v, w;
    ansedge(){}
    ansedge(int u, int v, int w):u(u), v(v), w(w){}
    bool operator < (const ansedge &a) const{
        return w > a.w;
    }
};

priority_queue<ansedge> waittodo;
vector<ansedge> anss;
int n, m, q;
int efresh;

void init(){
    memset(fromedge, 0, sizeof(fromedge));
    memset(fromhead, -1, sizeof(fromhead));
    memset(toedge, 0, sizeof(toedge));
    memset(tohead, -1, sizeof(tohead));
    fromtail = totail = 0;
    efresh = 0;
    anss.clear();
    while(!waittodo.empty())
        waittodo.pop();
}
void push(int u, int v, int w){
    fromedge[fromtail].u = u;
    fromedge[fromtail].v = v;
    fromedge[fromtail].w = w;
    fromedge[fromtail].nxt = fromhead[u];
    fromhead[u] = fromtail++;
    toedge[totail].u = v;
    toedge[totail].v = u;
    toedge[totail].w = w;
    toedge[totail].nxt = tohead[v];
    tohead[v] = totail++;
}
void getallans(){
    int u, v, w, csize;
    for(int i = 0; i < fromtail; i++)
        waittodo.push(ansedge(fromedge[i].u, fromedge[i].v, fromedge[i].w));
    while((csize=anss.size()) < maxn){
        do{
            anss.push_back(waittodo.top());
            waittodo.pop();
            csize++;
            if(csize >= maxn-1)
                break;
        }while(waittodo.top().w == anss[csize-1].w);
        if(csize >= maxn-1)
            break;
        while(efresh < anss.size()){
            u = anss[efresh].u;
            v = anss[efresh].v;
            w = anss[efresh].w;
            for(int i = fromhead[v]; i != -1; i = fromedge[i].nxt)
                waittodo.push(ansedge(u, fromedge[i].v, w+fromedge[i].w));
            for(int i = tohead[u]; i != -1; i = toedge[i].nxt)
                waittodo.push(ansedge(fromedge[i].v, v, w+toedge[i].w));
            efresh++;
        }
    }
}

int main(){
    int t, cu, cv, cw;
    scanf("%d", &t);
    while(t--){
        init();
        scanf("%d%d%d", &n, &m, &q);
        for(int i = 0; i < m; i++){
            scanf("%d%d%d", &cu, &cv, &cw);
            push(cu, cv, cw);
        }
        getallans();
        while(q--){
            scanf("%d", &cu);
            printf("%d\n", anss[cu-1].w);
        }
    }
	return 0;
}

