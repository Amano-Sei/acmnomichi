/*************************************************************************
    > File Name: poj2387.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年09月16日 星期一 22时52分16秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 1005;
struct edge{
    int v, w;
    edge(){}
    edge(int v, int w):v(v), w(w){}
};
vector<edge> edges[maxn];
bool book[maxn];
int t, n;
int d[maxn];

void djst(){
    //memset(book, 0, sizeof(book));
    memset(d, 0x3f, sizeof(d));
    d[n] = 0;
    int cmin;
    int cu = n;
    for(int j = 0; j < n; j++){
        cmin = 0x3f3f3f3f;
        for(int i = 1; i <= n; i++)
            if(!book[i] && d[i] < cmin){
                cu = i;
                cmin = d[i];
            }
        book[cu] = true;
        for(int i = 0; i < edges[cu].size(); i++){
            int v = edges[cu][i].v;
            int w = edges[cu][i].w;
            if(d[v] > d[cu]+w)
                d[v] = d[cu]+w;
        }
    }
}

int main(){
    int u, v, w;
    scanf("%d%d", &t, &n);
    while(t--){
        scanf("%d%d%d", &u, &v, &w);
        edges[u].push_back(edge(v, w));
        edges[v].push_back(edge(u, w));
    }
    djst();
    printf("%d\n", d[1]);

	return 0;
}

