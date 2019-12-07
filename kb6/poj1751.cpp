/*************************************************************************
    > File Name: poj1751.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月22日 星期五 09时58分08秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

#define POW2(x) ({int x_ = (x); x_*=x_;})

using namespace std;

const int maxn = 755;
const int inf = 0x3f3f3f3f;

vector<short> edge[maxn];
int lowc[maxn];
int pre[maxn];
int lt[maxn], rt[maxn];
int x[maxn], y[maxn];

void prim(int n){
    for(int i = 1; i <= n; i++){
        lt[i] = i-1;
        rt[i] = i+1;
        lowc[i] = inf;
    }
    int p = 1;
    for(int i = 2; i <= n; i++){
        for(int j = 0; j < edge[p].size(); j++)
            lowc[edge[p][j]] = 0;
        register int tp = -1;
        register int minc = inf;
        for(int j = rt[1]; j <= n; j = rt[j]){
            register int td = POW2(x[p]-x[j])+POW2(y[p]-y[j]);
            if(td < lowc[j]){
                lowc[j] = td;
                pre[j] = p;
            }else
                td = lowc[j];
            if(td < minc){
                minc = td;
                tp = j;
            }
        }
        if(minc)
            printf("%d %d\n", pre[tp], tp);
        lt[rt[tp]] = lt[tp];
        rt[lt[tp]] = rt[tp];
        p = tp;
    }
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d%d", &x[i], &y[i]);
    register int m;
    scanf("%d", &m);
    while(m--){
        register int cu, cv;
        scanf("%d%d", &cu, &cv);
        edge[cu].push_back(cv);
        edge[cv].push_back(cu);
    }
    prim(n);
    return 0;
}

