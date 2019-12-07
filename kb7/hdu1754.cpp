/*************************************************************************
    > File Name: hdu1754.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月25日 星期一 19时04分59秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>

using namespace std;

//我不明白为什么有人这道题非要用树状数组...不是不能做，也不是会t
//毕竟只不过是logn^2的复杂度，更何况树状数组本来常数就比较小
//但是好别扭啊...这里是花了一天时间把树状数组又重新复习了一遍的as...
//发觉所谓的树状数组维护最大值不过是再求一遍最大值...
//感觉...这也太不优雅了...
//不过加深了线段树和树状数组的理解还是有意义的
//毕竟这些数据结构以后要蛮常用的

const int maxn = 200005;

struct node{
    int l, r;
    int val;
}segt[maxn<<2];

void built(int x, int l, int r){
    segt[x].l = l;
    segt[x].r = r;
    if(l == r){
        scanf("%d", &segt[x].val);
        return;
    }
    int m = (l+r)>>1;
    built(x<<1, l, m);
    built((x<<1)|1, m+1, r);
    segt[x].val = max(segt[x<<1].val, segt[(x<<1)|1].val);
}

void update(int x, int id, int val){
    if(segt[x].l == segt[x].r){
        segt[x].val = val;
        return;
    }
    int m = (segt[x].l+segt[x].r)>>1;
    if(id <= m)
        update(x<<1, id, val);
    else
        update((x<<1)|1, id, val);
    segt[x].val = max(segt[x<<1].val, segt[(x<<1)|1].val);
}

int query(int x, int l, int r){
    if(l <= segt[x].l && segt[x].r <= r)
        return segt[x].val;
    int m = (segt[x].l+segt[x].r)>>1;
    if(r <= m)
        return query(x<<1, l, r);
    else if(m < l)
        return query((x<<1)|1, l, r);
    else
        return max(query(x<<1, l, m), query((x<<1)|1, m+1, r));
}

int main(){
    int n, m, ca, cb;
    char cmd[16];
    while(scanf("%d%d", &n, &m) != EOF){
        built(1, 1, n);
        while(m--){
            scanf("%s%d%d", cmd, &ca, &cb);
            if(cmd[0] == 'Q')
                printf("%d\n", query(1, ca, cb));
            else
                update(1, ca, cb);
        }
    }
    return 0;
}

