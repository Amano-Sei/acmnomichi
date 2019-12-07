/*************************************************************************
    > File Name: poj2387re.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年09月17日 星期二 14时12分32秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 1005;
const int inf = 0x3f3f3f3f;

struct edge{
    int v, w;
    edge(){}
    edge(int v, int w):v(v), w(w){}
};

vector<edge> E[maxn];
int n;
int d[maxn];
bool book[maxn];

void dijkstra(int s){
    memset(d, 0x3f, sizeof(d));
    //memset(book, 0, sizeof(book));
    d[s] = 0;
    for(int i = 0; i < n; i++){
        int k = -1;
        int minw = inf;
        for(int j = 0; j < n; j++)
            if(!book[j] && d[j] < minw){
                k = j;
                minw = d[j];
            }
        if(k == -1)
            return;
        book[k] = true;
        for(int j = 0; j < E[k].size(); j++){
            int v = E[k][j].v;
            if(!book[v] && d[v] > E[k][j].w+d[k])
                d[v] = E[k][j].w+d[k];
        }
    }
}

int main(){
    int t, cu, cv, cw;
    scanf("%d%d", &t, &n);
    while(t--){
        scanf("%d%d%d", &cu, &cv, &cw);
        cu--;
        cv--;
        E[cu].push_back(edge(cv, cw));
        E[cv].push_back(edge(cu, cw));
    }
    dijkstra(n-1);
    printf("%d\n", d[0]);
	return 0;
}

