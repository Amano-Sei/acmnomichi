/*************************************************************************
    > File Name: poj2349.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月21日 星期四 19时28分11秒
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

#define POW2(x) ({int _x = (x); _x*=_x;})

using namespace std;

//思考了半天，死活证明不出最小生成树的第k小边一定小于等于任意生成树的第k小边
//最后换了一个角度，从小到大依次加入边，只考虑联通块的数量，第一次让连通块变成(n-k)个的瞬间的那条边同时也是最小生成树的第k小边
//这样来想就方便多了
//任意的树，从最小边到最大边依次加入，加到第k条时也是(n-k)个连通块，如果这样的第k条比我们之前找到的mst的第k小边要小的话
//那么这条边必然出现mst的第k小边之前，同时这棵树的前(k-1)条边也在mst的第k小边之前，这样会在mst的第k小边之前变成(n-k)个连通块，这与我们寻找mst的第k小边的过程矛盾

//其实是看dalao说尽量不装大边的时候想了下kruskal过程发觉好像是这样的...
//虽然dalao的证明有问题...或者说不知所云...

//是第k小...被各路参差不齐的博客带跑了（

const int maxn = 505;

int x[maxn], y[maxn];

struct Edge{
    int u, v, w;
}edge[maxn*maxn];
int tot;

bool cmp(const Edge &a, const Edge &b){
    return a.w < b.w;
}

int pre[maxn];
int getpre(int x){
    if(pre[x] == -1)
        return x;
    return getpre(pre[x]);
}

inline int kruskal(int n, int cnt){
    //发觉自己kruskal写的有坑...
    //回头来补，这道题数据要求最少两个点，所以这个可以这么写...
    memset(pre, -1, sizeof(pre));
    sort(edge, &edge[tot], cmp);
    for(int i = 0; i < tot; i++){
        register int tu = getpre(edge[i].u);
        register int tv = getpre(edge[i].v);
        if(tu != tv){
            pre[tu] = tv;
            if(--cnt == 0)
                return edge[i].w;
        }
    }
    return -1;
}

int main(){
    int t, s, n;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &s, &n);
        tot = 0;
        for(int i = 0; i < n; i++){
            scanf("%d%d", &x[i], &y[i]);
            for(int j = 0; j < i; j++)
                edge[tot++] = { i, j, POW2(x[i]-x[j])+POW2(y[i]-y[j]) };
        }
        printf("%.2f\n", sqrt(kruskal(n, n-s)));
    }

    return 0;
}

