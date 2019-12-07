/*************************************************************************
    > File Name: hdu1698.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月27日 星期三 20时30分15秒
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

//以后还是优先写最小节点是一个区间的线段树了（
//毕竟这样才能说是线段树
//另外是另一种线段树本来就是我比较熟悉的那种

const int maxn = 100005;

struct node{
    int sum, l, r, lz;
}st[maxn<<2];

void built(int x, int l, int r){
    st[x] = { r-l, l, r, 0 };
    if(l+1 == r)
        return;
    int m = (l+r)>>1;
    built(x<<1, l, m);
    built((x<<1)|1, m, r);
}

inline void push_down(int x){
    if(st[x].lz){
        st[x<<1].lz = st[(x<<1)|1].lz = st[x].lz;
        st[x<<1].sum = (st[x<<1].r-st[x<<1].l)*st[x].lz;
        st[(x<<1)|1].sum = (st[(x<<1)|1].r-st[(x<<1)|1].l)*st[x].lz;
        st[x].lz = 0;
    }
}

void update(int x, int l, int r, int val){
    if(l <= st[x].l && st[x].r <= r){
        st[x].sum = (r-l)*val;
        st[x].lz = val;
        return;
    }
    push_down(x);
    int m = (st[x].l+st[x].r)>>1;
    if(r <= m)
        update(x<<1, l, r, val);
    else if(l >= m)
        update((x<<1)|1, l, r, val);
    else
        update(x<<1, l, m, val), update((x<<1)|1, m, r, val);
    st[x].sum = st[x<<1].sum+st[(x<<1)|1].sum;
}

int main(){
    int t, n, q;
    int cx, cy, cz;
    scanf("%d", &t);
    for(int caset = 1; caset <= t; caset++){
        scanf("%d%d", &n, &q);
        built(1, 1, n+1);
        while(q--){
            scanf("%d%d%d", &cx, &cy, &cz);
            update(1, cx, cy+1, cz);
        }
        printf("Case %d: The total value of the hook is %d.\n", caset, st[1].sum);
    }
    return 0;
}

