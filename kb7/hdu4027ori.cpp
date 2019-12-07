/*************************************************************************
    > File Name: hdu4027ori.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年12月01日 星期日 21时28分56秒
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int maxn = 100005;

struct node{
    long long val;
    int l, r;
}st[maxn<<2];

void built(int x, int l, int r){
    st[x].l = l;
    st[x].r = r;
    if(l == r){
        scanf("%lld", &st[x].val);
        return;
    }
    register int m = (l+r)>>1;
    built(x<<1, l, m);
    built((x<<1)|1, m+1, r);
    st[x].val = st[x<<1].val+st[(x<<1)|1].val;
}

void update(int x, int l, int r){
    if(st[x].r-st[x].l+1 == st[x].val)
        return;
    if(st[x].l == st[x].r){
        st[x].val = sqrt(st[x].val);
        return;
    }
    register int m = (st[x].l+st[x].r)>>1;
    if(r <= m)
        update(x<<1, l, r);
    else if(l > m)
        update((x<<1)|1, l, r);
    else
        update(x<<1, l, m), update((x<<1)|1, m+1, r);
    st[x].val = st[x<<1].val+st[(x<<1)|1].val;
}

long long query(int x, int l, int r){
    if(l <= st[x].l && st[x].r <= r)
        return st[x].val;
    register int m = (st[x].l+st[x].r)>>1;
    if(r <= m)
        return query(x<<1, l, r);
    else if(l > m)
        return query((x<<1)|1, l, r);
    else
        return query(x<<1, l, m)+query((x<<1)|1, m+1, r);
}

int main(){
    int n, m, ct, cx, cy, caset = 1;
    while(scanf("%d", &n) != EOF){
        printf("Case #%d:\n", caset++);
        built(1, 1, n);
        scanf("%d", &m);
        while(m--){
            scanf("%d%d%d", &ct, &cx, &cy);
            if(cx > cy)
                swap(cx, cy);
            if(ct == 0)
                update(1, cx, cy);
            else
                printf("%lld\n", query(1, cx, cy));
        }
        putchar('\n');
    }
    return 0;
}

