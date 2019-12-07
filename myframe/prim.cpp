/*************************************************************************
    > File Name: prim.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月21日 星期四 18时34分22秒
 ************************************************************************/

#include <cstdio>
#include <cstring>

const int maxn = 1005;
const int inf = 0x3f3f3f3f;

int cost[maxn][maxn];
int lowc[maxn];
bool book[maxn];

//基于bin神模板基础版
int prim(int n){
    int ans = 0;
    memset(book, 0, sizeof(book));
    //book[0] = true;
    //这里因为0不会遍历所以没有必要
    for(int i = 1; i < n; i++)
        lowc[i] = cost[0][i];
    for(int i = 1; i < n; i++){
        register int p = -1;
        register int minc = inf;
        for(int j = 1; j < n; j++)
            if(!book[j] && minc > lowc[j]){
                p = j;
                minc = lowc[j];
            }
        if(p == -1)
            return -1;
        ans += minc;
        book[p] = true;
        for(int j = 1; j < n; j++)
            if(!book[j] && lowc[j] > cost[p][j])
                lowc[j] = cost[p][j];
    }
    return ans;
}

//因为只有一个for，所以效果类似循环展开
//基本思路是寻找新加入的点时，连接他的边可以到那个时候在更新
//相应的这样就要初始化lowc，还要保存前一个点
int primonefor(int n){
    int ans = 0;
    memset(book, 0, sizeof(book));
    memset(lowc, 0x3f, sizeof(lowc));
    for(int i = 1; i < n; i++)
        lowc[i] = cost[0][i];
    int p = 0;
    for(int i = 1; i < n; i++){
        register int tp = -1;
        register int minc = inf;
        for(int j = 1; j < n; j++)
            if(!book[j]){
                if(lowc[j] > cost[p][j])
                    lowc[j] = cost[p][j];
                if(minc > lowc[j]){
                    tp = j;
                    minc = lowc[j];
                }
            }
        if(tp == -1)
            return -1;
        ans += minc;
        book[tp] = true;
        p = tp;
    }
    return ans;
}

int lt[maxn], rt[maxn];

//双向链表版本，优点是不需要book数组和判断book，以及减少一半的迭代
//在n比较大的时候优化效果很明显，但是当n比较小时可能会负优化
int primlrt(int n){
    int ans = 0;
    rt[0] = 1;
    for(int i = 1; i < n; i++){
        lowc[i] = cost[0][i];
        lt[i] = i-1;
        rt[i] = i+1;
    }
    for(int i = 1; i < n; i++){
        register int p = -1;
        register int minc = inf;
        for(int j = rt[0]; j < n; j=rt[j])
            if(minc > lowc[j]){
                p = j;
                minc = lowc[j];
            }
        if(p == -1)
            return -1;
        lt[rt[j]] = lt[j];
        rt[lt[j]] = rt[j];
        ans += minc;
        for(int j = rt[0]; j < n; j=rt[j])
            if(lowc[j] > cost[p][j])
                lowc[j] = cost[p][j];
    }
    return ans;
}

//单向链表版本，少了一边链表，优化效果不如双向链表，空间较双向链表少一个长度n数组
//但是prim本来就是n^2的空间所以没什么必要的感觉...
int primrt(int n){
    int ans = 0;
    rt[0] = 1;
    for(int i = 1; i < n; i++){
        lowc[i] = cost[0][i];
        rt[i] = i+1;
    }
    for(int i = 1; i < n; i++){
        register int p = -1;
        register int pp = -1;
        register int minc = inf;
        for(int j = rt[0], prej = 0; j < n; prej=j, j=rt[j])
            if(minc > lowc[j]){
                p = j;
                pp = prej;
                minc = lowc[j];
            }
        if(p == -1)
            return -1;
        rt[pp] = rt[p];
        ans += minc;
        for(int j = rt[0]; j < n; j=rt[j])
            if(lowc[j] > cost[p][j])
                lowc[j] = cost[p][j];
    }
    return ans;
}

//目前我最好的双向链表结合版，事实上没有改变n^2的现实，但我现在还不知道堆优化怎么写
//注意rt[0]也要初始化
int primoneforlrt(int n){
    int ans = 0;
    memset(lowc, 0x3f, sizeof(lowc));
    rt[0] = 1;
    for(int i = 1; i < n; i++){
        lowc[i] = cost[0][i];
        lt[i] = i-1;
        rt[i] = i+1;
    }
    int p = 0;
    for(int i = 1; i < n; i++){
        register int tp = -1;
        register int minc = inf;
        for(int j = rt[0]; j < n; j=rt[j]){
            if(lowc[j] > cost[p][j])
                lowc[j] = cost[p][j];
            if(minc > lowc[j]){
                tp = j;
                minc = lowc[j];
            }
        }
        if(tp == -1)
            return -1;
        ans += minc;
        book[tp] = true;
        lt[rt[tp]] = lt[tp];
        rt[lt[tp]] = rt[tp];
        p = tp;
    }
    return ans;
}


