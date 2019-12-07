/*************************************************************************
    > File Name: poj3264.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月29日 星期五 17时50分40秒
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

//看到换成C++交就比G++快那么多就能大致猜到是读入是瓶颈
//再看那么多Q（

//看榜单上基本上不出意外都做了快速读写
//不过还是有300ms的存在，不知道是怎样做到的（

//或许现在的瓶颈在线段树上了
//比较意外的是我的RMQ比线段树慢...明明RMQ的合并是O(1)的
//猜想是初始化的原因
//想了想，rmq的初始化要比线段树多进行很多倍的赋值
//线段树的空间复杂度是O(n)的，最多4n个节点
//但是rmq初始化是O(nlogn)的空间复杂度和时间复杂度
//当然rmq的好处是查询时合并的复杂度是O(1)的，预处理出log数组后只需要2次查询合并即可
//线段树的复杂度是O(logn)的
//当然如果是猫树的话就会变为O(1)，但是对应的要预处理出前缀和
//可以感觉到猫树和rmq是非常接近的，所以可以想见rmq因为初始化成为瓶颈不如线段树，猫树自然不可能会比rmq快

const int maxn = 50005;
const int inf = 0x3f3f3f3f;

struct node{
    int l, r;
    int cmin, cmax;
}st[maxn<<4];

void built(int x, int l, int r){
    st[x].l = l;
    st[x].r = r;
    if(l == r){
        scanf("%d", &st[x].cmin);
        st[x].cmax = st[x].cmin;
        return;
    }
    int m = (l+r)>>1;
    built(x<<1, l, m);
    built((x<<1)|1, m+1, r);
    st[x].cmin = min(st[x<<1].cmin, st[(x<<1)|1].cmin);
    st[x].cmax = max(st[x<<1].cmax, st[(x<<1)|1].cmax);
}

void query(int x, int l, int r, int &tmin, int &tmax){
    if(l <= st[x].l && st[x].r <= r){
        tmin = min(tmin, st[x].cmin);
        tmax = max(tmax, st[x].cmax);
        return;
    }
    int m = (st[x].l+st[x].r)>>1;
    if(r <= m)
        query(x<<1, l, r, tmin, tmax);
    else if(l > m)
        query((x<<1)|1, l, r, tmin, tmax);
    else
        query(x<<1, l, m, tmin, tmax), query((x<<1)|1, m+1, r, tmin, tmax);
}

int main(){
    int n, q;
    scanf("%d%d", &n, &q);
    built(1, 1, n);
    int cl, cr, cmin, cmax;
    while(q--){
        scanf("%d%d", &cl, &cr);
        cmin = inf;
        cmax = 0;
        query(1, cl, cr, cmin, cmax);
        printf("%d\n", cmax-cmin);
    }
    return 0;
}

